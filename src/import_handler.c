/** @file import_handler.c
 *  @brief Imports information from transport_types.txt
 *
 *  Handles imports of data from transport_types.txt.
 *  It will error and exit if FILE if not found.
 *  Remember to free memory allocated by malloc.
 *
 *  @author
 *  @bug No known bugs.
 *  @tests !!No tests have been run.!!
*/

/* -- Includes -- */
#include "import_handler.h"


transport_struct *import_vehicle_data(const char* vehicle_data) {
    FILE *transport_file = read_file(vehicle_data);

    transport_struct *transport_data;
    transport_data = malloc(NUM_OF_TRANSPORT_TYPES * sizeof(transport_struct));

    read_data(transport_data, transport_file);

    fclose(transport_file);

    return transport_data;
}

int find_number_of_cities(const char* city_data){
    FILE *city_info = read_file(city_data);

    char tempname[30];
    int num_of_cities = 0;
    while(fscanf(city_info, "%s %*d",tempname)==1){
        num_of_cities++;
    }

    //printf("number of cities %d\n",num_of_cities);
    fclose(city_info);
    return num_of_cities;
}

char** import_city_names(const char* city_data, int number_of_cities){
    FILE *city_info = read_file(city_data);

    char **citynames;
    citynames = malloc(number_of_cities * sizeof(char*));
    char temp1[20];
    char prev_city[20];
    int index = 0;

    while(fscanf(city_info,"%s %*s %*d",temp1)==1){
        if(strcmp(temp1,prev_city) != 0) {
            citynames[index] = malloc((strlen(temp1)*sizeof(char)));
            strcpy(citynames[index],temp1);
            index++;
        }
        strcpy(prev_city,temp1);
    }
    fclose(city_info);
    return citynames;
}


int** import_city_distances(const char* city_distances, int number_of_cities, char** city_name_array){
    FILE *city_data = read_file(city_distances);

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
    fclose(city_data);
    return djikstra_array;
}

unsigned int index_city_names(char* name, char** city_name_array, int num_cities){
    for (int i = 0; i < num_cities; ++i) {
        if (strcmp(name,city_name_array[i]) == 0){
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
    } return 1;
}

void read_data(transport_struct *data, FILE *file) {
    // * "Do not store this", [^\n] "any character except newline"
    fscanf(file, "%*[^\n]\n");
    data[0].num_of_vehicle = 0;
    int i = 0;
    while (fscanf(file, "%s" "%lf" "%lf" "%lf", data[i].name, &data[i].speed, &data[i].cost, &data[i].co2) == 4) {
        i++;
        data[0].num_of_vehicle += 1;
    }
}

void print_data(transport_struct *data) {
    int i = 0;
    while (i < data[0].num_of_vehicle) {
        printf("----\n");
        printf("'%s' '%lf' '%lf' '%lf'\n", data[i].name, data[i].speed, data[i].cost, data[i].co2);
        ++i;
    }
}



FILE* read_file(const char* input_file) {
    FILE* temp_file = fopen(input_file, "r");
        if (!file_exists(temp_file)) {
            fclose(temp_file);
            exit(0);
        }
        return temp_file;
}