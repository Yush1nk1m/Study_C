#include <stdio.h>
#include <stdlib.h>

// POSIX standard header to use pthread library
#include <pthread.h>

// semaphore which is not provided by pthread.h
#include <semaphore.h>

// main pointer to the semaphore object
sem_t* semaphore;

void* thread_body_1(void* arg) {
    // get the pointer to the shared variable
    int* shared_var_ptr = (int*) arg;
    // semaphore wait
    sem_wait(semaphore);
    // increment the shared variable by 1
    ++(*shared_var_ptr);
    printf("%d\n", *shared_var_ptr);
    // semaphore release
    sem_post(semaphore);
    return NULL;
}

void* thread_body_2(void* arg) {
    // get the pointer to the shared variable
    int* shared_var_ptr = (int*) arg;
    // semaphore wait
    sem_wait(semaphore);
    // increment the shared variable by 2
    *shared_var_ptr += 2;
    printf("%d\n", *shared_var_ptr);
    // semaphore release
    sem_post(semaphore);
    return NULL;
}

int main(int argc, char** argv) {

    // shared variable
    int shared_var = 0;

    // thread handler
    pthread_t thread1;
    pthread_t thread2;

#ifdef __APPLE__
    // OS/X does not support unnamed semaphores
    // hence, initialize the semaphore as a named semaphore
    semaphore = sem_open("sem0", O_CREAT | O_EXCL, 0644, 1);
#else
    sem_t local_semaphore;
    semaphore = &local_semaphore;
    // initialize the semaphore as a mutex(binary semaphore)
    sem_init(semaphore, 0, 1);
#endif

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

#ifdef __APPLE__
    sem_close(semaphore);
#else
    sem_destroy(semaphore);
#endif

    return 0;
}