#pragma once

#include "main.h"

/**
 * @description a function that keeps running loop until user inputs a single integer and presses enter.
 * @return return a single int.
 */
int scan_int();

/**
 * @description a function that keeps running loop until user inputs a single char and presses enter.
 * @return return a single char.
 */
char scan_char();

/**
 * @return true if input is Y or y, false if input is N or n.
 */
bool confirm_choice();

/**
 * Prints the final sorted score of cities to the user. Frees memory allocated with malloc in functions
 * collect_user_input(), score_algorithm() and final_output. *
 * @param number_of_people
 * @param number_of_available_cities
 * @param final_combined_city_score
 * @param score
 * @param user_data
 */
void print_final_score(int number_of_people, int number_of_available_cities, shared_score *final_combined_city_score,
                       temp_score **score, people_data *user_data);

/**
 * Prints a guide of how to use the program
 */
void print_user_guide();