#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "8_4_animal.h"
#include "8_4_animal_p.h"

typedef struct {
    animal_t animal;
} duck_t;

// define a new behavior function for the sound of a duck
void __duck_sound(void* ptr) {
    animal_t* animal = (animal_t*) ptr;
    printf("%s: Quacks\n", animal->name);
}

// memory allocator
duck_t* duck_new() {
    return (duck_t*) malloc(sizeof(duck_t));
}

// constructor
void duck_constructor(duck_t* duck) {
    animal_constructor((struct animal_t*) duck);
    strcpy(duck->animal.name, "Duck");
    // sound_func points to the new behavior function and this is the line where the overriding occurs
    duck->animal.sound_func = __duck_sound;
}

// destructor
void duck_destructor(duck_t* duck) {
    animal_destructor((struct animal_t*) duck);
}