#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// alias of bool_t type definition
typedef int bool_t;

// list_t type definition
typedef struct {
    size_t size;
    int* items;
} list_t;

// private behavior checking if the list is full
bool_t __list_is_full(list_t* list) {
    return (list->size == MAX_SIZE);
}

// private behavior checking index
bool_t __check_index(list_t* list, const int index) {
    return (index >= 0 && index <= list->size);
}

// memory allocation for the list object
list_t* list_malloc() {
    return (list_t*) malloc(sizeof(list_t));
}

// constructor for the list object
void list_init(list_t* list) {
    list->size = 0;
    // allocate from the heap memory
    list->items = (int*) malloc(MAX_SIZE * sizeof(int));
}

// destructor for the list object
void list_destroy(list_t* list) {
    // free the allocated memory
    free(list->items);
}

int list_add(list_t* list, const int item) {
    // how to use for the private behavior
    if (__list_is_full(list)) {
        return -1;
    }
    list->items[list->size++] = item;
    return 0;
}

int list_get(list_t* list, const int index, int* result) {
    if (__check_index(list, index)) {
        *result = list->items[index];
        return 0;
    }
    return -1;
}

void list_clear(list_t* list) {
    list->size = 0;
}

size_t list_size(list_t* list) {
    return list->size;
}

void list_print(list_t* list) {
    printf("[");
    for (size_t i = 0; i < list->size; ++i) {
        printf("%d ", list->items[i]);
    }
    printf("]\n");
}