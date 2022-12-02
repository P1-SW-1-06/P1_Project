/** @file main.c
 *  @brief
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

#include "main.h"

int main() {
    transport_struct *transport_data = import_vehicle_data("transport_types.txt");
    int num_of_cities = find_number_of_cities("city_information.txt");
    char** city_name = import_city_names("city_information.txt" ,num_of_cities);
    int** city_distance_array = import_city_distances("cities.txt",num_of_cities, city_name);



    people_data* user_data = user_input(city_name,num_of_cities);



    int* distance_from_workplace = dijkstra(city_distance_array,
                                            index_city_names(user_data[0].place_of_work,city_name,num_of_cities),
                                   num_of_cities);

    printf("The distance from your workplace to\n");
    for (int i = 0; i < num_of_cities; ++i) {
            printf("%s is %d\n",city_name[i], distance_from_workplace[i]);
    }
}