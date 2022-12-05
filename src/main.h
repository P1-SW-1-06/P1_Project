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

/* -- Includes -- */
#include "structs.h"
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