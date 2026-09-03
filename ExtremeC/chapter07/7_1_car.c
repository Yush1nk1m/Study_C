#include <stdlib.h>

// Car can only serve as a public interface for Engine
#include "7_1_engine.h"

typedef struct {
    // composition relationship
    struct engine_t* engine;
} car_t;

car_t* car_new() {
    return (car_t*) malloc(sizeof(car_t));
}

void car_constructor(car_t* car) {
    // allocate memory for an engine object
    car->engine = engine_new();

    // construct the engine object
    engine_constructor(car->engine);
}

void car_destructor(car_t* car) {
    // destruct the engine object
    engine_destructor(car->engine);

    // free the memory space allocated for the engine object
    free(car->engine);
}

void car_start(car_t* car) {
    engine_turn_on(car->engine);
}

void car_stop(car_t* car) {
    engine_turn_off(car->engine);
}

double car_get_engine_temperature(car_t* car) {
    return engine_get_temperature(car->engine);
}