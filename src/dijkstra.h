/** @file dijkstra.h
 * @brief functions prototypes
 *
 * This contains the prototypes of the functions used in the dijkstra.c file
 *
 * @author
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
 */

#pragma once
/* -- Includes -- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

/* -- Prototypes -- */
/**
 *
 * @return
 */
int find_number_of_cities();
/**
 *
 * @param number_of_cities
 * @return
 */
char** create_city_name_array(int number_of_cities);
/**
 *
 * @param number_of_cities
 * @param city_name_array
 * @return
 */
int** create_city_distance_matrix(int number_of_cities, char** city_name_array);
/**
 *
 * @param name
 * @param city_name_array
 * @param num_cities
 * @return
 */
unsigned int index_city_names(char* name, char** city_name_array, int num_cities);
/**
 *
 * @param city_dist_matrix
 * @param workplace
 * @param number_of_cities
 * @return
 */
int* dijkstra(int** city_dist_matrix, int workplace, int number_of_cities);
/**
 *
 * @param distance_array
 * @param visited_points
 * @param num_cities
 * @return
 */
int shortest_distance(int* distance_array, bool* visited_points, int num_cities);
/**
 *
 * @param dist
 * @param number_of_cities
 */
void printSolution(int dist[], int number_of_cities);