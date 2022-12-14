/** @file import_handler.h
 * Contains prototypes used in import_handler.c.
 *
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
*/

#pragma once
/* -- Includes -- */
#include "main.h"

/* -- Prototypes -- */
#define NUM_OF_TRANSPORT_TYPES 10

/**
 * @description The function uses stdlib.h to open the file, checks if the file is found,
 * and allocates memory in malloc for the data.
 * Further, it scans the file for 4 inputs with the following type: "%s" "%lf" "%lf" "%lf".
 * Stops when there are no longer 4 inputs. Closes the file. Does not free memory.
 * @param vehicle_data pointer to the corresponding .txt file.
 * @return A pointer to the array of the  struct types transport_vehicle_info.
 */
transport_vehicle_info *import_vehicle_data(const char *vehicle_data);

/**
 * @description a functions that reads the file city_information.txt and counts the number of cities.
 * @param city_data the file there is read.
 * @return returns the number of cities found.
 */
int find_number_of_cities(const char *city_data);

/**
 * @description a function that reads the file city_information.txt stores the names of the different cities.
 * @param city_data the file there is read.
 * @param number_of_cities int for the number of cities in the program.
 * @return two dimensional char array containing the names of the cities.
 */
char **import_city_names(const char *city_data, int number_of_cities);

/**
 * @description a function that read distances between cities by reading the file cities.txt
 * and calculate the shortest path between each city. This assumes you can travel both ways between the cities.
 * @param city_distances a const char pointer.
 * @param number_of_cities int for the number of cities in the dataset.
 * @param city_name_array array with names of included cities.
 * @return two dimensional int array of the type struct.
 */
int **import_city_distances(const char *city_distances, int number_of_cities, char **city_name_array);

/**
 * @description a function that takes in a city name to give an index of that city.
 * @param name name of the city being compared.
 * @param city_name_array array with names of included cities.
 * @param num_cities the number of cities in the dataset.
 * @return the index of the inputted city.
 */
unsigned int index_city_names(char *name, char **city_name_array, int num_cities);

/**
 * @description a function that checks if the file exists.
 * @param file Taking in a pointer to file.
 * @return Returning true if the file exists and false if it does not.
 */
int file_exists(FILE *file);

/**
 * @description a function that will open a file in read mode if it exists.
 * @param input_file name of the file that should be read.
 * @return returns pointer to a file.
 */
FILE *read_file(const char *input_file);

/**
 * @desription a function that opens city_information.txt and scans the text.
 * Only takes integers from the txt file and store the data.
 * @param city_data the file there is read.
 * @param num_cities number of cities in the dataset.
 * @return array of square_meter_prices .
 */
int *find_housing_cost(const char *city_data, int num_cities);
