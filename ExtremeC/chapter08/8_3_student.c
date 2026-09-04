#include <stdlib.h>
#include <string.h>

// public interface for person class
#include "8_3_person.h"

// forward declaration
typedef struct {
    char* student_number;
    unsigned int passed_credits;
    // at this line, a pointer is needed as person_t is the incomplete type
    struct person_t* person;
} student_t;

// memory allocator
student_t* student_new() {
    return (student_t*) malloc(sizeof(student_t));
}

// constructor
void student_constructor(student_t* student,
                        const char* first_name,
                        const char* last_name,
                        unsigned int birth_year,
                        const char* student_number,
                        unsigned int passed_credits) {
    // allocate memory for the parent object
    student->person = person_new();
    person_constructor(student->person, first_name, last_name, birth_year);
    student->student_number = (char*) malloc(16 * sizeof(char));
    strcpy(student->student_number, student_number);
    student->passed_credits = passed_credits;
}

// destructor
void student_destructor(student_t* student) {
    // at first, need to destruct the child object
    free(student->student_number);
    // and then, call the destructor of the parent class
    person_destructor(student->person);
    // finally, release the memory allocated for the parent object
    free(student->person);
}

// behavior function
void student_get_first_name(student_t* student, char* buffer) {
    // need to call person's behavior function
    person_get_first_name(student->person, buffer);
}

void student_get_last_name(student_t* student, char* buffer) {
    // need to call person's behavior function
    person_get_last_name(student->person, buffer);
}

unsigned int student_get_birth_year(student_t* student) {
    // need to call person's behavior function
    return person_get_birth_year(student->person);
}

void student_get_student_number(student_t* student, char* buffer) {
    strcpy(buffer, student->student_number);
}

unsigned int student_get_passed_credits(student_t* student) {
    return student->passed_credits;
}