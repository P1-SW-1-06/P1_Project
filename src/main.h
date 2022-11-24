/** @file main.h
 *  @brief Function prototypes for the user inputs.
 *
 *  This contains the prototypes for the
 *  driver and eventually any macros, constants,
 *  or global variables you will need.
 *
 *  @author Harry Q. Bovik (hqbovik)
 *  @author Fred Hacker (fhacker)
 *  @bug No known bugs.
 *
 *  Parenting https://stackoverflow.com/questions/48401627/confusion-with-preprocessor-directives
 */
// current source file to be included only once in a single compilation. Thus, #pragma once serves the same purpose
// as #include guards, but with several advantages, including: less code, avoiding name clashes, and improved
// compile speed.
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "import_handler.h"
#include "user_input.h"