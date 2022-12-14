/** @file utility.h
 * Contains prototypes used in utility.c
 *
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
*/

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
 * @return true if input is 'Y' or 'y', false if input is 'N' or 'n'.
 */
bool confirm_choice();

/**
 * Sorts the passed array shared_score array by output_score. Prints the final sorted score of cities to the user.
 * Frees memory allocated with malloc in functions collect_user_input(), score_algorithm() and final_output. *
 * @param number_of_people Number of people to display
 * @param number_of_available_cities Number of cities to display
 * @param final_combined_city_score Final city score
 * @param score Vehicle winner
 * @param user_data Uses for name of person
 */
void sort_and_print_final_score(int number_of_people, int number_of_available_cities, shared_score *final_combined_city_score,
                       temp_score **score, people_data *user_data);

/**
 * Prints a guide of how to use the program
 */
void print_user_guide();

/**
 * Handles selection of dataset for the specific city
 * @param distance .txt file with distances to nearby cities
 * @param housing .txt file with housing costs
 */
void choose_dataset(char* distance, char* housing);