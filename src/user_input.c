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

people_data *collect_user_input(char **city_name_array, int num_cities, int number_of_people) {

    people_data *people_data_arr = malloc(number_of_people * sizeof(people_data));
    if (people_data_arr == NULL) {
        printf("Memmory not allocated");
    }

    for (int i = 0; i < number_of_people; ++i) {
        scan_name(people_data_arr, i);
        scan_transport_exclusions(people_data_arr, i, people_data_arr[i].name);
        people_data_arr[i].max_time = max_time(people_data_arr[i].name);
        commuting_preferences(people_data_arr, i);
        people_data_arr[i].place_of_work = place_of_work(city_name_array, num_cities);
        people_data_arr[i].place_of_work_index = index_city_names(people_data_arr[i].place_of_work, city_name_array,
                                                                  num_cities);

    }

    for (int i = 0; i < number_of_people; ++i) {

        printf("Person:%d Name:%s\n Maxtime:%d\n Pref\n Env:%d\n Cost:%d\n Time:%d\n Place of work:%s\n", i + 1,
               people_data_arr[i].name,
               people_data_arr[i].max_time,
               people_data_arr[i].preference_environment,
               people_data_arr[i].preference_cost,
               people_data_arr[i].preference_time,
               people_data_arr[i].place_of_work);

        printf(" transport types included:\n");
        if (people_data_arr[i].exclusion.include_car == 1) {
            printf(" car,");
        }
        if (people_data_arr[i].exclusion.include_bus == 1) {
            printf(" bus,");
        }
        if (people_data_arr[i].exclusion.include_bike == 1) {
            printf(" bike,");
        }
        printf("\n");
    }

    return people_data_arr;
}

int scan_number_of_people() {
    int people = 0;

    printf("Please enter number of people you want to optimize for\n");

    do {
        if (people == 9)
            printf("put information about number of people here\n");
        printf("Enter number between 1-5\n");
        people = scan_int();
    } while (people < 1 || people > 5);

    printf("You chose to optimize for: %d people\n", people);

    return people;
}

void scan_people_preferences(people_data *array, int number_of_people) {
    for (int i = 0; i < number_of_people; ++i) {
        array[i].max_time = 0;

        fflush(stdin); //Clears buffer to make sure scanf is not skipped
        printf("Please enter name of person nr. %d\n", i + 1);
        scanf("%50[^\n]", array[i].name);
        // scanf only reads the first 50 characters and disregards the rest, or stops when enter is input
        printf("%s\n", array[i].name);

        scan_transport_exclusions(array, i, array[i].name);

        array[i].max_time = max_time(array[i].name);
    }
}

void scan_name(people_data *array, int person_number) {
    fflush(stdin); //Clears buffer to make sure scanf is not skipped
    printf("Please enter name of person nr. %d\n", person_number + 1);
    scanf("%50[^\n]", array[person_number].name);
    // scanf only reads the first 50 characters and disregards the rest, or stops when enter is input
    printf("%s\n", array[person_number].name);
}

int max_time(char *name) {

    int time = 0;
    printf("Please enter the max amount of minutes %s want to commute followed by enter\n", name);

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

    char tempchar;
    while (choice != 0) {
        //system("cls");
        printf("%s do you want to exclude any of these transportation types?\n", name);
        print_transport_exclude_checkbox(ex_car, ex_bus, ex_bike);
        fflush(stdin);
        printf("To remove or add press\n1 for car\n2 for bus\n3 for bike\nPress 0 when satisfied\n");
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
                        printf("You must have at least 1 possible mean of transportation\n");
                    } else {
                        ex_car = ' ';
                    }
                    break;
                }
                case 2: {
                    if (ex_bus == ' ') {
                        ex_bus = 'x';
                    } else if (ex_bike == ' '&& ex_car == ' ') {
                        printf("You must have at least 1 possible mean of transportation\n");
                    } else {
                        ex_bus = ' ';
                    }
                    break;
                }
                case 3: {
                    if (ex_bike == ' ') {
                        ex_bike = 'x';
                    } else if (ex_car == ' ' && ex_bus == ' ') {
                        printf("You must have at least 1 possible mean of transportation\n");
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
    printf("Included transportations types indicated by x\n");
    printf("1-car[%c]  2-bus[%c]  3-bike[%c]\n", ex_car, ex_bus, ex_bike);
    printf("\n");
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
    printf("%s please distribute 100 points in the categories environment, cost and time \n"
           "based on what is most important to you when it comes to commuting\n\n",
           array[person_number].name);
    while (remainder > 0) {
        char input[5];
        int value = 0;

        printf("Env \tCost \tTime \tRemaining\n");
        printf("%d \t%d \t%d \t%d\n\n", co2, cost, time, remainder);
        fflush(stdin);
        scanf("%s %d", input, &value);
        convert_to_lowercase(input);
        if (strcmp(input, "env") == 0 && (value <= 100 && value > 0) && ((100 - value - time - cost) >= 0)) {
            co2 = value;
        } else if (strcmp(input, "cost") == 0 && (value <= 100 && value > 0) && ((100 - value - co2 - time) >= 0)) {
            cost = value;
        } else if (strcmp(input, "time") == 0 && (value <= 100 && value > 0) && ((100 - value - co2 - cost) >= 0)) {
            time = value;
        } else
            printf("invalid input\n");

        remainder = 100 - co2 - cost - time;
        //system("cls");

        if (remainder == 0) {
            printf("You chose the following distribution:\n");
            printf("Env \tCost \tTime\n");
            printf("%d \t%d \t%d \n", co2, cost, time);
            printf("Are you happy with your choices? Y/N\n");
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

void convert_to_lowercase(char *str) {//runs over every letter in the string and converts them to lowercase
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = tolower(str[i]);
    }
}

char *place_of_work(char **city_array, int number_of_cities) {

    printf("please choose the city you work in by entering its index followed by enter\n");
    printf("Index\t City\n");
    for (int i = 1; i < number_of_cities + 1; ++i) {
        printf("%d\t %s\n", i, city_array[i - 1]);
    }

    int city_choice;

    do {
        city_choice = scan_int();
    } while (city_choice < 1 ||
             city_choice > number_of_cities);

    return city_array[city_choice - 1];
}

