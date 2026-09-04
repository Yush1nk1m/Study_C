#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_4_ANIMAL_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_4_ANIMAL_H

// forward declaration
struct animal_t;

// memory allocator
struct animal_t* animal_new();

// constructor
void animal_constructor(struct animal_t*);

// destructor
void animal_destructor(struct animal_t*);

// behavior function
void animal_get_name(struct animal_t*, char*);
void animal_sound(struct animal_t*);

#endif