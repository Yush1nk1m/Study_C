#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_4_ANIMAL_P_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_4_ANIMAL_P_H

// a function pointer type needed to point the other morphs of animal_sound function
typedef void (*sound_func_t)(void*);

// forward declaration
typedef struct {
    char* name;
    // this member is a pointer to the function which behaves sound function
    sound_func_t sound_func;
} animal_t;

#endif