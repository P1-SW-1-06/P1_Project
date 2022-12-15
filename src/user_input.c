/** @file user_input.c
 * This file handles all communication and collection of data from the user.
 *
 * @author P1-SW-1-06
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
*/

#include "user_input.h"

people_data *collect_user_input(char **city_name_array, int num_cities, int number_of_people) {

    people_data *people_data_arr = malloc(number_of_people * sizeof(people_data));
    if (people_data_arr == NULL) {
        printf("Memory not allocated");
    }

    for (int person_count = 0; person_count < number_of_people; ++person_count) {
        scan_people_preferences(people_data_arr, person_count, num_cities, city_name_array);
    }

    return people_data_arr;
}

int scan_number_of_people() {
    int people = 0;
    printf("------------------------------------------------\n");
    printf("Please enter number of people you want to optimize for (between 1 and 10)\n");
    do {
        people = scan_int();
        if (people < 1 || people > 10)
            printf("invalid input\n");
    } while (people < 1 || people > 10);


    printf("You chose to optimize for: %d people\n", people);

    return people;
}

void scan_people_preferences(people_data *array, int person_index, int num_cities, char **city_name_array) {
    scan_name(array, person_index);
    scan_transport_exclusions(array, person_index, array[person_index].name);
    array[person_index].max_time = max_time(array[person_index].name);
    commuting_preferences(array, person_index);
    place_of_work(city_name_array, num_cities, array, person_index);
}

void scan_name(people_data *array, int person_number) {
    printf("------------------------------------------------\n");
    fflush(stdin); //Clears buffer to make sure scanf is not skipped
    printf("Please enter name of person nr. %d\n", person_number + 1);
    scanf("%50[^\n]", array[person_number].name);
    // scanf only reads the first 50 characters and disregards the rest, or stops when enter is input
}

int max_time(char *name) {

    int time = 0;
    printf("------------------------------------------------\n");
    printf("Please enter the max amount of minutes %s want to commute one way\n", name);

    do {
        time = scan_int();
    } while (time < 0 || time > 240);

    printf("%s's max travel time is %d minutes\n", name, time);
    return time;
}

void scan_transport_exclusions(people_data *array, int person_number, char *name) {
    int choice = -1;
    char ex_car = 'x', ex_bus = 'x', ex_bike = 'x';
    array[person_number].exclusion.include_car = 1;
    array[person_number].exclusion.include_bus = 1;
    array[person_number].exclusion.include_bike = 1;

    printf("------------------------------------------------\n");
    printf("%s please specify, if one of the following transportation types should be excluded:\n", name);
    printf("To remove or add press\n1 for car\n2 for bus\n3 for bike\nPress 0 when satisfied\n");
    char tempchar;
    while (choice != 0) {
        //system("cls");

        print_transport_exclude_checkbox(ex_car, ex_bus, ex_bike);
        fflush(stdin);
        if (scanf("%d%c", &choice, &tempchar) != 2
            || tempchar != '\n' || (choice > 4 && choice != 9) || choice < 0) {
            printf("invalid input\n");
        } else {
            switch (choice) {
                case 0: {
                    print_transport_choices(ex_car, ex_bus, ex_bike, name);
                    break;
                }
                case 1: {
                    if (ex_car == ' ') {
                        ex_car = 'x';
                    } else if (ex_bus == ' ' && ex_bike == ' ') {
                        printf("You must have at least one possible mean of transportation\n");
                    } else {
                        ex_car = ' ';
                    }
                    break;
                }
                case 2: {
                    if (ex_bus == ' ') {
                        ex_bus = 'x';
                    } else if (ex_bike == ' ' && ex_car == ' ') {
                        printf("You must have at least one possible mean of transportation\n");
                    } else {
                        ex_bus = ' ';
                    }
                    break;
                }
                case 3: {
                    if (ex_bike == ' ') {
                        ex_bike = 'x';
                    } else if (ex_car == ' ' && ex_bus == ' ') {
                        printf("You must have at least one possible mean of transportation\n");
                    } else {
                        ex_bike = ' ';
                    }
                    break;
                }
                default:
                    choice = -1;
            }
        }
    }
    if (ex_car == ' ') {
        array[person_number].exclusion.include_car = 0;
    }
    if (ex_bus == ' ') {
        array[person_number].exclusion.include_bus = 0;
    }
    if (ex_bike == ' ') {
        array[person_number].exclusion.include_bike = 0;
    }
}

void print_transport_exclude_checkbox(char ex_car, char ex_bus, char ex_bike) {
    printf("------------------------------------------------\n");
    printf("Included transportation types are indicated by x\n");
    printf("1-car[%c]  2-bus[%c]  3-bike[%c]\n", ex_car, ex_bus, ex_bike);
}

void print_transport_choices(char ex_car, char ex_bus, char ex_bike, char *name) {
    printf("%s chose ", name);
    if (ex_car == 'x') { printf("car, "); }
    if (ex_bus == 'x') { printf("bus, "); }
    if (ex_bike == 'x') { printf("bike, "); }
    printf("as possible transportations types to use.\n");
}

void commuting_preferences(people_data *array, int person_number) {

    int co2 = 0, cost = 0, time = 0, remainder = 100;
    printf("------------------------------------------------\n");
    printf("%s please distribute 100 points in the categories environment, cost and time \n"

           "based on what is most important to you when it comes to commuting.\n"
           "Env, is carbon footprint of transportation.\n"
           "Cost, is the general cost of transportation and housing.\n"
           "Time, is the time of commuting.\n"
           "You can only input one value at a time.\n"
           "To enter a value, type the category and the number of points you want to put in that category\n"
           "i.e 'env 40' 'cost 30' 'time 30'\n",

           array[person_number].name);
    while (remainder > 0) {
        char input[5] = "qqqq";
        int value = -1;


        printf("Env \tCost \tTime \tRemaining\n");
        printf("%d \t%d \t%d \t%d\n", co2, cost, time, remainder);
        fflush(stdin);
        int check_input = scanf("%[a-zA-Z] %d", input, &value);

        convert_to_lowercase(input);
        if (check_input != 2) {
            printf("invalid input\n");
        } else if (strcmp(input, "env") == 0 && (value <= 100 && value >= 0) && ((100 - value - time - cost) >= 0)) {
            co2 = value;
        } else if (strcmp(input, "cost") == 0 && (value <= 100 && value >= 0) && ((100 - value - co2 - time) >= 0)) {
            cost = value;
        } else if (strcmp(input, "time") == 0 && (value <= 100 && value >= 0) && ((100 - value - co2 - cost) >= 0)) {
            time = value;
        } else
            printf("invalid input\n");

        remainder = 100 - co2 - cost - time;

        if (remainder == 0) {
            printf("You choose the following distribution:\n");
            printf("Env \tCost \tTime\n");
            printf("%d \t%d \t%d \n", co2, cost, time);
            printf("Please, confirm your choice with Y/N\n");
            if (confirm_choice())
                break;
            else {
                remainder = 100;
                co2 = 0, cost = 0, time = 0;
            }
        }
    }
    array[person_number].preference_time = time;
    array[person_number].preference_cost = cost;
    array[person_number].preference_environment = co2;
}

void convert_to_lowercase(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = tolower(str[i]);
    }
}

void place_of_work(char **city_array, int number_of_cities, people_data *array, int person_index) {
    printf("------------------------------------------------\n");
    printf("Please choose the city you work in by entering its index \n");

    printf("Index\t City\n");
    for (int i = 1; i < number_of_cities + 1; ++i) {
        printf("%d\t %s\n", i, city_array[i - 1]);
    }

    int city_choice;
    do {
        city_choice = scan_int();
    } while (city_choice < 1 ||
             city_choice > number_of_cities);
    array[person_index].place_of_work_index = city_choice - 1;
    array[person_index].place_of_work = city_array[city_choice - 1];
}

void print_people_preferences(people_data *preference_data, int person_index) {
    printf("------------------------------------------------\n");
    printf("Person:%d Name:%s\n Maxtime:%d\n Pref\n Env:%d\n Cost:%d\n Time:%d\n Place of work:%s\n",
           person_index + 1,
           preference_data[person_index].name,
           preference_data[person_index].max_time,
           preference_data[person_index].preference_environment,
           preference_data[person_index].preference_cost,
           preference_data[person_index].preference_time,
           preference_data[person_index].place_of_work);

    printf(" transport types included:\n");
    if (preference_data[person_index].exclusion.include_car == 1) {
        printf(" car,");
    }
    if (preference_data[person_index].exclusion.include_bus == 1) {
        printf(" bus,");
    }
    if (preference_data[person_index].exclusion.include_bike == 1) {
        printf(" bike,");
    }
    printf("\n");
}

