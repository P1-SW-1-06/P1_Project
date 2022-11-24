/** @file user_input
 *  @brief Function and struct prototypes used in user_input.h.
 *
 *  This contains the prototypes for the
 *  functions and structs used in the program.
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

#include "user_input.h"

void user_input() {

    int number_of_people = scan_number_of_people();
    people_data* people_data_arr = malloc(number_of_people * sizeof(people_data));
    if (people_data_arr == NULL){
        printf("Memmory not allocated");
    }
    scan_people_preferences(people_data_arr, number_of_people);

    for (int i = 0; i < number_of_people; ++i) {

        printf("Person:%d Name:%s\n Maxtime:%d\n Pref\n Env:%d\n Cost:%d\n Time:%d\n Place of work:%s\n", i + 1,
               people_data_arr[i].name,
               people_data_arr[i].max_time,
               people_data_arr[i].preference_environment, people_data_arr[i].preference_cost,
               people_data_arr[i].preference_time, people_data_arr[i].place_of_work);

        printf(" transport types included:\n");
        if (people_data_arr[i].exclusion.include_car == 1){
            printf(" car,");
        }
        if (people_data_arr[i].exclusion.include_bus == 1){
            printf(" bus,");
        }
        if (people_data_arr[i].exclusion.include_bike == 1){
            printf(" bike,");
        }
        if (people_data_arr[i].exclusion.include_train == 1){
            printf(" train,");
        }
        printf("\n");

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
        array[i].max_time = 0;

        fflush(stdin); //Clears buffer to make sure scanf is not skipped
        printf("Please enter name of person nr. %d\n", i + 1);
        scanf("%50[^\n]",
              array[i].name); // scanf only reads the first 50 characters and disregards the rest or stops when enter is input
        printf("%s\n", array[i].name);


        array[i].place_of_work = place_of_work();
        printf("%s\n",array[i].place_of_work);

        scan_transport_exclusions(array, i, array[i].name);


        max_time(array, i);
        commuting_preferences(array, i);

    }
}

void max_time(people_data *array, int person_number) {
    while (array[person_number].max_time == 0) {
        char tempchar;
        fflush(stdin); //Clears buffer to make sure scanf is not skipped
        printf("Please enter the max amount of minutes %s want to commute followed by enter\n",
               array[person_number].name);
        if (scanf("%d%c", &array[person_number].max_time, &tempchar) != 2
            || tempchar != '\n') {
            printf("invalid input\n");
            array[person_number].max_time = 0;
        } else {
            printf("%s's max travel time is %d minutes\n", array[person_number].name, array[person_number].max_time);
        }
    }
}

void scan_transport_exclusions(people_data *array, int person_number, char *name) {
    int choice = -1;
    char ex_car = 'x', ex_bus = 'x', ex_bike = 'x', ex_train = 'x';
    array[person_number].exclusion.include_car = 1;
    array[person_number].exclusion.include_bus = 1;
    array[person_number].exclusion.include_bike = 1;
    array[person_number].exclusion.include_train = 1;

    char tempchar;
    while (choice != 0) {
        //system("cls");
        printf("%s do you want to exclude any of these transportation types?\n", name);
        print_transport_exclude_checkbox(ex_car, ex_bus, ex_bike, ex_train);
        fflush(stdin);
        printf("To remove or add press\n1 for car\n2 for bus\n3 for bike\n4 for train\nPress 0 when satisfied\n");
        if (scanf("%d%c", &choice, &tempchar) != 2
            || tempchar != '\n' || (choice > 4 && choice != 9) || choice < 0) {
            printf("invalid input\n");
        }else if (ex_car == ' ' && ex_bus == ' ' && ex_bike == ' ' && ex_train == ' '){
            printf("You must have at least 1 possible mean of transportation\n");
        }else {
            switch (choice) {
                case 0: {
                    print_transport_choices(ex_car, ex_bus, ex_bike, ex_train, name);
                    break;
                }
                case 1: {
                    if (ex_car == ' '){
                        ex_car = 'x';
                    } else if (ex_bus == ' ' && ex_bike == ' ' && ex_train == ' ') {
                        printf("You must have at least 1 possible mean of transportation\n");
                    } else {
                        ex_car = ' ';
                    } break;
                }
                case 2:{
                    if (ex_bus == ' '){
                        ex_bus = 'x';
                    } else if (ex_bike == ' ' && ex_train == ' ' && ex_car == ' ') {
                        printf("You must have at least 1 possible mean of transportation\n");
                    } else {
                        ex_bus = ' ';
                    } break;
                }
                case 3: {
                    if (ex_bike == ' '){
                        ex_bike = 'x';
                    } else if (ex_car == ' ' && ex_bus == ' ' && ex_train == ' ') {
                        printf("You must have at least 1 possible mean of transportation\n");
                    } else {
                        ex_bike = ' ';
                    } break;
                }
                case 4:{
                    if (ex_train == ' '){
                        ex_train = 'x';
                    } else if (ex_car == ' ' && ex_bus == ' ' && ex_bike == ' ') {
                        printf("You must have at least 1 possible mean of transportation\n");
                    } else {
                        ex_train = ' ';
                    } break;
                }
                default:
                    choice = -1;
            }
        }
    }
    if (ex_car == ' '){
        array[person_number].exclusion.include_car = 0;
    }
    if (ex_bus == ' '){
        array[person_number].exclusion.include_bus = 0;
    }
    if (ex_bike == ' '){
        array[person_number].exclusion.include_bike = 0;
    }
    if (ex_train == ' '){
        array[person_number].exclusion.include_train = 0;
    }
}

void print_transport_exclude_checkbox(char ex_car, char ex_bus, char ex_bike, char ex_train) {
    printf("Included transportations types indicated by x\n");
    printf("1-car[%c]  2-bus[%c]  3-bike[%c]  4-train[%c]\n", ex_car, ex_bus, ex_bike, ex_train);
    printf("\n");
}

void print_transport_choices(char ex_car, char ex_bus, char ex_bike, char ex_train, char *name) {
    printf("%s chose ", name);
    if (ex_car == 'x') { printf("car, "); }
    if (ex_bus == 'x') { printf("bus, "); }
    if (ex_bike == 'x') { printf("bike, "); }
    if (ex_train == 'x') { printf("train, "); }
    printf("as possible transportations types to use.\n");
}

void commuting_preferences(people_data *array, int person_number) {


    int co2 = 0, cost = 0, time = 0, remainder = 100;
    printf("%s please distribute 100 points in the categories environment, cost and time \n"
           "based on what is most important to you when it comes to commuting\n\n",
           array[person_number].name);
    while (remainder > 0) {
        char input[5];
        int value = 0, valid = 0;

        printf("Env \tCost \tTime \tRemaining\n");
        printf("%d \t%d \t%d \t%d\n\n", co2, cost, time, remainder);
        fflush(stdin);
        scanf("%s \t%d", input, &value);
        convert_to_lowercase(input);
        if (strcmp(input, "env") == 0 && (value <= 100 && value > 0) && ((100 - value - time - cost) >= 0)) {
            co2 = value;
            valid = 1;
        } else if (strcmp(input, "cost") == 0 && (value <= 100 && value > 0) && ((100 - value - co2 - time) >= 0)) {
            cost = value;
            valid = 1;
        } else if (strcmp(input, "time") == 0 && (value <= 100 && value > 0) && ((100 - value - co2 - cost) >= 0)) {
            time = value;
            valid = 1;
        } else
            printf("invalid input\n");

        if ((100 - co2 - cost - time) >= 0 && (value > 0) && valid == 1)
            remainder = 100 - co2 - cost - time;
        //system("cls");

        if (remainder == 0) {

            printf("You chose the following distribution:\n");
            printf("Env \tCost \tTime\n");
            printf("%d \t%d \t%d \n", co2, cost, time);
            printf("Are you happy with your choices? Y/N\n");

            while (1) {
                char tempchar;
                char choice;
                fflush(stdin);
                if (scanf("%c%c", &choice, &tempchar) != 2
                    || tempchar != '\n') {
                    printf("invalid input\n");
                }
                if (choice == 'y' || choice == 'Y')
                    break;
                if (choice == 'n' || choice == 'N') {
                    remainder = 100;
                    cost = 0;
                    co2 = 0;
                    time = 0;
                    break;
                } else
                    printf("invalid input\n");
            }
        }
    }
    array[person_number].preference_time = time;
    array[person_number].preference_cost = cost;
    array[person_number].preference_environment = co2;
}

void convert_to_lowercase(char *str) {//runs over every letter in the string and converts them to lowercase
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = tolower(str[i]);
    }
}

char* place_of_work() {
    char *city;
    int input;

    do {
        printf("Where is your job located? Press the given number\n"
               "[1]:Aalborg\n"
               "[2]:Noerresundby\n"
               "[3]:Stoevring\n"
               "[4]:Frederikshavn\n"
               "[5]:Broenderslev\n"
               "[6]:Hjoerring\n"
               "[7]:Thisted\n"
               "[8]:Hobro\n");
        scanf("%d", &input);

        switch (input) {
            case 1:
                city = "Aalborg";
                break;
            case 2:
                city = "Noerresundby";
                break;
            case 3:
                city = "Stoevring";
                break;
            case 4:
                city = "Frederikshavn";
                break;
            case 5:
                city = "Broenderslev";
                break;
            case 6:
                city = "Hjoerring";
                break;
            case 7:
                city = "Thisted";
                break;
            case 8:
                city = "Hobro";
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (input < 1 || input > 8);
    return city;
}