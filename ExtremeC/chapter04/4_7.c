#include <unistd.h> // header for sleep function
#include <stdlib.h> // header for malloc function
#include <stdio.h>  // header for printf function

int main(int argc, char** argv) {
    void* ptr = malloc(1024);   // allocate 1KB from heap
    printf("Address: %p\n", ptr);
    fflush(stdout);
    // infinite loop
    while (1) {
        sleep(1);   // sleep for 1 second
    }
    return 0;
}