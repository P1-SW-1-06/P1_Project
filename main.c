#include "main.h"

typedef enum {
    ignore, limited_importance, important, very_important
} preference_scale;

typedef enum {
    car, bus, train, bike
} transport_types;

typedef struct {
    char name[50];
    int max_time;
    preference_scale environment;
    preference_scale cost;
    transport_types included_transport_types;
    char *place_of_work;
} people_data;

typedef struct {
    char name[50];

} city_data;
/***
 * a function that takes the number of people from the user
 * @return returns the number chosen by the user
 */
int scan_number_of_people();
/***
 * a function that takes the preferences of the number of people selected
 * @param array taking in array to store the preferences in the correct structs
 * @param number_of_people taking in the number of people to facilitate how many runs through the loop to take preferrences
 */
void scan_people_preferences(people_data *array, int number_of_people);
/***
 * a function that takes in the max amount of minutes a user wants to commute
 * @param array the array of person structs taken in, to allocate the max_time to the person struct
 * @param person_number taking in what number person the person has in the array
 */
void max_time(people_data *array, int person_number);
/***
 * a function that facilitates users excluding different transportation types they want to use personally
 * @param name taking in the name to  personalize prints
 */
void scan_transport_exclusions(char* name);
/***
 * a function that prints the checkboxes for visualization of what transport types are selected
 * @param ex_car a parameter that checks whether car has been excluded as a possible transportation mode
 * @param ex_bus a parameter that checks whether bus has been excluded as a possible transportation mode
 * @param ex_bike a parameter that checks whether bike has been excluded as a possible transportation mode
 * @param ex_train a parameter that checks whether train has been excluded as a possible transportation mode
 */
void print_transport_exclude_checkbox(char ex_car, char ex_bus, char ex_bike, char ex_train);
/***
 * a function that prints the final choices of the current user
 * @param ex_car a parameter that checks whether car has been excluded as a possible transportation mode
 * @param ex_bus a parameter that checks whether bus has been excluded as a possible transportation mode
 * @param ex_bike a parameter that checks whether bike has been excluded as a possible transportation mode
 * @param ex_train a parameter that checks whether train has been excluded as a possible transportation mode
 * @param name the name of the current user
 */
void print_transport_choices(char ex_car, char ex_bus, char ex_bike, char ex_train, char* name);


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
        printf("Please enter number of people you want to optimize for followed by enter\n");
        if (scanf("%d%c", &people, &tempchar) != 2
            || tempchar != '\n') {
            printf("invalid input\n");
            people = 0;
        } else if (people == 9) {
            printf("Put more information about number of people here\n");
            people = 0;
        } else {
            printf("You chose to optimize for: %d people\n", people);
        }
    }
    return people;
}

void scan_people_preferences(people_data *array, int number_of_people) {
    for (int i = 0; i < number_of_people; ++i) {
        char name[50]; // names can at max be 50 characters long
        array[i].max_time = 0;
        array[i].environment = -1;
        array[i].cost = -1;

        fflush(stdin); //Clears buffer to make sure scanf is not skipped
        printf("Please enter name of person nr. %d\n", i + 1);
        scanf("%50[^\n]",array[i].name); // scanf only reads the first 50 characters and disregards the rest or stops when enter is input
        printf("%s\n", array[i].name);
        /*while (array[i].max_time == 0) {

            char tempchar;

            fflush(stdin); //Clears buffer to make sure scanf is not skipped
            printf("Please enter the max amount of minutes person %d want to commute\n", i + 1);
            if (scanf("%d%c", &array[i].max_time, &tempchar) != 2
                || tempchar != '\n') {
                printf("invalid input\n");
                array[i].max_time = 0;
            } else {
                printf("Person %d max travel time is %d minutes\n", i + 1, array[i].max_time);
            }
        }*/
        scan_transport_exclusions(array[i].name);
        max_time(array, i);

        while (array[i].environment == -1) {
            char tempchar;
            fflush(stdin); //Clears buffer to make sure scanf is not skipped
            printf("On a scale of 1-3 how important is the environment for you followed by enter\n");
            if (scanf("%d%c", &array[i].environment, &tempchar) != 2
                || tempchar != '\n' || array[i].environment > 3 || array[i].environment < 1) {
                printf("invalid input\n");
                array[i].environment = -1;
            } else {
                printf("%s, env %d\n", array[i].name, array[i].environment);
            }
        }
        while (array[i].cost == -1) {
            char tempchar;
            fflush(stdin); //Clears buffer to make sure scanf is not skipped
            printf("How important is money for you followed by enter\n");
            if (scanf("%d%c", &array[i].cost, &tempchar) != 2
                || tempchar != '\n' || array[i].cost > 3 || array[i].cost < 1) {
                printf("invalid input\n");
                array[i].cost = -1;
            } else {
                printf("%s cost %d\n", array[i].name, array[i].cost);
            }
        }
    }
}

void max_time(people_data *array, int person_number){
    while (array[person_number].max_time == 0) {
        char tempchar;
        fflush(stdin); //Clears buffer to make sure scanf is not skipped
        printf("Please enter the max amount of minutes %s want to commute followed by enter\n", array[person_number].name);
        if (scanf("%d%c", &array[person_number].max_time, &tempchar) != 2
            || tempchar != '\n') {
            printf("invalid input\n");
            array[person_number].max_time = 0;
        } else {
            printf("%s's max travel time is %d minutes\n", array[person_number].name, array[person_number].max_time);
        }
    }
}

void scan_transport_exclusions(char* name){
    int choice = -1;
    char ex_car = 'x', ex_bus = 'x', ex_bike = 'x', ex_train = 'x';
    char tempchar;
    while(choice != 0) {
        //system("cls");
        printf("%s do you want to exclude any of these transportation types?\n", name);
        print_transport_exclude_checkbox(ex_car, ex_bus, ex_bike, ex_train);
        fflush(stdin);
        printf("To remove or add press\n1 for car\n2 for bus\n3 for bike\n4 for train\nPress 0 when satisfied\n");
        if (scanf("%d%c", &choice, &tempchar) != 2
            || tempchar != '\n' || (choice > 4 && choice != 9) || choice < 0) {
            printf("invalid input\n");
        }
        else {
            if (choice == 0){
                print_transport_choices(ex_car, ex_bus, ex_bike, ex_train, name);
                break;
            }
            else if (choice == 1){
                if (ex_car == 'x') {
                    ex_car = ' ';
                }
                else {
                    ex_car = 'x';
                }
            }
            else if (choice == 2){
                if (ex_bus == 'x') {
                    ex_bus = ' ';
                }
                else {
                    ex_bus = 'x';
                }
            }
            else if (choice == 3){
                if (ex_bike == 'x') {
                    ex_bike = ' ';
                }
                else {
                    ex_bike = 'x';
                }
            }
            else if (choice == 4){
                if (ex_train == 'x') {
                    ex_train = ' ';
                }
                else {
                    ex_train = 'x';
                }
            }
            print_transport_exclude_checkbox(ex_car, ex_bus, ex_bike, ex_train);
            choice = -1;
        }
    }
}
void print_transport_exclude_checkbox(char ex_car, char ex_bus, char ex_bike, char ex_train){
    printf("\nIncluded transportations types indicated by x\n");
    printf("1-car[%c]  2-bus[%c]  3-bike[%c]  4-train[%c]\n",ex_car,ex_bus,ex_bike,ex_train);
    printf("\n");
}
void print_transport_choices(char ex_car, char ex_bus, char ex_bike, char ex_train, char* name){
    printf("%s chose ",name);
    if (ex_car == 'x') { printf("car, ");}
    if (ex_bus == 'x') { printf("bus, ");}
    if (ex_bike == 'x') { printf("bike, ");}
    if (ex_train == 'x') { printf("train, ");}
    printf("as possible transportations types to use.\n");
}
