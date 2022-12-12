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
        if (scanf("%d%c", &choice, &tempchar) != 2 || tempchar != '\n')
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

void print_user_guide(){
    printf("User guide:\n"
           "This program is intended to be used as a guide when considering relocating.\n\n"
           "The numbers that will be outputted after the calculation "
           "are intended to be a help in deciding where to reside,\n"
           "and may therefore not be the the best overall solution for your situation.\n"
           "The output is only based on commuting preferences, and are therefore up for interpretation by the user.\n\n"
           "All inputs should be finished by pressing <enter>\n"
           "e.g if prompted to input a number then press the number followed by <enter>\n\n"
           "If prompted to input more than one value, please separate the inputs with a <space>.\n\n"
           "When inputting the data in the program please only type the values you are prompted for\n"
           "please, input only one number at a time when prompted for such e.g '4' or '24'."
           "\n");
}


void print_final_score(int number_of_people, int number_of_available_cities, shared_score *final_combined_city_score,
                       temp_score **score, people_data *user_data) {
    for (int i = 0; i < number_of_available_cities; ++i) {
        printf("Nr.%d\n%s Total score: %15.2lf\n",i, final_combined_city_score[i].city_name,
               final_combined_city_score[i].output_score);
        for (int j = 0; j < number_of_people; ++j) {
            printf("%s using %s\n", user_data[j].name,
                   score[j][final_combined_city_score[i].city_index].vehicle_winner.vehicle);
        }
    }
    for (int i = 0; i < number_of_people; ++i) {
        free(score[i]);
    }
    free(score);
    free(final_combined_city_score);
    free(user_data);
}



