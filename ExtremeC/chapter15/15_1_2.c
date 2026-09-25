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

    // thread detachment
    result = pthread_detach(thread);
    // if the detachment failed
    if (result) {
        printf("Thread could not be detached. Error number: %d\n", result);
        exit(2);
    }

    // main thread termination
    pthread_exit(NULL);

    return 0;
}