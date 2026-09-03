#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_2_PERSON_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_2_PERSON_H

// forward declaration
struct person_t;

// memory allocator
struct person_t* person_new();

// constructor
void person_constructor(struct person_t*,
                        const char*     /* first name */,
                        const char*     /* last name*/,
                        unsigned int    /* birth year */);


// destructor
void person_destructor(struct person_t*);

// behavior function
void person_get_first_name(struct person_t*, char*);
void person_get_last_name(struct person_t*, char*);
unsigned int person_get_birth_year(struct person_t*);

#endif