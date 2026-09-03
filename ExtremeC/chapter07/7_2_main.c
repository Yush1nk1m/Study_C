#include <stdio.h>
#include <stdlib.h>

#include "7_2_player.h"
#include "7_2_gun.h"

int main(int argc, char** argv) {
    // create and construct a gun object
    struct gun_t* gun = gun_new();
    gun_constructor(gun, 3);

    // create and construct a player object
    struct player_t* player = player_new();
    player_constructor(player, "Billy");

    // start the aggregate relationship
    player_pickup_gun(player, gun);

    // shoot until bullets run out
    while (gun_has_bullets(gun)) {
        player_shoot(player);
    }

    // reload the gun
    gun_refill(gun);

    // shoot until the bullets run out
    while (gun_has_bullets(gun)) {
        player_shoot(player);
    }

    // end the aggregate relationship
    player_drop_gun(player);

    // destruct and free the player object
    player_destructor(player);
    free(player);

    // destruct and free the gun object
    gun_destructor(gun);
    free(gun);

    return 0;
}