#include "dijkstra.h"

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int number_of_cities)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < number_of_cities; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

int shortest_distance(int* distance_array, bool* visited_points, int num_cities){
    int min = INT_MAX;
    int shortest_index;
    for (int i = 0; i < num_cities; ++i) {
        if(visited_points[i] == false && distance_array[i] <= min){
            min = distance_array[i];
            shortest_index = i;
        }
    }
    return shortest_index;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
int* dijkstra(int** city_dist_matrix, int workplace, int number_of_cities)
{
    int *dist_from_src = (int*) malloc(sizeof(int) * number_of_cities); // The output array.  dist[i] will hold the
    // shortest distance from src to i
    bool visited_points[number_of_cities];
    for (int i = 0; i < number_of_cities; ++i) {
        dist_from_src[i] = INT_MAX;
        visited_points[i] = false;
    }
    dist_from_src[workplace] = 0;
    for (int count = 0; count < number_of_cities - 1; count++) {
        int current_vertex = shortest_distance(dist_from_src, visited_points, number_of_cities);

        visited_points[current_vertex] = true;

        for (int i = 0; i < number_of_cities; i++) {
            if (!visited_points[i]
                && (city_dist_matrix[current_vertex][i] && dist_from_src[current_vertex] != INT_MAX)
                && city_dist_matrix[current_vertex][i] + dist_from_src[current_vertex] < dist_from_src[i]){

                dist_from_src[i] = dist_from_src[current_vertex] + city_dist_matrix[current_vertex][i];
            }
        }
    }
    // print the constructed distance array
    printSolution(dist_from_src, number_of_cities);
    return dist_from_src;
}

int find_number_of_cities(){
    FILE *city_info = fopen("city_information.txt", "r");
    if(city_info == NULL){
        printf("file not found");
        exit(0);
    }
    char tempname[30];
    int num_of_cities = 0;
    while(fscanf(city_info, "%s %*d",tempname)==1){
        num_of_cities++;
    }

    printf("number of cities %d\n",num_of_cities);
    fclose(city_info);
    return num_of_cities;
}

char** create_city_name_array(int number_of_cities){
    FILE *city_data = fopen("city_information.txt","r");
    if(city_data == NULL){
        printf("file not found");
    }
    char **citynames;
    citynames = malloc(number_of_cities * sizeof(char*));
    char temp1[20];
    char prev_city[20];
    int index = 0;

    while(fscanf(city_data,"%s %*s %*d",temp1)==1){
        if(strcmp(temp1,prev_city) != 0) {
            citynames[index] = malloc((strlen(temp1)*sizeof(char)));
            strcpy(citynames[index],temp1);
            index++;
        }
        strcpy(prev_city,temp1);
    }
    fclose(city_data);
    return citynames;
}

int** create_city_distance_matrix(int number_of_cities, char** city_name_array){
    FILE *city_data = fopen("cities.txt","r");
    if(city_data == NULL){
        printf("file not found");
    }

    int **djikstra_array;
    djikstra_array = (int**)malloc(number_of_cities  * (sizeof(int*)));
    for (int i = 0; i < number_of_cities; ++i) {
        djikstra_array[i]= (int*) malloc(number_of_cities*sizeof(int));
    }

    for (int i = 0; i < number_of_cities; ++i) {
        for (int j = 0; j < number_of_cities; ++j) {
            djikstra_array[i][j]=0;
        }
    }

    char temp1[20];
    char temp2[20];
    int value = 0;
    while(fscanf(city_data,"%s %s %d",temp1,temp2,&value)==3){
        djikstra_array[index_city_names(temp1,city_name_array,number_of_cities)]
        [index_city_names(temp2, city_name_array, number_of_cities)]=value;
        djikstra_array[index_city_names(temp2,city_name_array,number_of_cities)]
        [index_city_names(temp1, city_name_array, number_of_cities)]=value;
    }
    return djikstra_array;
}

unsigned int index_city_names(char* name, char** city_name_array, int num_cities){
    for (int i = 0; i < num_cities; ++i) {
        if (strcmp(name,city_name_array[i]) == 0){
            return i;
        }
    }
    printf("index function error occurred\nmismatch between city data files\n");
    exit(0);
}