#include <stdio.h>

#define SIZE 5

int main(int argc, char** argv) {
    int arr[SIZE];
    arr[0] = 2; arr[1] = 3; arr[2] = 5; arr[3] = 7; arr[4] = 9;

    int* ptr = &arr[0];
    do {
        printf("%d\n", *ptr);
    } while (++ptr <= &arr[SIZE - 1]);

    return 0;
}