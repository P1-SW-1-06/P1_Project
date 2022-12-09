#include "utility.h"

int scan_int(bool *info) {

    while (1) {
        char info_string[10];
        int choice;
        char tempchar;
        fflush(stdin);
        if (scanf("%[a-zA-Z ]%d%c", info_string, &choice, &tempchar) != 2|| tempchar != '\n')
            printf("invalid input\n");
        else {
            if (strcmp(info_string,"info") == 0){
                *info = true;
            }
            else
                *info = false;

            return choice;
        }
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
        char tempchar;
        char choice;
        fflush(stdin);
        if (scanf("%c%c", &choice, &tempchar) != 2
            || tempchar != '\n') {
            printf("invalid input\n");
        }
        if (choice == 'y' || choice == 'Y')
            return true;
        if (choice == 'n' || choice == 'N') {
            return false;
        } else
            printf("invalid input\n");
    }
}

