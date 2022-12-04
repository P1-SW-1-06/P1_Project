/** @file user_input.h
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
#include "import_handler.h"

/* -- Prototypes -- */
typedef enum {
    car, bus, train, bike
} transport_types;

typedef enum {
    frederikshavn, aalborg, hjoerring, hobro, stoevring, thisted, noerresundby, broenderslev
} cities;

typedef struct {
    int include_car;
    int include_bus;
    int include_bike;
    int include_train;
} exclusions;

typedef struct {
    char name[50];
    int max_time;
    int preference_environment;
    int preference_cost;
    int preference_time;
    transport_types included_transport_types[4];
    exclusions exclusion;
    char* place_of_work;
} people_data;

typedef struct {
    char name[50];

} city_data;

/**
 *
 * @return
 */
people_data* collect_user_input(char** city_name_array, int num_cities);

/***
 * a function that takes the number of people from the user
 * @return returns the number chosen by the user
 */
int scan_number_of_people();

/***
 * a function that takes the preferences of the number of people selected
 * @param array taking in array to store the preferences in the correct structs
 * @param number_of_people taking in the number of people to facilitate how many runs through the loop to take preferrences
 */
void scan_people_preferences(people_data *array, int number_of_people);

/***
 * a function that takes in the max amount of minutes a user wants to commute one-way
 * @param array the array of person structs taken in, to allocate the max_time to the person struct
 * @param person_number taking in what number person the person has in the array
 */
int max_time(char* name);

void scan_name(people_data *array, int person_number);

/***
 * a function that facilitates users excluding different transportation types they want to use personally
 * @param name taking in the name to  personalize prints
 */
void scan_transport_exclusions(people_data *array, int person_number, char *name);

/***
 * a function that prints the checkboxes for visualization of what transport types are selected
 * @param ex_car a parameter that checks whether car has been excluded as a possible transportation mode
 * @param ex_bus a parameter that checks whether bus has been excluded as a possible transportation mode
 * @param ex_bike a parameter that checks whether bike has been excluded as a possible transportation mode
 * @param ex_train a parameter that checks whether train has been excluded as a possible transportation mode
 */
void print_transport_exclude_checkbox(char ex_car, char ex_bus, char ex_bike, char ex_train);

/***
 * a function that prints the final choices of the current user
 * @param ex_car a parameter that checks whether car has been excluded as a possible transportation mode
 * @param ex_bus a parameter that checks whether bus has been excluded as a possible transportation mode
 * @param ex_bike a parameter that checks whether bike has been excluded as a possible transportation mode
 * @param ex_train a parameter that checks whether train has been excluded as a possible transportation mode
 * @param name the name of the current user
 */
void print_transport_choices(char ex_car, char ex_bus, char ex_bike, char ex_train, char *name);

/**
 *
 * @param str
 */
void convert_to_lowercase(char *str);

/**
 *
 * @param array
 * @param person_number
 */
void commuting_preferences(people_data *array, int person_number);

/***
 * Ask the user for job location
 * @param city char pointer as a string which contains the name of the city
 * @param input ask user for loaction of job from a list
 * @return the choosen city for workplace
 */
char* place_of_work(char** city_array, int number_of_cities);

