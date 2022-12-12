#pragma once

typedef enum {
    bus, car, bike
} transport_types;

typedef struct {
    int include_car;
    int include_bus;
    int include_bike;
} exclusions;

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

typedef struct {
    char name[20];
    double co2;
    double cost;
    double speed;

    int num_of_vehicles;
} transport_vehicle_info;

typedef struct {
    double score_bus;
    double score_car;
    double score_bike;
} transport_vehicle;

typedef struct{
    char vehicle[10];
    double final_score;
} best_score;

typedef struct{
    double housing_cost;
    transport_vehicle sum_of_scores;
    transport_vehicle final_cost;
    transport_vehicle transport_cost;
    transport_vehicle environment;
    transport_vehicle time;
    best_score vehicle_winner;
} temp_score;

typedef struct{
    char city_name[50];
    double output_score;
    int city_index;
} shared_score;

