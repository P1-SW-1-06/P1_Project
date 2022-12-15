#include <assert.h>
#include "../src/dijkstra.h"
#include "../src/import_handler.h"

int main(){

    int** djikstra_array;
    int number_of_cities = 10;

    djikstra_array = (int **) malloc(number_of_cities * (sizeof(int *)));
    for (int i = 0; i < number_of_cities; ++i) {
        djikstra_array[i] = (int *) malloc(number_of_cities * sizeof(int));
    }

    for (int i = 0; i < number_of_cities; ++i) {
        for (int j = 0; j < number_of_cities; ++j) {
            djikstra_array[i][j] = 1;
        }
    }

    printf("%d\n",djikstra_array[0][0]);

    int* distance_array = dijkstra(djikstra_array,0,10);

    assert(distance_array[0]==0);
    assert(distance_array[5]==1);
    assert(distance_array[9]==1);

    for (int i = 0; i < number_of_cities; ++i) {
        for (int j = 0; j < number_of_cities; ++j) {
            djikstra_array[i][j] = 0;
        }
    }

    djikstra_array[0][9] = 50;

    distance_array = dijkstra(djikstra_array,0,10);


    assert(distance_array[9]==50);


    int** djikstra_array2;
    number_of_cities = 4;

    djikstra_array2 = (int **) malloc(number_of_cities * (sizeof(int *)));
    for (int i = 0; i < number_of_cities; ++i) {
        djikstra_array2[i] = (int *) malloc(number_of_cities * sizeof(int));
    }

    for (int i = 0; i < number_of_cities; ++i) {
        for (int j = 0; j < number_of_cities; ++j) {
            djikstra_array2[i][j] = 0;
        }
    }

    djikstra_array2[1][0] = 10;
    djikstra_array2[0][1] = 10;
    djikstra_array2[0][2] = 20;
    djikstra_array2[0][3] = 40;
    djikstra_array2[1][3] = 5;


    int* distance_array2 = dijkstra(djikstra_array2,0,4);

    assert(distance_array2[3]==15);
    assert(distance_array2[2]==20);

    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int *p[9];

    for (int i = 0; i < 9; ++i) {
        p[i]= graph[i];
    }

    int* distance_array3 = dijkstra(p,0,9);

    assert(distance_array3[1] == 4);
}