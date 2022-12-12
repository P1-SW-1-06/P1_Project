/** @file main.c
 *  @brief
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

#include "main.h"

int main() {

    transport_vehicle_info *transport_data = import_vehicle_data("transport_types.txt");
    int num_of_cities = find_number_of_cities("city_information.txt");
    char **city_name = import_city_names("city_information.txt", num_of_cities);
    int **city_distance_array = import_city_distances("cities.txt",
                                                      num_of_cities,
                                                      city_name);

    int number_of_people = scan_number_of_people();
    people_data *user_data = collect_user_input(city_name, num_of_cities, number_of_people);


    temp_score **score = score_algorithm(city_distance_array, user_data, num_of_cities,
                                         number_of_people, transport_data);

    int number_of_available_cities = 0;

    shared_score *final_combined_city_score = final_output(score, num_of_cities, number_of_people,
                                                           city_name,&number_of_available_cities);

    qsort(final_combined_city_score, number_of_available_cities, sizeof(shared_score),
          final_score_sort_logic);

    print_final_score(number_of_people, number_of_available_cities, final_combined_city_score, score, user_data);
}