/** @file utility.c
 *  @brief
 *
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

#include "utility.h"

int scan_int() {

    while (1) {
        int choice;
        char tempchar;
        fflush(stdin);
        if (scanf("%d%c", &choice, &tempchar) != 2|| tempchar != '\n')
            printf("invalid input\n");
        else
            return choice;
    }
}

char scan_char() {
    while (1) {
        char choice;
        char tempchar;
        fflush(stdin);
        if (scanf("%c%c", &choice, &tempchar) != 2
            || tempchar != '\n')
            printf("invalid input\n");
        else
            return choice;
    }
}

bool confirm_choice() {
    while (1) {
        char choice = scan_char();

        if (choice == 'y' || choice == 'Y')
            return true;
        if (choice == 'n' || choice == 'N') {
            return false;
        } else
            printf("invalid input\n");
    }
}

