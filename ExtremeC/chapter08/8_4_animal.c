#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "8_4_animal_p.h"

// the basic definition of animal_sound at the level of the parent
void __animal_sound(void* this_ptr) {
    animal_t* animal = (animal_t*) this_ptr;
    printf("%s: Beeeep\n", animal->name);
}

// memory allocator
animal_t* animal_new() {
    return (animal_t*) malloc(sizeof(animal_t));
}

// constructor
void animal_constructor(animal_t* animal) {
    animal->name = (char*) malloc(10 * sizeof(char));
    strcpy(animal->name, "Animal");
    // set the function pointer to point to the basic definition
    animal->sound_func = __animal_sound;
}

// destructor
void animal_destructor(animal_t* animal) {
    free(animal->name);
}

// behavior function
void animal_get_name(animal_t* animal, char* buffer) {
    strcpy(buffer, animal->name);
}

void animal_sound(animal_t* animal) {
    // call the function, which is pointed by the function pointer
    animal->sound_func(animal);
}