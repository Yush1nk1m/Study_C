#include <stdlib.h>
#include <string.h>

// this header file defines person_t structure
#include "8_2_person_p.h"

// memory allocator
person_t* person_new() {
    return (person_t*) malloc(sizeof(person_t));
}

// constructor
void person_constructor(person_t* person,
                        const char* first_name,
                        const char* last_name,
                        unsigned int birth_year) {
    strcpy(person->first_name, first_name);
    strcpy(person->last_name, last_name);
    person->birth_year = birth_year;
}

// destructor
void person_destructor(person_t* person) {
    // no need to do anything
}

// behavior function
void person_get_first_name(person_t* person, char* buffer) {
    strcpy(buffer, person->first_name);
}

void person_get_last_name(person_t* person, char* buffer) {
    strcpy(buffer, person->last_name);
}

unsigned int person_get_birth_year(person_t* person) {
    return person->birth_year;
}