#pragma once
#include "main.h"
#include "user_input.h"
#include "import_handler.h"

temp_score* score_algorithm(int** distance_array, people_data* final_user, int nr_city, int number_of_people,transport_struct* transport_data);
void time_score(temp_score *scorearray, int* distance, people_data* final_user, transport_struct* transport_data, int city);
double max_co2(people_data* final_user, transport_struct* transport_data);
void env_score(temp_score *scorearray ,int* distance, people_data* final_user, transport_struct* transport_data, int city);
void transport_cost_score(temp_score *scorearray, int* distance, people_data* final_user, transport_struct* transport_data, int city);