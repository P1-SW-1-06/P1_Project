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
    transport_struct *transport_data = import_data();

    int nr = find_number_of_cities();
    char** city_name = create_city_name_array(nr);

    char* PoW = place_of_work(city_name, nr);

    printf("%s",PoW);

    int** city_distance_array = create_city_distance_matrix(nr, city_name);

    char* work_city = "frederikshavn";
    int* dijkstra_array = dijkstra(city_distance_array, index_city_names(work_city, city_name, nr),nr);
    printf("The distance from your workplace to\n");
    for (int i = 0; i < nr; ++i) {
        if (dijkstra_array[i] <= 95) { // mangler MAX_distance i if statement i stedet for 95
            printf("%s is %d\n",city_name[i], dijkstra_array[i]);
        }
    }
    printf("%lf", transport_data[1].cost);
}