//
// Created by Anders Overgaard Lisberg on 20/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "import_handler.h"

#define NUM_OF_TRANSPORT_TYPES 20

int file_exists(FILE *file);
void read_data(transport_data *data, FILE *file);
void print_data(transport_data *data);

transport_data import_data() {
    FILE *transport_file = fopen("transport_types.txt", "r");
    if (!file_exists(transport_file)) {
        fclose(transport_file);
        exit(0);
    }

    transport_data transport_types[NUM_OF_TRANSPORT_TYPES];

    read_data(transport_types, transport_file);

    print_data(transport_types);

    fclose(transport_file);

}

int file_exists(FILE *file) {
    if (file == NULL) {
        printf("'transport_types' could not be found. Make sure to select working directory\n");
        return 0;
    } return 1;
}

//"%[^1-9 ,]" "%[ A-Za-z^,]" "%[A-Za-z]" "%[A-Za-z^ ]" "%[1-9^,]" "%[^.]"
void read_data(transport_data *data, FILE *file) {
    char* garbage = "";
    fscanf(file, "%*[^\n]\n");
    for (int i = 0; i < NUM_OF_TRANSPORT_TYPES; ++i) {
        // * "Do not store this", [^\n] "any character except newline"
        fscanf(file, "%[]s" "%s" "%lf" "%lf" "%lf", data->name, data->speed, data->cost, data->co2);
    }
}

void print_data(transport_data *data) {
    for (int i = 0; i < NUM_OF_TRANSPORT_TYPES; ++i) {
        printf("----");
        printf("%s %lf %lf %lf", data->name, data->speed, data->cost, data->co2);
        printf("----");
    }
}