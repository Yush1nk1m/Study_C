#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_2_PLAYER_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_2_PLAYER_H

// forward declaration
struct player_t;
struct gun_t;

// memory allocator
struct player_t* player_new();

// constructor
void player_constructor(struct player_t*, const char*);

// destructor
void player_destructor(struct player_t*);

// behavior function
void player_pickup_gun(struct player_t*, struct gun_t*);
void player_shoot(struct player_t*);
void player_drop_gun(struct player_t*);

#endif