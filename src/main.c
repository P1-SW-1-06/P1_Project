/** @file main.c
 * This is the main file of the program. All other functions are rooted in this file,
 * which means that either the other functions are called by main, or called by a function that
 * is called by main.
 *
 * @author P1-SW-1-06
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
*/

#include "main.h"

int main() {
    print_user_guide();
    do {
        transport_vehicle_info *transport_data = import_vehicle_data("transport_types.txt");

        char distance_information[50];
        char housing_information[50];
        choose_dataset(distance_information,housing_information);

        printf("Chose dataset: %s\n",housing_information);

        int num_of_cities = find_number_of_cities(housing_information);
        char **city_name = import_city_names(housing_information, num_of_cities);
        int **city_distance_array = import_city_distances(distance_information,
                                                          num_of_cities,
                                                          city_name);

        int number_of_people = scan_number_of_people();
        people_data *user_data = collect_user_input(city_name, num_of_cities, number_of_people);

        clock_t begin = clock();
        temp_score **score = score_algorithm(city_distance_array, user_data, num_of_cities,
                                             number_of_people, transport_data, housing_information);

        int number_of_available_cities = 0;

        shared_score *final_combined_city_score = final_output(score, num_of_cities, number_of_people,
                                                               city_name, &number_of_available_cities);

        qsort(final_combined_city_score, number_of_available_cities, sizeof(shared_score),
              final_score_sort_logic);
        if (number_of_available_cities > 0)
            print_final_score(number_of_people, number_of_available_cities, final_combined_city_score, score, user_data);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Test with %d cities and %d people\nTime spend calculating scores for %d available cities: %lfs\n\n",num_of_cities,number_of_people, number_of_available_cities,time_spent);
        printf("Do you want to run the program again? Y/N:");
    } while (confirm_choice());
}