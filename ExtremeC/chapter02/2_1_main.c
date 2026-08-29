#include <stdio.h>
#include "2_1.h"

int main(int argc, char** argv) {
    // array declaration
    int array[5];

    // fill the array with values
    array[0] = 2;
    array[1] = -3;
    array[2] = 5;
    array[3] = -7;
    array[4] = 11;

    // calculate the average of the array with 'avg' function
    double average = avg(array, 5, NORMAL);
    printf("The average: %f\n", average);

    average = avg(array, 5, SQUARED);
    printf("The squared average: %f\n", average);

    return 0;
}