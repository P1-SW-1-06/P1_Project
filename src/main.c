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
    int** city_distance_array = import_city_distances("cities.txt",
                                                      num_of_cities,
                                                      city_name);
    /*for (int j = 0; j < num_of_cities; ++j) {
        for (int i = 0; i < num_of_cities; ++i) {
            printf("[%d]\t",city_distance_array[j][i]);
        }
        printf("\n");
    }*/


    int number_of_people = scan_number_of_people();
    people_data* user_data = collect_user_input(city_name,num_of_cities, number_of_people);


    temp_score* score = score_algorithm(city_distance_array,user_data,num_of_cities,number_of_people,transport_data);

/*
    for (int i = 0; i < num_of_cities; ++i) {
        printf("\nCity name: %s\nBus\nTime score: %lf\n Trans score: %lf\n Env score: %lf\n Housing cost score: %lf \n Final cost score: %lf",
               city_name[i],
               score[i].time.score_bus,
               score[i].transport_cost.score_bus,
               score[i].enviroment.score_bus,
               score[i].housing_cost,
               score[i].final_cost.score_bus);
        printf("\nCar\n Time score: %lf\n Trans score: %lf\n Env score: %lf\n Housing cost score: %lf \n Final cost score: %lf",
               score[i].time.score_car,
               score[i].transport_cost.score_car,
               score[i].enviroment.score_car,
               score[i].housing_cost,
               score[i].final_cost.score_car);
        printf("\nBike\n Time score: %lf\n Trans score: %lf\n Env score: %lf\n Housing cost score: %lf \n Final cost score: %lf",
               score[i].time.score_bike,
               score[i].transport_cost.score_bike,
               score[i].enviroment.score_bike,
               score[i].housing_cost,
               score[i].final_cost.score_bike);

    }
*/
    for (int i = 0; i < num_of_cities; ++i) {
        double bus_score = score[i].time.score_bus + score[i].enviroment.score_bus + score[i].final_cost.score_bus;
        double car_score = score[i].time.score_car + score[i].enviroment.score_car + score[i].final_cost.score_car;
        double bike_score = score[i].time.score_bike + score[i].enviroment.score_bike + score[i].final_cost.score_bike;


        printf("\n City: %s\n BUSSCORE: %.2lf\n CARSCORE: %.2lf\n BIKESCORE: %.2lf\n ",city_name[i],bus_score, car_score, bike_score);

    }
}