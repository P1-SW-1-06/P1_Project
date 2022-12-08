#pragma once
#include "main.h"
#include "user_input.h"
#include "import_handler.h"

temp_score **score_algorithm(int** distance_array, people_data* final_user, int nr_city, int number_of_people,transport_struct* transport_data);
void time_score(temp_score **scorearray,int person_number, int *distance, people_data *final_user, transport_struct *transport_data, int city);
double max_co2(people_data* final_user, transport_struct* transport_data);
void env_score(temp_score **scorearray,int person_number, int *distance, people_data *final_user, transport_struct *transport_data, int city);
void transport_cost_score(temp_score **scorearray,int person_number, int *distance, people_data *final_user, transport_struct *transport_data,int city);
void housing_cost_score(temp_score **scorearray, int person_number, double yearly_max_housing_cost, int current_city, int city);
double max_housing_price(int* array_housing_cost,int nr_city);
double max_result_transport_cost(int person_number, transport_struct *transport_data, people_data *final_user);
void sum_of_cost_scores(int person_number,temp_score **scorearray, people_data *final_user, int city, double max_result_transport_cost,double yearly_max_housing_cost);
