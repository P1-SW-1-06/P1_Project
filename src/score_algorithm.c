#include "score_algorithm.h"
#include "structs.h"


temp_score *score_algorithm(int** distance_array, people_data *final_user, int nr_city, int number_of_people,
                            transport_struct *transport_data) {
    temp_score *score_array = malloc(nr_city * sizeof(temp_score));
    int* distance = dijkstra(distance_array,final_user[0].place_of_work_index,nr_city);
    if (score_array == NULL) {
        printf("Memory not allocated");
    }
    int* array_housing_cost = find_housing_cost("city_information.txt", nr_city);
    double yearly_max_housing_cost = max_housing_price(array_housing_cost, nr_city);
    double max_transport_cost = max_result_transport_cost(transport_data, final_user);

    for (int i = 0; i < nr_city; ++i) {
        time_score(score_array, distance, final_user, transport_data, i);
        env_score(score_array, distance, final_user, transport_data, i);
        transport_cost_score(score_array, distance, final_user, transport_data, i);
        housing_cost_score(score_array, final_user,yearly_max_housing_cost, array_housing_cost[i], i);
        sum_of_cost_scores(score_array, final_user, i, max_transport_cost, yearly_max_housing_cost);
    }

    return score_array;
    //void housing_cost_score(temp_score* scorearray, people_data *final_user, int number_of_people, int city)//
}

/* double final_combined_score(temp_score *score_array,){
     for (int i = 0; i < nr_city; ++i) {
         score[i].time.score_bus + score[i].transport_cost.score_bus + score[i].enviroment.score_bus + score[i].housing_cost);
 */

double max_housing_price(int* array_housing_cost,int nr_city){
    int max_square_meter_price = 0;
    for (int i = 0; i < nr_city; ++i) {
        if (array_housing_cost[i] > max_square_meter_price)
            max_square_meter_price = array_housing_cost[i];
    }
    return max_square_meter_price*136.5/2/15;
}

void
time_score(temp_score *scorearray, int *distance, people_data *final_user, transport_struct *transport_data, int city) {
    if (final_user[0].exclusion.include_bus == 1) {
        scorearray[city].time.score_bus =
                (distance[city] / transport_data[bus].speed) / final_user[0].max_time * final_user[0].preference_time;
    }
    if (final_user[0].exclusion.include_car == 1) {
        scorearray[city].time.score_car =
                (distance[city] / transport_data[car].speed) / final_user[0].max_time * final_user[0].preference_time;
    }
    if (final_user[0].exclusion.include_bike == 1) {
        scorearray[city].time.score_bike =
                (distance[city] / transport_data[bike].speed) / final_user[0].max_time * final_user[0].preference_time;
    }
}

void
env_score(temp_score *scorearray, int *distance, people_data *final_user, transport_struct *transport_data, int city) {

    double max_result_co2 = (final_user[0].max_time / (1 / transport_data[car].speed) * transport_data[car].co2 * 189 *
                             2);
    if (final_user[0].exclusion.include_bus == 1) {
        scorearray[city].enviroment.score_bus = (distance[city] * transport_data[bus].co2 * 189 * 2) / max_result_co2 *
                                                final_user[0].preference_environment;
    }
    if (final_user[0].exclusion.include_car == 1) {
        scorearray[city].enviroment.score_car = (distance[city] * transport_data[car].co2 * 189 * 2) / max_result_co2 *
                                                final_user[0].preference_environment;
    }
    if (final_user[0].exclusion.include_bike == 1) {
        scorearray[city].enviroment.score_bike =
                (distance[city] * transport_data[bike].co2 * 189 * 2) / max_result_co2 *
                final_user[0].preference_environment;
    }


}

void
transport_cost_score(temp_score *scorearray, int *distance, people_data *final_user, transport_struct *transport_data,
                     int city) {
    //if (final_user[user].exclusion.include_bus == 1)
    scorearray[city].transport_cost.score_bus = distance[city] * transport_data[bus].cost * 189 * 2;
    scorearray[city].transport_cost.score_car = distance[city] * transport_data[car].cost * 189 * 2;
    scorearray[city].transport_cost.score_bike = distance[city] * transport_data[bike].cost * 189 * 2;

}

double max_result_transport_cost(transport_struct *transport_data, people_data *final_user) {

    return (final_user[0].max_time / (1 / transport_data[car].speed) * transport_data[car].cost * 189 * 2);
}

void housing_cost_score(temp_score* scorearray, people_data *final_user, double yearly_max_housing_cost, int current_city, int city){

    scorearray[city].housing_cost = (current_city * 136.5 /2/15);
}

void sum_of_cost_scores(temp_score *scorearray, people_data *final_user, int city, double max_result_transport_cost,double yearly_max_housing_cost){

    if (final_user[0].exclusion.include_bus == 1) {
        scorearray[city].final_cost.score_bus =
                (scorearray[city].housing_cost + scorearray[city].transport_cost.score_bus) /
                (max_result_transport_cost + yearly_max_housing_cost) * final_user[0].preference_cost;
    }
    if (final_user[0].exclusion.include_car == 1) {
        scorearray[city].final_cost.score_car =
                (scorearray[city].housing_cost + scorearray[city].transport_cost.score_car) /
                (max_result_transport_cost + yearly_max_housing_cost) * final_user[0].preference_cost;
    }
    if (final_user[0].exclusion.include_bike == 1) {
        scorearray[city].final_cost.score_bike =
                (scorearray[city].housing_cost + scorearray[city].transport_cost.score_bike) /
                (max_result_transport_cost + yearly_max_housing_cost) * final_user[0].preference_cost;
    }
}








