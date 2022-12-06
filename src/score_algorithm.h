#pragma once
#include "main.h"
#include "user_input.h"
#include "import_handler.h"


temp_score* time_score(int* distance ,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data);
double max_co2(people_data* final_user, transport_struct* transport_data);
temp_score* env_score(int* distance,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data);
temp_score* transport_cost_score(int* distance,int nr_city, people_data* final_user, int number_of_people, transport_struct* transport_data);