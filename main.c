#include <stdio.h>
#include <string.h>

typedef enum preference_scale {
    ignore, limited_importance, important, very_important
} preference_scale;

typedef struct {
    char name[50];
    int max_time;
    preference_scale environment;
    preference_scale cost;
} people_data;

int scan_number_of_people();

void scan_people_preferences(people_data *array, int number_of_people);

int main() {

    int number_of_people = scan_number_of_people();
    people_data people_data_arr[number_of_people];

    scan_people_preferences(people_data_arr, number_of_people);

    for (int i = 0; i < number_of_people; ++i) {
        printf("%s %d %d %d\n", people_data_arr[i].name, people_data_arr[i].max_time,
               people_data_arr[i].environment, people_data_arr[i].cost);
    }
}


int scan_number_of_people() {
    int people = 0;
    while (people == 0) {

        char tempchar;

        fflush(stdin); //Clears buffer to make sure scanf is not skipped
        printf("Please enter number of people you want to optimize for\n");
        if (scanf("%d%c", &people, &tempchar) != 2
            || tempchar != '\n') {
            printf("invalid input\n");
            people = 0;
        } else {
            printf("You chose to optimize for: %d people\n", people);
        }
    }
    return people;
}

void scan_people_preferences(people_data *array, int number_of_people) {
    for (int i = 0; i < number_of_people; ++i) {
        char *name;
        array[i].max_time = 0;
        array[i].environment = -1;
        array[i].cost = -1;


        fflush(stdin); //Clears buffer to make sure scanf is not skipped
        printf("Please enter name of person nr. %d\n", i + 1);
        scanf("%s", array[i].name);
        printf("%s\n", array[i].name);

        while (array[i].max_time == 0) {

            char tempchar;

            fflush(stdin); //Clears buffer to make sure scanf is not skipped
            printf("Please enter the max amount minutes person %d want to commute\n", i + 1);
            if (scanf("%d%c", &array[i].max_time, &tempchar) != 2
                || tempchar != '\n') {
                printf("invalid input\n");
                array[i].max_time = 0;
            } else {
                printf("Person %d max travel time is %d minutes\n", i + 1, array[i].max_time);
            }
        }
        while (array[i].environment == -1) {

            char tempchar;

            fflush(stdin); //Clears buffer to make sure scanf is not skipped
            printf("On a scale of 1-3 how important is the environment for you\n", i + 1);
            if (scanf("%d%c", &array[i].environment, &tempchar) != 2
                || tempchar != '\n' || array[i].environment > 3 || array[i].environment < 1) {
                printf("invalid input\n");
                array[i].environment = -1;
            } else {
                printf("Person %d, env %d\n", i + 1, array[i].environment);
            }
        }
        while (array[i].cost == -1) {

            char tempchar;

            fflush(stdin); //Clears buffer to make sure scanf is not skipped
            printf("How important is money for you\n", i + 1);
            if (scanf("%d%c", &array[i].cost, &tempchar) != 2
                || tempchar != '\n' || array[i].cost > 3 || array[i].cost < 1) {
                printf("invalid input\n");
                array[i].cost = -1;
            } else {
                printf("Person %d cost %d\n", i + 1, array[i].cost);
            }
        }
    }
}
