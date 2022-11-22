//
// Created by Anders Overgaard Lisberg on 20/11/2022.
//

#ifndef MAIN_C_IMPORT_HANDLER_H
#define MAIN_C_IMPORT_HANDLER_H



typedef struct {
    char name[20];
    double co2;
    double cost;
    double speed;
    int num_of_vehicle;
} transport_struct;

/**
 * A function that has a pointer to a file as input.
 * A function that open the file transport_types.txt and checks if the file exists.
 * A function that allocate space in malloc for transport_data
 * @return Returns transport_data, the data from the input file
 */
transport_struct *import_data();

/**
 *
 * @param file
 * @return
 */
int file_exists(FILE *file);

/**
 *
 * @param data
 */
void print_data(transport_struct *data);

/**
 *
 * @param data
 * @param file
 */
void read_data(transport_struct *data, FILE *file)

#endif //MAIN_C_IMPORT_HANDLER_H