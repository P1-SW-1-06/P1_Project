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



    for (int i = 0; i < nr_city; ++i) {
      double timescore = (distance_array[i] / transport_data[bus].speed) / final_user[0].max_time
              * final_user[0].preference_time;
      printf("%lf \n", timescore);
    }

}


    /*for (int i = 0; i < nr_city; ++i) {
        printf("%d \n", distance_array[i]);
    }

}
     */
/*
 printf("%lf", transport_data[1].cost);

((Shortest distance / speed) / max_time) * pref_time_point
 */