/** @file main.c
 *  @brief
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

#include "main.h"

int main() {
    user_input();
    transport_struct *transport_data = import_data();

    printf("%lf", transport_data[1].cost);
}