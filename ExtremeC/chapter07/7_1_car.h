#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_1_CAR_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_1_CAR_H

struct car_t;

// memory allocator
struct car_t* car_new();

// constructor
void car_constructor(struct car_t*);

// destructor
void car_destructor(struct car_t*);

// behavior function
void car_start(struct car_t*);
void car_stop(struct car_t*);
double car_get_engine_temperature(struct car_t*);

#endif