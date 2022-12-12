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

void print_final_score(int number_of_people, int number_of_available_cities, shared_score *final_combined_city_score,
                       temp_score **score, people_data *user_data);
void print_user_guide();