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