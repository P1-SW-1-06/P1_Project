/** @file main.c
 *  @brief
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

#include "main.h"

int main() {

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
           "\n\n\n\n");

    transport_vehicle_info *transport_data = import_vehicle_data("transport_types.txt");
    int num_of_cities = find_number_of_cities("city_information.txt");
    char **city_name = import_city_names("city_information.txt", num_of_cities);
    int **city_distance_array = import_city_distances("cities.txt",
                                                      num_of_cities,
                                                      city_name);


    int number_of_people = scan_number_of_people();
    people_data *user_data = collect_user_input(city_name, num_of_cities, number_of_people);


    temp_score **score = score_algorithm(city_distance_array, user_data, num_of_cities, number_of_people,
                                        transport_data);

    for (int i = 0; i < number_of_people; ++i) {
        printf("%s\n", user_data[i].name);
        for (int j = 0; j < num_of_cities; ++j) {
            if(score[i][j].vehicle_winner.final_score > 100)
                printf("%s Not reachable with any transport type \n", city_name[j]);
            else
                printf("%s %s %lf \n", city_name[j], score[i][j].vehicle_winner.vehicle, score[i][j].vehicle_winner.final_score);
        }
    }
    int number_of_available_cities = 0;
    shared_score *final_combined_city_score = final_output(score, num_of_cities, number_of_people, city_name, &number_of_available_cities);

    for (int i = 0; i < number_of_available_cities; ++i) {
        printf("\nCity name: %s Total score: %lf\n", final_combined_city_score[i].city_name, final_combined_city_score[i].output_score);
        for (int j = 0; j < number_of_people; ++j) {
            printf("%s using %s\n", user_data[j].name, score[j][final_combined_city_score[i].city_index].vehicle_winner.vehicle);

        }
    }

    qsort(final_combined_city_score,number_of_available_cities, sizeof(shared_score), final_score_sort_logic);

    for (int i = 0; i < number_of_available_cities; ++i) {
        printf("\nCity name: %s Total score: %lf\n", final_combined_city_score[i].city_name, final_combined_city_score[i].output_score);
        for (int j = 0; j < number_of_people; ++j) {
            printf("%s using %s\n", user_data[j].name, score[j][final_combined_city_score[i].city_index].vehicle_winner.vehicle);

        }
    }
}