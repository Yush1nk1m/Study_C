#include <stdio.h>
#include <stdlib.h>

#include "8_2_person.h"
#include "8_2_student.h"

int main(int argc, char** argv) {
    // create and construct a student object
    struct student_t* student = student_new();
    student_constructor(student, "John", "Doe", 1987, "TA5667", 134);

    // call person's behavior function to read its attributes from the student object
    char buffer[32];

    // upcast to the parent type's pointer
    struct person_t* person_ptr = (struct person_t*) student;

    person_get_first_name(person_ptr, buffer);
    printf("First name: %s\n", buffer);

    person_get_last_name(person_ptr, buffer);
    printf("Last name: %s\n", buffer);

    printf("Birth year: %d\n", person_get_birth_year(person_ptr));

    // read the attributes limited to the student object
    student_get_student_number(student, buffer);
    printf("Student number: %s\n", buffer);

    printf("Passed credits: %d\n", student_get_passed_credits(student));

    // destruct and free the student object
    student_destructor(student);
    free(student);

    return 0;
}