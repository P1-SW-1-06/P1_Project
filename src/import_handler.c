/** @file import_handler.c
 *  @brief Imports information from transport_types.txt
 *
 *  Handles imports of data from transport_types.txt.
 *  It will error and exit if FILE if not found.
 *  Remember to free memory allocated by malloc.
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

/* -- Includes -- */
#include "import_handler.h"
FILE* read_file(const char* input_file);

transport_struct *import_vehicle_data(const char* transport_types) {
    FILE *transport_file = read_file(transport_types);

    transport_struct *transport_data;
    transport_data = malloc(NUM_OF_TRANSPORT_TYPES * sizeof(transport_struct));

    read_data(transport_data, transport_file);

    fclose(transport_file);

    return transport_data;
}

int file_exists(FILE *file) {
    if (file == NULL) {
        printf("'transport_types' could not be found. Make sure to select working directory\n");
        return 0;
    } return 1;
}

void read_data(transport_struct *data, FILE *file) {
    // * "Do not store this", [^\n] "any character except newline"
    fscanf(file, "%*[^\n]\n");
    data[0].num_of_vehicle = 0;
    int i = 0;
    while (fscanf(file, "%s" "%lf" "%lf" "%lf", data[i].name, &data[i].speed, &data[i].cost, &data[i].co2) == 4) {
        i++;
        data[0].num_of_vehicle += 1;
    }
}

void print_data(transport_struct *data) {
    int i = 0;
    while (i < data[0].num_of_vehicle) {
        printf("----\n");
        printf("'%s' '%lf' '%lf' '%lf'\n", data[i].name, data[i].speed, data[i].cost, data[i].co2);
        ++i;
    }
}



FILE* read_file(const char* input_file) {
    FILE* temp_file = fopen(input_file, "r");
        if (!file_exists(temp_file)) {
            fclose(temp_file);
            exit(0);
        }
        return temp_file;
}