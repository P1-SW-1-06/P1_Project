/** @file main.h
 *  @brief includes childs for parenting and use in main.h.
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
 *
 *  Parenting https://stackoverflow.com/questions/48401627/confusion-with-preprocessor-directives
 */

// "#Pragma once": Current source file to be included only once in a single compilation. Thus, #pragma once serves the same purpose
// as #include guards, but with several advantages, including: less code, avoiding name clashes, and improved
// compile speed.
#pragma once
typedef enum {
    bus, car, bike
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
    char *place_of_work;
} people_data;

typedef struct {
    char name[50];

} city_data;

/* -- Includes -- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "import_handler.h"
#include "user_input.h"
#include "dijkstra.h"
#include "utility.h"
#include "score_algorithm.h"

/* -- Prototypes -- */
/**
 *
 * @return Should not return
 */
int main();