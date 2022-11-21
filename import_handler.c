//
// Created by Anders Overgaard Lisberg on 20/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "import_handler.h"

#define NUM_OF_TRANSPORT_TYPES 2

int file_exists(FILE *file);
void read_data(transport_struct *data, FILE *file);
void print_data(transport_struct *data);

transport_struct import_data() {
    FILE *transport_file = fopen("transport_types.txt", "r");
    if (!file_exists(transport_file)) {
        fclose(transport_file);
        exit(0);
    }

    transport_struct transport_data[NUM_OF_TRANSPORT_TYPES];

    read_data(transport_data, transport_file);

    print_data(transport_data);

    fclose(transport_file);

}

int file_exists(FILE *file) {
    if (file == NULL) {
        printf("'transport_types' could not be found. Make sure to select working directory\n");
        return 0;
    } return 1;
}

//"%[^1-9 ,]" "%[ A-Za-z^,]" "%[A-Za-z]" "%[A-Za-z^ ]" "%[1-9^,]" "%[^.]"
void read_data(transport_struct *data, FILE *file) {
    char* garbage = "";
    // * "Do not store this", [^\n] "any character except newline"
    fscanf(file, "%*[^\n]\n");
    for (int i = 0; i < NUM_OF_TRANSPORT_TYPES; ++i) {
        fscanf(file, "%[]s" "%s" "%lf" "%lf" "%lf", data->name, data->speed, data->cost, data->co2);
    }
}

void print_data(transport_struct *data) {
    for (int i = 0; i < NUM_OF_TRANSPORT_TYPES; ++i) {
        printf("----\n");
        printf("%s %lf %lf %lf\n", data->name, data->speed, data->cost, data->co2);
    }
}