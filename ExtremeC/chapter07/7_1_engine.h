#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_1_ENGINE_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_1_ENGINE_H

struct engine_t;

// memory allocator
struct engine_t* engine_new();

// constructor
void engine_constructor(struct engine_t*);

// destructor
void engine_destructor(struct engine_t*);

// behavior function
void engine_turn_on(struct engine_t*);
void engine_turn_off(struct engine_t*);
double engine_get_temperature(struct engine_t*);

#endif