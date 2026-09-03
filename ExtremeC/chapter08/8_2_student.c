#include <stdlib.h>
#include <string.h>

#include "8_2_person.h"

// this header file defines person_t structure
#include "8_2_person_p.h"

// forward declaration
typedef struct {
    // at this point all attributes of the person class are inherited
    person_t person;
    char* student_number;
    unsigned int passed_credits;
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
    // call the constructor of the parent class
    person_constructor((struct person_t*) student, first_name, last_name, birth_year);
    student->student_number = (char*) malloc(16 * sizeof(char));
    strcpy(student->student_number, student_number);
    student->passed_credits = passed_credits;
}

// destructor
void student_destructor(student_t* student) {
    // needed to destruct the child object
    free(student->student_number);
    person_destructor((struct person_t*) student);
}

// behavior function
void student_get_student_number(student_t* student, char* buffer) {
    strcpy(buffer, student->student_number);
}

unsigned int student_get_passed_credits(student_t* student) {
    return student->passed_credits;
}