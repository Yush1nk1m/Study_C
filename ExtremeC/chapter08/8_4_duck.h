#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_4_DUCK_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_4_DUCK_H

// forward declaration
struct duck_t;

// memory allocator
struct duck_t* duck_new();

// constructor
void duck_constructor(struct duck_t*);

// destructor
void duck_destructor(struct duck_t*);

// all behavior functions are inherited from the animal class

#endif