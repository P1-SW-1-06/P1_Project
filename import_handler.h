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
 * @description A function that has a pointer to a file as input, opens the file transport_types.txt and checks if the file exists, allocate space in malloc for transport_data
 * @return Returns a pointer to the input file
 */
transport_struct *import_data();

/**
 * @description A function that checks if the file exists
 * @param file Taking in a pointer to file
 * @return Returning true if the file exists and false if it does not
 */
int file_exists(FILE *file);

/**
 * @description A function that reads a file and place the input in an array in a loop that runs until it no longer receives 4 input
 * @param data Is an array where the data is stored
 * @param file The file where the data is drawn from
 */
void read_data(transport_struct *data, FILE *file);

/**
 * @description A function that prints an array as long as there is something to print
 * @param data Is an array where the data is stored
 */
void print_data(transport_struct *data);

#endif //MAIN_C_IMPORT_HANDLER_H