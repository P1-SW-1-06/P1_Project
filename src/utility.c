#include "utility.h"

int scan_int() {

    while (1) {
        int choice;
        char tempchar;
        fflush(stdin);
        if (scanf("%d%c", &choice, &tempchar) != 2
            || tempchar != '\n')
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

