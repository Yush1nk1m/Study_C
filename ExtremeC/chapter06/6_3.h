#ifndef EXTREME_C_EXAMPLES_CHAPTER_6_3_H
#define EXTREME_C_EXAMPLES_CHAPTER_6_3_H

#include <unistd.h>

// attribute structure with no public attribute
struct list_t;

// allocation function
struct list_t* list_malloc();

// constructor and destructor function
void list_init(struct list_t*);
void list_destroy(struct list_t*);

// public behavior function
int list_add(struct list_t*, int);
int list_get(struct list_t*, int, int*);
void list_clear(struct list_t*);
size_t list_size(struct list_t*);
void list_print(struct list_t*);

#endif