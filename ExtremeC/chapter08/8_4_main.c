#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// include only public interfaces
#include "8_4_animal.h"
#include "8_4_cat.h"
#include "8_4_duck.h"

int main(int argc, char** argv) {
    struct animal_t* animal = animal_new();
    struct cat_t* cat = cat_new();
    struct duck_t* duck = duck_new();

    animal_constructor(animal);
    cat_constructor(cat);
    duck_constructor(duck);

    animal_sound(animal);
    animal_sound((struct animal_t*) cat);
    animal_sound((struct animal_t*) duck);

    animal_destructor(animal);
    cat_destructor(cat);
    duck_destructor(duck);

    free(duck);
    free(cat);
    free(animal);

    return 0;
}