#include <stdio.h>
#include <stdlib.h>

// standard POSIX header to use pthread library
#include <pthread.h>

// this function includes the logic that needs to be executed as a body of an independent thread
void* thread_body(void* arg) {
    printf("Hello from first thread!\n");
    return NULL;
}

int main(int argc, char** argv) {

    // thread handler
    pthread_t thread;

    // create a new thread
    int result = pthread_create(&thread, NULL, thread_body, NULL);
    // if the creation failed
    if (result) {
        printf("Thread could not be created. Error number: %d\n", result);
        exit(1);
    }

    // wait for the created thread to finish
    result = pthread_join(thread, NULL);
    // if the joining failed
    if (result) {
        printf("The thread could not be joined. Error number: %d\n", result);
        exit(2);
    }
    return 0;
}