#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_2_GUN_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_2_GUN_H

typedef int bool_t;

// forward declaration
struct gun_t;

// memory allocator
struct gun_t* gun_new();

// constructor
void gun_constructor(struct gun_t*, int);

// destructor
void gun_destructor(struct gun_t*);

// behavior function
bool_t gun_has_bullets(struct gun_t*);
void gun_trigger(struct gun_t*);
void gun_refill(struct gun_t*);

#endif