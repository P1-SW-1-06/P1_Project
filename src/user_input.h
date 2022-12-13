/** @file user_input.h
 * Contains all the prototypes used in user_input.c
 *
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
*/

#pragma once

/* -- Includes -- */
#include "import_handler.h"

/* -- Prototypes -- */
/**
 * @description a function that allocates memory to an array with people data.
 * A for loop that runs number of people times that calls the function scan_people_preferences.
 * A for loop that runs number of people times that calls the function.
 * @return people_data_array of type struct
 */
people_data *collect_user_input(char **city_name_array, int num_cities, int number_of_people);

/**
 * @description a function that takes the number of people from the user
 * @return returns the number chosen by the user
 */
int scan_number_of_people();

/**
 * @description a function that takes the preferences of the number of people selected
 * @param array taking in array to store the preferences in the correct structs
 * @param number_of_people taking in the number of people to facilitate how many runs through the loop to take preferences
 */
void scan_people_preferences(people_data *array, int person_index, int num_cities, char **city_name_array);

/**
 * @description a function that takes in the max amount of minutes a user wants to commute one-way
 * @param array the array of person structs taken in, to allocate the max_time to the person struct
 * @param person_number taking in what number person the person has in the array
 */
int max_time(char *name);

/**
 * @description Scans for a name of max 50 characters and disregards the rest, or stops when enter is input
 * @param array array from people_data
 * @param person_number index of person
 */
void scan_name(people_data *array, int person_number);

/**
 * @description a function that facilitates users excluding different transportation types they want to use personally
 * @param name taking in the name to  personalize prints
 */
void scan_transport_exclusions(people_data *array, int person_number, char *name);

/**
 * @description a function that prints the checkboxes for visualization of what transport types are selected.
 * @param ex_car bool for whether car is a possible transportation. (0=excluded, 1=included)
 * @param ex_bus bool for whether bus is a possible transportation. (0=excluded, 1=included)
 * @param ex_bike bool for whether bike is a possible transportation. (0=excluded, 1=included)
 */
void print_transport_exclude_checkbox(char ex_car, char ex_bus, char ex_bike);

/**
 * @description a function that prints the final choices of the current user.
 * @param ex_car bool for whether car is a possible transportation. (0=excluded, 1=included)
 * @param ex_bus bool for whether bus is a possible transportation. (0=excluded, 1=included)
 * @param ex_bike bool for whether bike is a possible transportation. (0=excluded, 1=included)
 * @param name the name of the current user.
 */
void print_transport_choices(char ex_car, char ex_bus, char ex_bike, char *name);

/**
 * @description a function that runs over every letter in the string and converts them to lowercase.
 * @param str a string of letters.
 */
void convert_to_lowercase(char *str);

/**
 * @description a function that checks for the users preference points divided into environment, cost and time
 * with the sum of 100. The preference points is store in an array of the type struct.
 * @param array people_data an array of the type struct.
 * @param person_number index for a person in the array.
 */
void commuting_preferences(people_data *array, int person_number);

/**
 * @description ask the user for job location from a generated list from the dataset.
 * @param city_array char pointer as a string which contains the name of the city.
 * @param number_of_cities number of cities in the dataset.
 * @param array an array people_data of the type struct.
 * @param person_index the person with number "person_index" in the array
 */
void place_of_work(char **city_array, int number_of_cities, people_data *array, int person_index);

/**
 * @description prints the data of a persons preferences.
 * @param preference_data the array that holds all the data of the users preferences
 * @param person_index the person with number "person_index" in the array
 */
void print_people_preferences(people_data *preference_data, int person_index);
