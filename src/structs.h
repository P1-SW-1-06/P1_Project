/** @file structs.h
 * Contains all the structs used in other parts of the program.
 *
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
*/

#pragma once
/* enum possible vehicles so it can be called directly in the functions */
typedef enum {
    bus, car, bike
} transport_types;

/* the structure to store if the user has included or excluded a vehicle */
typedef struct {
    int include_car;
    int include_bus;
    int include_bike;
} exclusions;

/* the structure to store all the data prompted by the user */
typedef struct {
    char name[50];
    int max_time;
    int preference_environment;
    int preference_cost;
    int preference_time;
    transport_types included_transport_types[4];
    exclusions exclusion;
    char* place_of_work;
    unsigned int place_of_work_index;
} people_data;

/* the structure to store the data read and collected by the transport_types.txt */
typedef struct {
    char name[20];
    double co2;
    double cost;
    double speed;
    int num_of_vehicles;
} transport_vehicle_info;

/* the structure to store the scores for each possible transport vehicle in the dataset */
typedef struct {
    double score_bus;
    double score_car;
    double score_bike;
} transport_vehicle;

/* the structure to store the best score and the type as a string for a city */
typedef struct{
    char vehicle[10];
    double final_score;
} best_score;

/* the structure to store the score for each vehicle for each city */
typedef struct{
    double housing_cost;
    transport_vehicle sum_of_scores;
    transport_vehicle final_cost;
    transport_vehicle transport_cost;
    transport_vehicle environment;
    transport_vehicle time;
    best_score vehicle_winner;
} temp_score;

/* the structure to store the shared shore for all users, which makes it possible to compare cities */
typedef struct{
    char city_name[50];
    double output_score;
    int city_index;
} shared_score;

