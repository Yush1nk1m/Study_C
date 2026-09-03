#include <stdlib.h>

typedef int bool_t;

// attribute structure
typedef struct {
    int bullets;
} gun_t;

// memory allocator
gun_t* gun_new() {
    return (gun_t*) malloc(sizeof(gun_t));
}

// constructor
void gun_constructor(gun_t* gun, int initial_bullets) {
    gun->bullets = 0;
    if (initial_bullets > 0) {
        gun->bullets = initial_bullets;
    }
}

// destructor
void gun_destructor(gun_t* gun) {
    // no need to do anything
}

// behavior function
bool_t gun_has_bullets(gun_t* gun) {
    return (gun->bullets > 0);
}

void gun_trigger(gun_t* gun) {
    --gun->bullets;
}

void gun_refill(gun_t* gun) {
    gun->bullets = 7;
}