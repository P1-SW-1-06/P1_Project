/** @file import_handler.c
 *  @brief Imports information from transport_types.txt
 *
 *  Handles imports of data from transport_types.txt.
 *  It will error and exit if FILE if not found.
 *  Remember to free memory allocated by malloc.
 *
 *  @author
 *  @bug If there's more cities in cities than in city_information it will fail.
 *  @tests !!No tests have been run.!!
*/

/* -- Includes -- */
#include "import_handler.h"

transport_struct *import_vehicle_data(const char *vehicle_data) {
    FILE *transport_file = read_file(vehicle_data);

    transport_struct *transport_data;
    transport_data = malloc(NUM_OF_TRANSPORT_TYPES * sizeof(transport_struct));

    // * "Do not store this", [^\n] "any character except newline"
    fscanf(transport_file, "%*[^\n]\n");
    transport_data[0].num_of_vehicles = 0;
    int i = 0;
    while (fscanf(transport_file, "%s" "%lf" "%lf" "%lf", transport_data[i].name, &transport_data[i].speed,
                  &transport_data[i].cost, &transport_data[i].co2) == 4) {
        i++;
        transport_data[0].num_of_vehicles += 1;
    }

    fclose(transport_file);

    return transport_data;
}

int find_number_of_cities(const char *city_data) {
    FILE *city_info = read_file(city_data);

    char temp_city[30];
    int num_of_cities = 0;
    while (fscanf(city_info, "%s %*d", temp_city) == 1) {
        num_of_cities++;
    }

    //printf("number of cities %d\n",num_of_cities);
    fclose(city_info);
    return num_of_cities;
}

char **import_city_names(const char *city_data, int number_of_cities) {
    FILE *city_info = read_file(city_data);

    char **city_names;
    city_names = malloc(number_of_cities * sizeof(char *));
    char current_city[20];
    char previous_city[20];
    int index = 0;

    while (fscanf(city_info, "%s %*s %*d", current_city) == 1) {
        if (strcmp(current_city, previous_city) != 0) {
            city_names[index] = malloc((strlen(current_city) * sizeof(char)));
            strcpy(city_names[index], current_city);
            index++;
        }
        strcpy(previous_city, current_city);
    }
    fclose(city_info);
    return city_names;
}

int **import_city_distances(const char *city_distances, int number_of_cities, char **city_name_array) {
    FILE *city_data = read_file(city_distances);

    int **djikstra_array;
    djikstra_array = (int **) malloc(number_of_cities * (sizeof(int *)));
    for (int i = 0; i < number_of_cities; ++i) {
        djikstra_array[i] = (int *) malloc(number_of_cities * sizeof(int));
    }

    for (int i = 0; i < number_of_cities; ++i) {
        for (int j = 0; j < number_of_cities; ++j) {
            djikstra_array[i][j] = 0;
        }
    }

    char city_1[20];
    char city_2[20];
    int value = 0;
    while (fscanf(city_data, "%s %s %d", city_1, city_2, &value) == 3) {
        /* There's the same distance between the opposite city therefore fx point (1,2) should be the same as (2,1)*/
        djikstra_array[index_city_names(city_1, city_name_array, number_of_cities)]
        [index_city_names(city_2, city_name_array, number_of_cities)] = value;

        djikstra_array[index_city_names(city_2, city_name_array, number_of_cities)]
        [index_city_names(city_1, city_name_array, number_of_cities)] = value;
    }
    fclose(city_data);
    return djikstra_array;
}

unsigned int index_city_names(char *name, char **city_name_array, int num_cities) {
    for (int i = 0; i < num_cities; ++i) {
        if (strcmp(name, city_name_array[i]) == 0) {
            return i;
        }
    }
    printf("index function error occurred\nmismatch between city data files\n");
    exit(-1);
}

int file_exists(FILE *file) {
    if (file == NULL) {
        printf("'transport_types' could not be found. Make sure to select working directory\n");
        return 0;
    }
    return 1;
}

void print_data(transport_struct *data) {
    int i = 0;
    while (i < data[0].num_of_vehicles) {
        printf("----\n");
        printf("'%s' '%lf' '%lf' '%lf'\n", data[i].name, data[i].speed, data[i].cost, data[i].co2);
        ++i;
    }
}

FILE *read_file(const char *input_file) {
    FILE *temp_file = fopen(input_file, "r");
    if (!file_exists(temp_file)) {
        fclose(temp_file);
        exit(0);
    }
    return temp_file;
}
int* find_housing_cost(const char *city_data, int num_cities) {
    FILE *city_information = read_file(city_data);

    int squaremeter_price = 0;
    int i = 0;
    int *array_housing_cost = malloc(num_cities * sizeof(int));
    while (fscanf(city_information, "%*s %d", &squaremeter_price) == 1) {
        array_housing_cost[i] = squaremeter_price;
        i++;
    }

    fclose(city_information);
    return array_housing_cost;
}