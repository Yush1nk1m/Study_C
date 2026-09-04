#include <stdio.h>
#include <stdlib.h>

#include "8_3_student.h"

int main(int argc, char** argv) {
    // create and construct a student object
    struct student_t* student = student_new();
    student_constructor(student, "John", "Doe", 1987, "TA5667", 134);

    // need to call Student's behavior function as the student's pointer cannot be casted to the person's pointer
    char buffer[32];
    student_get_first_name(student, buffer);
    printf("First name: %s\n", buffer);

    student_get_last_name(student, buffer);
    printf("Last name: %s\n", buffer);

    printf("Birth year: %d\n", student_get_birth_year(student));

    student_get_student_number(student, buffer);
    printf("Student number: %s\n", buffer);

    printf("Passed credits: %d\n", student_get_passed_credits(student));

    // destruct and release the student object
    student_destructor(student);
    free(student);

    return 0;
}