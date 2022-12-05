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
 * @param city_dist_matrix 2d int array of distances between cities
 * @param workplace int correlating to a city
 * @param number_of_cities int for the number of cities in the program
 * @return
 */
int* dijkstra(int** city_dist_matrix, int workplace, int number_of_cities);
/**
 *
 * @param distance_array array of distances to the different points
 * @param visited_points bool to check whether a point has been visited
 * @param num_cities int for the number of cities in the program
 * @return
 */
int shortest_distance(int* distance_array, bool* visited_points, int num_cities);
/**
 *
 * @param dist int the distance to point from source point
 * @param number_of_cities int for the number of cities in the program
 */
void printSolution(int dist[], int number_of_cities);