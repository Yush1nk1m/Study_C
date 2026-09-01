#include <stdlib.h> // header for malloc
#include <string.h> // header for memset

int main(int argc, char** argv) {
    char* ptr = (char*) malloc(16 * sizeof(char));
    memset(ptr, 0, 16 * sizeof(char));      // fill with 0
    memset(ptr, 0xff, 16 * sizeof(char));   // fill with 0xff
    ...
    free(ptr);
    return 0;
}