//
// Created by Anders Overgaard Lisberg on 20/11/2022.
//

#ifndef MAIN_C_IMPORT_HANDLER_H
#define MAIN_C_IMPORT_HANDLER_H



typedef struct {
    char name[20];
    double co2;
    double cost;
    double speed;
} transport_data;

transport_data import_data();

#endif //MAIN_C_IMPORT_HANDLER_H