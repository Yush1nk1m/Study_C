#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>

#define CHECK_RESULT(result) \
if (result) { \
    printf("A pthread error happened.\n"); \
    exit(1); \
}

int TRUE = 1;
int FALSE = 0;

// a pointer to the shared array
char* shared_array;
// size of the shared array
unsigned int shared_array_len;

void* alloc_thread_body(void* arg) {
    shared_array_len = 20;
    shared_array = (char*) malloc(shared_array_len * sizeof(char*));
    return NULL;
}

void* filler_thread_body(void* arg) {
    int even = *((int*) arg);
    char c = 'a';
    size_t start_index = 1;
    if (even) {
        c = 'Z';
        start_index = 0;
    }
    for (size_t i = start_index; i < shared_array_len; i += 2) {
        shared_array[i] = even ? c-- : c++;
    }
    shared_array[shared_array_len - 1] = '\0';
    return NULL;
}

void* printer_thread_body(void* arg) {
    printf(">> %s\n", shared_array);
    return NULL;
}

void* dealloc_thread_body(void* arg) {
    free(shared_array);
    return NULL;
}

int main(int argc, char** argv) {
    // ... create threads ...
}