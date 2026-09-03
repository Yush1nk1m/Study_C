#include <stdio.h>
#include <stdlib.h>

#include "7_1_car.h"

int main(int argc, char** argv) {

    // allocate memory for a car object
    struct car_t* car = car_new();

    // construct the car object
    car_constructor(car);

    printf("Engine temperature before starting the car object: %f\n",
        car_get_engine_temperature(car));
    car_start(car);
    printf("Engine temperature after starting the car object: %f\n",
        car_get_engine_temperature(car));
    car_stop(car);
    printf("Engine temperature after stopping the car object: %f\n",
        car_get_engine_temperature(car));
    
    // destruct the car object
    car_destructor(car);

    // free the memory space allocated for the car object
    free(car);
    return 0;
}