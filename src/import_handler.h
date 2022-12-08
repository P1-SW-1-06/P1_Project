/** @file import_handler.h
 *  @brief Function and struct prototypes used in user_input.h.
 *
 *  This contains the prototypes for the
 *  functions and structs used in the program.
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

#pragma once

/* -- Includes -- */
#include "main.h" /* Necessary libraries are included in main.h */

/* -- Prototypes -- */
#define NUM_OF_TRANSPORT_TYPES 10



/**
 * @description A function that has a pointer to a file as input, opens the file transport_types.txt and checks if the
 * file exists, allocate space in malloc for transport_data
 * @return Returns a pointer to the input file
 */
transport_vehicle_info *import_vehicle_data(const char* vehicle_data);

/**
 * a functions that reads a file and counts the number of cities
 * @return returns the number of cities found
 */
int find_number_of_cities(const char* city_data);


/**
 * a function that reads a file and stores the names of the different cities
 * @param number_of_cities int for the number of cities in the program
 * @return 2d char array containing the names of the cities
 */
char** import_city_names(const char* city_data, int number_of_cities);

/**
 * a function that read distances between cities and calculate the missing distances
 * @param number_of_cities int for the number of cities in the program
 * @param city_name_array array with names of included cities
 * @return 2d int array of the distances between cities
 */
int** import_city_distances(const char* city_distances, int number_of_cities, char** city_name_array);
/**
 * a function that takes in a city name to give an index of that city
 * @param name name of the city being compared
 * @param city_name_array array with names of included cities
 * @param num_cities int for the number of cities in the program
 * @return the index of the inputted city
 */
unsigned int index_city_names(char* name, char** city_name_array, int num_cities);

/**
 * @description A function that checks if the file exists
 * @param file Taking in a pointer to file
 * @return Returning true if the file exists and false if it does not
 */
int file_exists(FILE *file);

/**
 * @description A function that reads a file and place the input in an array in a loop that runs until it no longer
 * receives 4 input
 * @param data Is a pointer to an array of type transport_struct
 * @param file The file where the data is drawn from
 */
void read_data(transport_vehicle_info *data, FILE *file);

/**
 * a function that wil open a file if it exists
 * @param input_file name of the file that should be read
 * @return returns pointer to a file
 */
FILE* read_file(const char* input_file);

/**
 * @description A function that prints an array as long as there is something to print
 * @param data Is a pointer to an array of type transport_struct
 */
void print_data(transport_vehicle_info *data);

int* find_housing_cost(const char *city_data, int num_cities);
