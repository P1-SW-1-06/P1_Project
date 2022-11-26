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


int verify_scanned_input(char mode) {

    switch (mode) {
        case 'c': {
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
        case 'i': {
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
        case 's': {
            return -1;
        }
        default:
            printf("mode unknown");
            exit(0);
    }
}