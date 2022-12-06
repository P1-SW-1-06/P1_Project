#pragma once

typedef enum {
    bus, car, bike
} transport_types;

typedef enum {
    frederikshavn, aalborg, hjoerring, hobro, stoevring, thisted, noerresundby, broenderslev
} cities;

typedef struct {
    int include_car;
    int include_bus;
    int include_bike;
} exclusions;

typedef struct {
    char name[50];
    int max_time;
    int preference_environment;
    int preference_cost;
    int preference_time;
    transport_types included_transport_types[4];
    exclusions exclusion;
    char* place_of_work;
} people_data;

typedef struct {
    char name[50];

} city_data;

typedef struct {
    char name[20];
    double co2;
    double cost;
    double speed;
    int num_of_vehicle;
} transport_struct;


