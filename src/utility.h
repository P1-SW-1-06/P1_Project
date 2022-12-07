#pragma once

#include "main.h"

/**
 *
 * Keeps running loop until user inputs a single integer and presses enter
 * @return return a single int
 */
int scan_int();

/**
 *
 * Keeps running loop until user inputs a single char and presses enter
 * @return return a single char
 */
char scan_char();

/**
 *
 * @return true if input is Y or y, false if input is N or n.
 */
bool confirm_choice();