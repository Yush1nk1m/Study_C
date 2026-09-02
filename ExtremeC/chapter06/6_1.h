#ifndef EXTREME_C_EXAMPLES_CHAPTER_6_1_H
#define EXTREME_C_EXAMPLES_CHAPTER_6_1_H

// this structure has all attributes related to the Car object
typedef struct {
    char name[32];
    double speed;
    double fuel;
} car_t;

// this function declarations correspond to the behaviors of the Car object
void car_construct(car_t*, const char*);
void car_destruct(car_t*);
void car_accelerate(car_t*);
void car_brake(car_t*);
void car_refuel(car_t*, double);

#endif