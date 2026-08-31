#include <stdio.h>  // header for printf function
#include <stdlib.h> // header for malloc & free functions

void fill(char* ptr) {
    ptr[0] = 'H';
    ptr[1] = 'e';
    ptr[2] = 'l';
    ptr[3] = 'l';
    ptr[4] = 'o';
}

int main(int argc, char** argv) {
    void* gptr = malloc(10 * sizeof(char));
    char* ptr = (char*) gptr;
    fill(ptr);
    printf("%s!\n", ptr);
    free(ptr);
    return 0;
}