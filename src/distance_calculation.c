/** @file dijkstra.c
 * This file contains the functionality for the calculation of finding the shortest path from source to all other
 * nodes in the graph. Inspiration has been conducted from
 * https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
 * It has been rewritten from the scratch to fit into the projects use case.
 *
 * @author P1-SW-1-06
 * @bug No known bugs.
 * @tests !!No tests have been run.!!
*/

#include "distance_calculation.h"


void printSolution(int dist[], int number_of_cities)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < number_of_cities; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

int shortest_distance(int* distance_array, bool* visited_cities, int num_cities){
    int min = INT_MAX;
    int shortest_dist_index;
    for (int i = 0; i < num_cities; ++i) {
        if(visited_cities[i] == false && distance_array[i] <= min){
            //checks whether the points have been visited and that the distance is smaller than INT_MAX
            min = distance_array[i];
            shortest_dist_index = i;
        }
    }
    return shortest_dist_index;
}

int* dijkstra(int** city_dist_matrix, int workplace, int number_of_cities)
{
    int *dist_from_workplace = (int*) malloc(sizeof(int) * number_of_cities);
    // The output array.  dist[i] will hold the shortest distance from src to i
    bool visited_cities[number_of_cities];
    for (int i = 0; i < number_of_cities; ++i) {
        dist_from_workplace[i] = INT_MAX;
        visited_cities[i] = false;
    }
    dist_from_workplace[workplace] = 0;
    for (int count = 0; count < number_of_cities - 1; count++) {

        int current_vertex = shortest_distance(dist_from_workplace, visited_cities, number_of_cities);
        visited_cities[current_vertex] = true;

        for (int i = 0; i < number_of_cities; i++) {
            if (!visited_cities[i]
                && (city_dist_matrix[current_vertex][i] && dist_from_workplace[current_vertex] != INT_MAX)
                && city_dist_matrix[current_vertex][i] + dist_from_workplace[current_vertex] < dist_from_workplace[i]){
                // returns true if visited_points[i] is false
                // and the distances are different from INT_MAX
                // and the new distance + the distance is smaller than the recorded distance for that point
                dist_from_workplace[i] = dist_from_workplace[current_vertex] + city_dist_matrix[current_vertex][i];
            }
        }
    }
    return dist_from_workplace;
}


