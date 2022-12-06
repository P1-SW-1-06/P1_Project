#include "score_algorithm.h"
#include "structs.h"



temp_score* score_algorithm(int* distance, people_data* final_user, int nr_city, int number_of_people,transport_struct* transport_data){
    temp_score *score_array = malloc(nr_city * sizeof(temp_score));
    if (score_array == NULL) {
        printf("Memory not allocated");
    }


    for (int i = 0; i < nr_city; ++i) {
        time_score(score_array, distance,final_user,transport_data,i);
        env_score(score_array, distance, final_user, transport_data, i);
        transport_cost_score(score_array, distance, final_user, transport_data, i);
    }
    return score_array;

}

void time_score(temp_score *scorearray, int* distance, people_data* final_user, transport_struct* transport_data, int city) {
    scorearray[city].time.score_bus = (distance[city]/transport_data[bus].speed) / final_user[0].max_time * final_user[0].preference_time;
    scorearray[city].time.score_car = (distance[city]/transport_data[car].speed) / final_user[0].max_time * final_user[0].preference_time;
    scorearray[city].time.score_bike = (distance[city]/transport_data[bike].speed) / final_user[0].max_time * final_user[0].preference_time;
    }

void env_score(temp_score *scorearray ,int* distance, people_data* final_user, transport_struct* transport_data, int city) {

    double max_result_co2 = (final_user[0].max_time / (1 / transport_data[car].speed) * transport_data[car].co2 * 189 *2);
    scorearray[city].enviroment.score_bus = (distance[city]*transport_data[bus].co2*189*2) / max_result_co2 * final_user[0].preference_environment;
    scorearray[city].enviroment.score_car = (distance[city]*transport_data[car].co2*189*2) / max_result_co2 * final_user[0].preference_environment;
    scorearray[city].enviroment.score_bike = (distance[city]*transport_data[bike].co2*189*2) / max_result_co2 * final_user[0].preference_environment;


}

void transport_cost_score(temp_score *scorearray, int* distance, people_data* final_user, transport_struct* transport_data, int city) {

    double max_result_transport_cost = (final_user[0].max_time / (1 / transport_data[car].speed)
                                        * transport_data[car].cost * 189 * 2);
    scorearray[city].transport_cost.score_bus = ((distance[city] * transport_data[bus].cost * 189 * 2) / max_result_transport_cost * final_user[0].preference_cost / 2);
    scorearray[city].transport_cost.score_car = ((distance[city] * transport_data[car].cost * 189 * 2) / max_result_transport_cost * final_user[0].preference_cost / 2);
    scorearray[city].transport_cost.score_bike = ((distance[city] * transport_data[bike].cost * 189 * 2) / max_result_transport_cost * final_user[0].preference_cost / 2);

}

