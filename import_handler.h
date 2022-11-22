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
 *
 * @return
 */
transport_struct * import_data();

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

#endif //MAIN_C_IMPORT_HANDLER_H