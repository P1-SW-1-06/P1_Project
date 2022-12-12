#include "score_algorithm.h"
#include "structs.h"


temp_score **score_algorithm(int **distance_array, people_data *final_user, int nr_of_cities, int number_of_people,
                             transport_vehicle_info *transport_data) {
    temp_score **score_array;
    score_array = malloc(number_of_people * (sizeof(temp_score *)));
    if (score_array == NULL) {
        printf("Memory not allocated");
    }
    int *array_housing_cost = find_housing_cost("city_information.txt", nr_of_cities);
    double yearly_max_housing_cost = max_housing_price(array_housing_cost, nr_of_cities);

    for (int person_count = 0; person_count < number_of_people; ++person_count) {
        score_array[person_count] = malloc(nr_of_cities * sizeof(temp_score));
        int *distance = dijkstra(distance_array, final_user[person_count].place_of_work_index, nr_of_cities);
        double max_transport_cost = max_result_transport_cost(person_count, transport_data, final_user);
        for (int city_count = 0; city_count < nr_of_cities; ++city_count) {
            time_score(score_array, person_count, distance, final_user, transport_data, city_count);
            env_score(score_array, person_count, distance, final_user, transport_data, city_count);
            transport_cost_price(score_array, person_count, distance, transport_data, city_count);
            housing_cost_score(score_array, person_count, array_housing_cost[city_count], city_count);
            sum_of_cost_scores(person_count, score_array, final_user, city_count, max_transport_cost,
                               yearly_max_housing_cost);
        }
    }
    for (int person_count = 0; person_count < number_of_people; ++person_count) {
        for (int city_count = 0; city_count < nr_of_cities; ++city_count) {

            if (final_user[person_count].exclusion.include_bus == 0) {
                score_array[person_count][city_count].sum_of_scores.score_bus = -1;
            } else
                score_array[person_count][city_count].sum_of_scores.score_bus =
                        score_array[person_count][city_count].time.score_bus +
                        score_array[person_count][city_count].environment.score_bus +
                        score_array[person_count][city_count].final_cost.score_bus;

            if (final_user[person_count].exclusion.include_car == 0) {
                score_array[person_count][city_count].sum_of_scores.score_car = -1;
            } else
                score_array[person_count][city_count].sum_of_scores.score_car =
                        score_array[person_count][city_count].time.score_car +
                        score_array[person_count][city_count].environment.score_car +
                        score_array[person_count][city_count].final_cost.score_car;

            if (final_user[person_count].exclusion.include_bike == 0) {
                score_array[person_count][city_count].sum_of_scores.score_bike = -1;
            } else
                score_array[person_count][city_count].sum_of_scores.score_bike =
                        score_array[person_count][city_count].time.score_bike +
                        score_array[person_count][city_count].environment.score_bike +
                        score_array[person_count][city_count].final_cost.score_bike;
        }
    }
    for (int person_count = 0; person_count < number_of_people; ++person_count) {
        for (int city_count = 0; city_count < nr_of_cities; ++city_count) {
            score_array[person_count][city_count].vehicle_winner.final_score = 1000;
            strcpy(score_array[person_count][city_count].vehicle_winner.vehicle, "none");
            if (score_array[person_count][city_count].sum_of_scores.score_bike >= 0 &&
                score_array[person_count][city_count].sum_of_scores.score_bike <= 100 &&
                score_array[person_count][city_count].sum_of_scores.score_bike <
                score_array[person_count][city_count].vehicle_winner.final_score) {

                score_array[person_count][city_count].vehicle_winner.final_score =
                        score_array[person_count][city_count].sum_of_scores.score_bike;
                strcpy(score_array[person_count][city_count].vehicle_winner.vehicle, "bike");
            }
            if (score_array[person_count][city_count].sum_of_scores.score_bus >= 0 &&
                score_array[person_count][city_count].sum_of_scores.score_bus <= 100 &&
                score_array[person_count][city_count].sum_of_scores.score_bus <
                score_array[person_count][city_count].vehicle_winner.final_score) {

                score_array[person_count][city_count].vehicle_winner.final_score =
                        score_array[person_count][city_count].sum_of_scores.score_bus;
                strcpy(score_array[person_count][city_count].vehicle_winner.vehicle, "bus");
            }
            if (score_array[person_count][city_count].sum_of_scores.score_car >= 0 &&
                score_array[person_count][city_count].sum_of_scores.score_car <= 100 &&
                score_array[person_count][city_count].sum_of_scores.score_car <
                score_array[person_count][city_count].vehicle_winner.final_score) {

                score_array[person_count][city_count].vehicle_winner.final_score =
                        score_array[person_count][city_count].sum_of_scores.score_car;
                strcpy(score_array[person_count][city_count].vehicle_winner.vehicle, "car");
            }
        }
    }
    return score_array;
}

/* double final_combined_score(temp_score *score_array,){
     for (int i = 0; i < nr_of_cities; ++i) {
         score[i].time.score_bus + score[i].cost.score_bus + score[i].enviroment.score_bus + score[i].housing_cost);
 */

double max_housing_price(int *array_housing_cost, int nr_of_cities) {
    int max_square_meter_price = 0;
    for (int i = 0; i < nr_of_cities; ++i) {
        if (array_housing_cost[i] > max_square_meter_price)
            max_square_meter_price = array_housing_cost[i];
    }
    return max_square_meter_price * 136.5 / 2 / 15;
}

void time_score(temp_score **scorearray, int person_number, int *distance, people_data *final_user,
                transport_vehicle_info *transport_data, int city) {
    if (final_user[person_number].exclusion.include_bus == 1) {
        if (distance[city] / transport_data[bus].speed > final_user[person_number].max_time) {
            scorearray[person_number][city].time.score_bus = INT_MAX;
        } else {
            scorearray[person_number][city].time.score_bus =
                    (distance[city] / transport_data[bus].speed) / final_user[person_number].max_time *
                    final_user[person_number].preference_time;
        }
    }
    if (final_user[person_number].exclusion.include_car == 1) {
        if (distance[city] / transport_data[car].speed > final_user[person_number].max_time) {
            scorearray[person_number][city].time.score_car = INT_MAX;
        } else {
            scorearray[person_number][city].time.score_car =
                    (distance[city] / transport_data[car].speed) / final_user[person_number].max_time *
                    final_user[person_number].preference_time;
        }
    }
    if (final_user[person_number].exclusion.include_bike == 1) {
        if (distance[city] / transport_data[bike].speed > final_user[person_number].max_time) {
            scorearray[person_number][city].time.score_bike = INT_MAX;
        } else {
            scorearray[person_number][city].time.score_bike =
                    (distance[city] / transport_data[bike].speed) / final_user[person_number].max_time *
                    final_user[person_number].preference_time;
        }
    }
}

void env_score(temp_score **scorearray, int person_number, int *distance, people_data *final_user,
               transport_vehicle_info *transport_data, int city) {

    double max_result_co2 = (final_user[person_number].max_time / (1 / transport_data[car].speed) *
                             transport_data[car].co2 * 189 *
                             2);
    if (final_user[person_number].exclusion.include_bus == 1) {
        scorearray[person_number][city].environment.score_bus =
                (distance[city] * transport_data[bus].co2 * 189 * 2) / max_result_co2 *
                final_user[person_number].preference_environment;
    }
    if (final_user[person_number].exclusion.include_car == 1) {
        scorearray[person_number][city].environment.score_car =
                (distance[city] * transport_data[car].co2 * 189 * 2) / max_result_co2 *
                final_user[person_number].preference_environment;
    }
    if (final_user[person_number].exclusion.include_bike == 1) {
        scorearray[person_number][city].environment.score_bike =
                (distance[city] * transport_data[bike].co2 * 189 * 2) / max_result_co2 *
                final_user[person_number].preference_environment;
    }

}

void
transport_cost_price(temp_score **scorearray, int person_number, int *distance, transport_vehicle_info *transport_data,
                     int city) {
    scorearray[person_number][city].transport_cost.score_bus = distance[city] * transport_data[bus].cost * 189 * 2;
    scorearray[person_number][city].transport_cost.score_car = distance[city] * transport_data[car].cost * 189 * 2;
    scorearray[person_number][city].transport_cost.score_bike = distance[city] * transport_data[bike].cost * 189 * 2;

}

double max_result_transport_cost(int person_number, transport_vehicle_info *transport_data, people_data *final_user) {

    return (final_user[person_number].max_time / (1 / transport_data[car].speed) * transport_data[car].cost * 189 * 2);
}

void housing_cost_score(temp_score **scorearray, int person_number, int current_city, int city) {

    scorearray[person_number][city].housing_cost = (current_city * 136.5 / 2 / 15);
}

void sum_of_cost_scores(int person_number, temp_score **scorearray, people_data *final_user, int city,
                        double max_result_transport_cost, double yearly_max_housing_cost) {

    if (final_user[person_number].exclusion.include_bus == 1) {
        scorearray[person_number][city].final_cost.score_bus =
                (scorearray[person_number][city].housing_cost +
                 scorearray[person_number][city].transport_cost.score_bus) /
                (max_result_transport_cost + yearly_max_housing_cost) * final_user[person_number].preference_cost;
    }
    if (final_user[person_number].exclusion.include_car == 1) {
        scorearray[person_number][city].final_cost.score_car =
                (scorearray[person_number][city].housing_cost +
                 scorearray[person_number][city].transport_cost.score_car) /
                (max_result_transport_cost + yearly_max_housing_cost) * final_user[person_number].preference_cost;
    }
    if (final_user[person_number].exclusion.include_bike == 1) {
        scorearray[person_number][city].final_cost.score_bike =
                (scorearray[person_number][city].housing_cost +
                 scorearray[person_number][city].transport_cost.score_bike) /
                (max_result_transport_cost + yearly_max_housing_cost) * final_user[person_number].preference_cost;
    }
}

shared_score *final_output(temp_score **scorearray, int number_of_cities, int number_of_people, char **city_name,
                           int *available_cities) {
    shared_score output_cities[number_of_cities];
    for (int city_count = 0; city_count < number_of_cities; ++city_count) {
        int city_availability = 0;
        for (int person_count = 0; person_count < number_of_people; ++person_count) {
            if (check_city(person_count, scorearray, city_count) != 0) {
                city_availability++;
            } else {
                output_cities[city_count].output_score += scorearray[person_count][city_count].vehicle_winner.final_score;
            }
        }
        if (city_availability != 0) {
            strcpy(output_cities[city_count].city_name, "unavailable");
            output_cities[city_count].output_score = -1;
        } else {
            strcpy(output_cities[city_count].city_name, city_name[city_count]);
            output_cities[city_count].output_score = output_cities[city_count].output_score / number_of_people;
        }
    }
    *available_cities = number_of_available_cities(output_cities, number_of_cities);
    shared_score *final_output = malloc(sizeof(shared_score) * *available_cities);
    int city_available_count = 0;
    for (int i = 0; i < number_of_cities; ++i) {
        if (output_cities[i].output_score != -1) {
            final_output[city_available_count].output_score = output_cities[i].output_score;
            strcpy(final_output[city_available_count].city_name, output_cities[i].city_name);
            final_output[city_available_count].city_index = i;
            city_available_count++;

        }
    }
    return final_output;
}

int number_of_available_cities(shared_score *temp_output, int number_of_cities) {
    int available_cities = 0;
    for (int i = 0; i < number_of_cities; ++i) {
        if (temp_output[i].output_score != -1) {
            available_cities++;
        }
    }
    return available_cities;
}

int check_city(int person_number, temp_score **scorearray, int city_number) {
    if (scorearray[person_number][city_number].vehicle_winner.final_score <= 100) {
        return 0;
    }
    return 1;
}

int final_score_sort_logic(const void *a, const void *b){
    shared_score *cityscorea = (shared_score*) a;
    shared_score *cityscoreb = (shared_score*) b;

    int check;

    if (cityscorea->output_score > cityscoreb->output_score)
        check = 1;

    if (cityscorea->output_score < cityscoreb->output_score)
        check = -1;

    return check;
}

