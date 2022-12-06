#include "score_algorithm.h"
#include "structs.h"


temp_score* time_score(int* distance,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data);

double score_algorithm(people_data* final_user, int nr_city, int number_of_people){

    /*double people_score_time[100] = {};

    //time_1(dijkstra_array,nr, final_user_input, nr);

    //people_score_time[bus] = timescore_bus; */




}

temp_score* time_score(int* distance,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data) {


    int user = 0;
    temp_score *people_score_time = malloc(number_of_people * sizeof(temp_score));
    if (people_score_time == NULL) {
        printf("Memmory not allocated");
    }


    for (int city = 0; city < nr_city; ++city) {
        if (final_user[user].exclusion.include_bus == 1) {
            people_score_time[city].time.score_bus = (distance[city] / transport_data[bus].speed) / final_user[user].max_time
                                               * final_user[user].preference_time;

            printf("timescore bus: %lf \n", people_score_time[city].time.score_bus);
        }


            if (final_user[user].exclusion.include_car == 1) {
                    people_score_time[city].time.score_car =
                            (distance[city] / transport_data[car].speed) / final_user[user].max_time
                                                * final_user[user].preference_time;

                    printf("timescore car: %lf \n", people_score_time[city].time.score_car);
            }

            if (final_user[user].exclusion.include_bike == 1) {
                    people_score_time[city].time.score_bike =
                            (distance[city] / transport_data[bike].speed) / final_user[user].max_time
                                                * final_user[user].preference_time;

                    printf("timescore bike: %lf \n", people_score_time[city].time.score_bike);
            }
        }

    return people_score_time;
    }
/*
double max_co2(people_data* final_user, transport_struct* transport_data){
    int user = 0;
    double result_co2 = (final_user[user].max_time / (1 / transport_data[car].speed) * transport_data[car].co2 * 189 * 2);
    return result_co2;
}
*/

temp_score* env_score(int* distance,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data) {


    temp_score *people_score_environment = malloc(number_of_people * sizeof(temp_score));
    if (people_score_environment == NULL) {
        printf("Memmory not allocated");
    }

    int user = 0;

    double max_result_co2 = (final_user[user].max_time / (1 / transport_data[car].speed)
                                                    * transport_data[car].co2 * 189 *2);


    for (int city = 0; city < nr_city; ++city) {
        if (final_user[user].exclusion.include_bus == 1) {
            people_score_environment[city].enviroment.score_bus = ((distance[city] * transport_data[bus].co2 * 189 * 2)
                                                                   / max_result_co2 *
                                                                   final_user[user].preference_environment);

            printf("enviroment score bus: %lf \n", people_score_environment[city].enviroment.score_bus);
        }
        if (final_user[user].exclusion.include_car == 1) {
            people_score_environment[city].enviroment.score_car = ((distance[city] * transport_data[car].co2 * 189 * 2)
                                                                   / max_result_co2 *
                                                                   final_user[user].preference_environment);

            printf("enviroment score car: %lf \n", people_score_environment[city].enviroment.score_car);
        }
        if (final_user[user].exclusion.include_bike == 1) {
            people_score_environment[city].enviroment.score_bike = (
                    (distance[city] * transport_data[bike].co2 * 189 * 2)
                    / max_result_co2 * final_user[user].preference_environment);

            printf("enviroment score bike: %lf \n", people_score_environment[city].enviroment.score_bike);
            printf("HEj: %lf\n", people_score_environment[2].enviroment.score_bus);
        }
    }
    return people_score_environment;
}

temp_score* transport_cost_score(int* distance,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data) {

    temp_score *people_score_transport_cost = malloc(number_of_people * sizeof(temp_score));
    if (people_score_transport_cost == NULL) {
        printf("Memmory not allocated");
    }


    int user = 0;

    double max_result_transport_cost = (final_user[user].max_time / (1 / transport_data[car].speed)
                                        * transport_data[car].cost * 189 * 2);

    for (int city = 0; city < nr_city; ++city) {
        if (final_user[user].exclusion.include_bus == 1) {
            people_score_transport_cost[city].transport_cost.score_bus = ((distance[city]
                                                                           * transport_data[bus].cost * 189 * 2) /
                                                                          max_result_transport_cost *
                                                                          final_user[user].preference_cost / 2);
            printf("transport cost score bus: %lf \n", people_score_transport_cost[city].transport_cost.score_bus);
        }
        if (final_user[user].exclusion.include_car == 1) {
            people_score_transport_cost[city].transport_cost.score_car = ((distance[city]
                                                                           * transport_data[car].cost * 189 * 2) /
                                                                          max_result_transport_cost *
                                                                          final_user[user].preference_cost / 2);
            printf("transport cost score car: %lf \n", people_score_transport_cost[city].transport_cost.score_car);
        }
        if (final_user[user].exclusion.include_bike == 1) {
            people_score_transport_cost[city].transport_cost.score_bike = ((distance[city]
                                                                            * transport_data[bike].cost * 189 * 2) /
                                                                           max_result_transport_cost *
                                                                           final_user[user].preference_cost / 2);
            printf("transport cost score bike: %lf \n", people_score_transport_cost[city].transport_cost.score_bike);
        }
    }
    return people_score_transport_cost;
}

