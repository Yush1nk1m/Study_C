#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_4_CAT_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_4_CAT_H

// forward declaration
struct cat_t;

// memory allocator
struct cat_t* cat_new();

// constructor
void cat_constructor(struct cat_t*);

// destructor
void cat_destructor(struct cat_t*);

// all behavior functions are inherited from the animal class

#endif