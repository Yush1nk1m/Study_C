#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "7_2_gun.h"

// attribute structure
typedef struct {
    char* name;
    struct gun_t* gun;
} player_t;

// memory allocator
player_t* player_new() {
    return (player_t*) malloc(sizeof(player_t));
}

// constructor
void player_constructor(player_t* player, const char* name) {
    player->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
    strcpy(player->name, name);
    // set the aggregation pointer as NULL if it cannot be set in the constructor
    player->gun = NULL;
}

// destructor
void player_destructor(player_t* player) {
    free(player->name);
}

// behavior function
void player_pickup_gun(player_t* player, struct gun_t* gun) {
    // from this line, the aggregation relationship begins
    player->gun = gun;
}

void player_shoot(player_t* player) {
    // check if the player picked up a gun
    if (player->gun) {
        gun_trigger(player->gun);
    } else {
        printf("There's no gun!");
        exit(1);
    }
}

void player_drop_gun(player_t* player) {
    // from thie line, the aggregation relationship ends
    // the gun object cannot be destructed as it is not owned by the player object
    player->gun = NULL;
}