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

void free_2D_char_array(char **array, unsigned int array_length) {
    for (int i = 0; i < array_length; ++i) {
        free(array[i]);
    }
    free(array);
}

void free_2D_int_array(int **array, unsigned int array_length) {
    for (int i = 0; i < array_length; ++i) {
        free(array[i]);
    }
    free(array);
}

void print_final_score(int number_of_people, int number_of_available_cities, shared_score *final_combined_city_score,
                       temp_score **score, people_data *user_data) {
    for (int i = 0; i < number_of_available_cities; ++i) {
        printf("\nCity name: %s Total score: %lf\n", final_combined_city_score[i].city_name,
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

