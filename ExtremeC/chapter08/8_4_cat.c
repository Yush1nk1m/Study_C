#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "8_4_animal.h"
#include "8_4_animal_p.h"

typedef struct {
    animal_t animal;
} cat_t;

// define a new behavior function for the sound of a cat
void __cat_sound(void* ptr) {
    animal_t* animal = (animal_t*) ptr;
    printf("%s: Meow\n", animal->name);
}

// memory allocator
cat_t* cat_new() {
    return (cat_t*) malloc(sizeof(cat_t));
}

// constructor
void cat_constructor(cat_t* cat) {
    animal_constructor((struct animal_t*) cat);
    strcpy(cat->animal.name, "Cat");
    // sound_func points to the new behavior function and this is the line where the overriding occurs
    cat->animal.sound_func = __cat_sound;
}

// destructor
void cat_destructor(cat_t* cat) {
    animal_destructor((struct animal_t*) cat);
}