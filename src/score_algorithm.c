//
// Created by Andreas Griem on 02/12/2022.
//

#include "score_algorithm.h"

/*
funktoner

time


cost transport

cost house

enviorment

 */

double* time_1(int* distance_array,int nr_city, people_data* final_user) {

    transport_struct *transport_data = import_data();

    int j = 0;

    if (final_user[j].exclusion.include_bus == 1) {
        for (int i = 0; i < nr_city; ++i) {
            double timescore = (distance_array[i] / transport_data[bus].speed) / final_user[0].max_time
                               * final_user[0].preference_time;
            printf("timescore bus: %lf \n", timescore);
        }
    }
    else {

    }

    if (final_user[j].exclusion.include_car == 1) {
        for (int i = 0; i < nr_city; ++i) {
            double timescore = (distance_array[i] / transport_data[car].speed) / final_user[0].max_time
                               * final_user[0].preference_time;
            printf("timescore car: %lf \n", timescore);
        }
    }
    else {

    }

    if (final_user[j].exclusion.include_bike == 1) {
        for (int i = 0; i < nr_city; ++i) {
            double timescore = (distance_array[i] / transport_data[bike].speed) / final_user[0].max_time
                               * final_user[0].preference_time;
            printf("timescore bike: %lf \n", timescore);
        }
    }
    else {

    }
}

