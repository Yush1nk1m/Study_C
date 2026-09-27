#include <stdio.h>
#include <stdlib.h>

// standard POSIX header to use pthread library
#include <pthread.h>

// a mutex object used to synchronize access to the shared state
pthread_mutex_t mutex;

void* thread_body_1(void* arg) {
    // get the pointer to the shared variable
    int* shared_var_ptr = (int*) arg;

    // critical section
    pthread_mutex_lock(&mutex);
    ++(*shared_var_ptr);
    printf("%d\n", *shared_var_ptr);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* thread_body_2(void* arg) {
    int* shared_var_ptr = (int*) arg;

    // critical section
    pthread_mutex_lock(&mutex);
    *shared_var_ptr += 2;
    printf("%d\n", *shared_var_ptr);
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main(int argc, char** argv) {

    // shared variable
    int shared_var = 0;

    // thread handler
    pthread_t thread1;
    pthread_t thread2;

    // initialize the mutex and resource
    pthread_mutex_init(&mutex, NULL);

    // create new threads
    int result1 = pthread_create(&thread1, NULL, thread_body_1, &shared_var);
    int result2 = pthread_create(&thread2, NULL, thread_body_2, &shared_var);

    if (result1 || result2) {
        printf("The threads could not be created.\n");
        exit(1);
    }

    // wait for the threads to terminate
    result1 = pthread_join(thread1, NULL);
    result2 = pthread_join(thread2, NULL);

    if (result1 || result2) {
        printf("The threads could not be joined.\n");
        exit(2);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}