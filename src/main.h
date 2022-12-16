/** @file main.h
 * Includes all functionality from other files. Doesn't include structs.h.
 *
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
 */

#pragma once
/* -- Includes -- */
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "import_handler.h"
#include "user_input.h"
#include "distance_calculation.h"
#include "utility.h"
#include "score_algorithm.h"

/* -- Prototypes -- */
/**
 * Has to be called for the program to execute.
 * @return Should not return.
 */
int main();