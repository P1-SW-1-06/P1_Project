/** @file score_algorithm.h

*  This contains the prototypes for the
        *  functions and structs used in the program.
*
*  @author
*  @bug No known bugs.
*  @tests !!No tests have been run.!!
*/
#pragma once
#include "main.h"
#include "user_input.h"
#include "import_handler.h"

/**
 * @description a function that allocates memory for struct temp_score
 * allocates memory for each person in the already allocated memory.
 * The function contains 3 different for loops in for loops.
 * 1. a loop that runs number of cities in a for loop that runs number of people times
 * that calculates a score for each persons transport vehicle for each reachable city.
 * 2. a loop that runs number of cities in a for loop that runs number of people times
 * if a vehicle is excluded it is given the value -1 else a sum for the vehicle-score is calculated.
 * 3. a loop that runes number of cities in a for loop that runs number of people times.
 * Sets vehicle.winner.final.score = 1000 and vehicle as "none" to have a score there is out of bound to compare with.
 * Checks if the first vehicle is between 0 and 100 and smaller than vehicle.winner.final.score.
 * If it is set the vehicle score as vehicle.winner.final.score and the transport type instead of "none".
 * Every vehicle is checked this way and at last only the best vehicle score is stored in vehicle.winner.final.score
 * and the transport vehicle is stored in vehicle.winner.vehicle.
 * @param distance_array a two dimensional array******************
 * @param final_user a pointer to the struct people_data
 * @param nr_of_cities the number of cities in the dataset
 * @param number_of_people the number of users
 * @param transport_data a pointer to the struct transport_vehicle_info
 * @return
 */
temp_score **score_algorithm(int **distance_array, people_data* final_user, int nr_of_cities, int number_of_people,transport_vehicle_info* transport_data);

/**
 * @description a function that checks the value in struct exclusions for bus, car and bike (0=excluded, 1=included).
 * Checks which cities can be reached based on distance, transport speed and the users max transport time.
 * If a city can not be reached set time score to INT_MAX for the given transport vehicle
 * else a timescore is calculated for person_number and city based on
 * distance, speed, user max transport time and preference points and stores the data in an array of type struct.
 * @param scorearray a two dimensional array of the struct temp_score
 * @param person_number index for a person in the array
 * @param distance distance from the person of index workplace to each city
 * @param final_user a pointer to the struct people_data
 * @param transport_data a pointer to the struct transport_vehicle_info
 * @param city index for a city in the array
 */
void time_score(temp_score **scorearray,int person_number, int *distance, people_data *final_user, transport_vehicle_info *transport_data, int city);

/**
 * @description a function that calculates max amount of co2 for a year (189 workdays).
 * A function that checks the value in struct exclusions for bus, car and bike (0=excluded, 1=included).
 * If included calculate a environment score for person_number and city based on
 * distance, carbon footprint, max co2 and preference points and stores the data in an array of type struct.
 * @param scorearray a two dimensional array of the struct temp_score
 * @param person_number index for a person in the array
 * @param distance distance from the person of index workplace to each city
 * @param final_user a pointer to the struct people_data
 * @param transport_data a pointer to the struct transport_vehicle_info
 * @param city index for a city in the array
 */
void env_score(temp_score **scorearray,int person_number, int *distance, people_data *final_user, transport_vehicle_info *transport_data, int city);

/**
 * @description a function that calculates the yearly price of all transportation types based on
 * distance, cost and workdays(189).
 * Stores the data in an array of type struct.
 * @param scorearray a two dimensional array of the struct temp_score
 * @param person_number index for a person in the array
 * @param distance distance from the person of index workplace to each city
 * @param transport_data a pointer to the struct transport_vehicle_info
 * @param city index for a city in the array
 */
void transport_cost_price(temp_score **scorearray,int person_number, int *distance, transport_vehicle_info *transport_data,int city);

/**
 * @description a function that calculates the maximal yearly price for transportation based on
 * the most expensive, fastest vehicle in the dataset and max_time and stores the data in an array of type struct.
 * @param person_number index for a person in the array
 * @param transport_data a pointer to the struct transport_vehicle_info
 * @param final_user a pointer to the struct people_data
 * @return the maximal yearly price for transportation
 */
double max_result_transport_cost(int person_number, transport_vehicle_info *transport_data, people_data *final_user);

/**
 * @description a function that calculates a yearly housing price for 1 person based on
 * square-meter price, the average house size(136.5 m^2) and the average living time in a house(15 years).
 * Stores the data in an array of type struct.
 * @param scorearray a two dimensional array of the struct temp_score
 * @param person_number index for a person in the array
 * @param current_city the average square-meter price
 * @param city index for a city in the array
 */
void housing_cost_score(temp_score **scorearray, int person_number, int current_city, int city);

/**
 * @description a function that finds the biggest square-meter price in the dataset.
 * @param array_housing_cost pointer to housing cost array
 * @param nr_of_cities the number of cities in the dataset
 * @return the most expensive yearly housing price in the dataset
 */
double max_housing_price(int* array_housing_cost,int nr_of_cities);

/**
 * @description a function that checks the value in struct exclusions for bus, car and bike (0=excluded, 1=included).
 * If included calculates a cost score for each vehicle based on
 * housing cost for a city, transport_cost_price, max_result_transport_cost , max_yearly_housing_cost and
 * preference points this data is then stored in an array of type struct.
 * @param person_number index for a person in the array
 * @param scorearray a two dimensional array of the struct temp_score
 * @param final_user a pointer to the struct people_data
 * @param city index for a city in the array
 * @param max_result_transport_cost is the function max_result_transport_cost
 * @param yearly_max_housing_cost is the function max_housing_price
 */
void sum_of_cost_scores(int person_number,temp_score **scorearray, people_data *final_user, int city, double max_result_transport_cost,double yearly_max_housing_cost);

/**
 * @description a function that checks if the final.score is <= 100
 * if the vehicle_winner.final.score <= 100 returns 0 else return 1.
 * @param person_number index for a person in the array
 * @param scorearray a two dimensional array of the struct temp_score
 * @param city_number index for a city in the array
 * @return returns 0 or 1
 */
int check_city(int person_number, temp_score **scorearray, int city_number);

/**
 * @description a function that checks which cities is available.
 * @param temp_output pointer to an array of the type struct that holds the average total score for a city
 * @param number_of_cities the number of cities in the dataset
 * @return the amount of available cities
 */
int number_of_available_cities(shared_score *temp_output, int number_of_cities);

/**
 * @description a function that checks if a city is available due to the value returned from function check_city:
 * If 1 set city name as unavailable set score as -1.
 * If != 1 add the sum of vehicle winners for a city and then find the average city score based on the users.
 * The score is then stored in output_cities this score is then checked for != -1.
 * If != -1 then the score is stored in final_output and available cities is counted up.
 * @param scorearray a two dimensional array of the struct temp_score
 * @param number_of_cities the number of cities in the dataset
 * @param number_of_people the number of users
 * @param city_name array of strings containing the names of the cities in the dataset
 * @param available_cities the amount of available cities
 * @return final_output
 */
shared_score *final_output(temp_score **scorearray, int number_of_cities, int number_of_people, char **city_name,int *available_cities);

/**
 * @description a function that sorts the available cities in order with the smallest score first.
 * @param a void pointer
 * @param b void pointer
 * @return check = 1 or -1
 */
int final_score_sort_logic(const void *a, const void *b);