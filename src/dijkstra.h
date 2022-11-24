#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int find_number_of_cities();
char** create_city_name_array(int number_of_cities);
int** create_city_distance_matrix(int number_of_cities, char** city_name_array);
unsigned int index_city_names(char* name, char** city_name_array, int num_cities);
int* dijkstra(int** city_dist_matrix, int workplace, int number_of_cities);
int shortest_distance(int* distance_array, bool* visited_points, int num_cities);
void printSolution(int dist[], int number_of_cities);