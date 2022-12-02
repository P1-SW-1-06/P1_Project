/** @file main.c
 *  @brief
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

#include "main.h"

int main() {
    user_input();

    transport_struct *transport_data = import_vehicle_data("transport_types.txt");

    int num_of_cities = find_number_of_cities();
    char** city_name = create_city_name_array(num_of_cities);
    char* workplace = place_of_work(city_name, num_of_cities);


    int** city_distance_array = create_city_distance_matrix(num_of_cities, city_name);
    int* dijkstra_array = dijkstra(city_distance_array,
                                   index_city_names(workplace, city_name, num_of_cities),
                                   num_of_cities);

    printf("The distance from your workplace to\n");
    for (int i = 0; i < num_of_cities; ++i) {
            printf("%s is %d\n",city_name[i], dijkstra_array[i]);
    }
}