#include "score_algorithm.h"

typedef struct {
    int bus;
    int car;
    int bike;
}temp_scores;
double* time_score(int* distance,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data);

double score_algorithm(people_data* final_user, int nr_city, int number_of_people){

    /*double score_array[100] = {};

    //time_1(dijkstra_array,nr, final_user_input, nr);

    //score_array[bus] = timescore_bus; */




}


double* time_score(int* distance,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data)
{
    double timescore_bus;
    double timescore_car;
    double timescore_bike;

    temp_scores *people_score_time = malloc(number_of_people * sizeof(temp_scores));
    if (people_score_time == NULL) {
        printf("Memmory not allocated");
    }
    for (int j = 0; j < number_of_people; ++j) {
        if (final_user[j].exclusion.include_bus == 1) {
            for (int i = 0; i < nr_city; ++i) {
                timescore_bus = (distance[i] / transport_data[bus].speed) / final_user[j].max_time
                                * final_user[j].preference_time;
                printf("timescore bus: %lf \n", timescore_bus);
            }
        }

        if (final_user[j].exclusion.include_car == 1) {
            for (int i = 0; i < nr_city; ++i) {
                timescore_car = (distance[i] / transport_data[car].speed) / final_user[j].max_time
                                * final_user[j].preference_time;
                printf("timescore car: %lf \n", timescore_car);
            }
        }

        if (final_user[j].exclusion.include_bike == 1) {
            for (int i = 0; i < nr_city; ++i) {
                timescore_bike = (distance[i] / transport_data[bike].speed) / final_user[j].max_time
                                 * final_user[j].preference_time;
                printf("timescore bike: %lf \n", timescore_bike);
            }
        }
    }

}


