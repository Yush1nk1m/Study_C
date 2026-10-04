#define __GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>  // header for errno and strerror function

// POSIX standard header to use pthread library
#include <pthread.h>
// pthread.h does not support semaphores
#include <semaphore.h>

#ifdef __APPLE__
// apple systems need to mimic the barrier functionality
pthread_mutex_t barrier_mutex;
pthread_cond_t barrier_cv;
unsigned int barrier_thread_count;
unsigned int barrier_round;
unsigned int barrier_thread_limit;

void barrier_wait() {
    pthread_mutex_lock(&barrier_mutex);
    ++barrier_thread_count;
    if (barrier_thread_count >= barrier_thread_limit) {
        barrier_thread_count = 0;
        ++barrier_round;
        pthread_cond_broadcast(&barrier_cv);
    } else {
        unsigned int my_round = barrier_round;
        do {
            pthread_cond_wait(&barrier_cv, &barrier_mutex);
        } while (my_round == barrier_round);
    }
    pthread_mutex_unlock(&barrier_mutex);
}

#else
// barrier to synchronize hydrogen and oxygen threads
pthread_barrier_t water_barrier;
#endif

// mutex to synchronize oxygen threads
pthread_mutex_t oxygen_mutex;

// general semaphore to synchronize hydrogen threads
sem_t* hydrogen_sem;

// shared integer to count the number of water molecules
unsigned int num_of_water_molecules;

void* hydrogen_thread_body(void* arg) {
    // 2 hydrogen threads are accessible to the same critical section
    sem_wait(hydrogen_sem);
    // wait for the other hydrogen thread to join
#ifdef __APPLE__
    barrier_wait();
#else
    pthread_barrier_wait(&water_barrier);
#endif
    sem_post(hydrogen_sem);
    return NULL;
}

void* oxygen_thread_body(void* arg) {
    pthread_mutex_lock(&oxygen_mutex);
    // wait for the hydrogen threads to join
#ifdef __APPLE__
    barrier_wait();
#else
    pthread_barrier_wait(&water_barrier);
#endif
    ++num_of_water_molecules;
    pthread_mutex_unlock(&oxygen_mutex);
    return NULL;
}

int main(int argc, char** argv) {

    num_of_water_molecules = 0;

    // initialize an oxygen mutex
    pthread_mutex_init(&oxygen_mutex, NULL);

    // initialize hydrogen semaphores
#ifdef __APPLE__
    hydrogen_sem = sem_open("hydrogen_sem", O_CREAT | O_EXCL, 0644, 2);
#else
    sem_t local_sem;
    hydrogen_sem = &local_sem;
    sem_init(hydrogen_sem, 0, 2);
#endif

    // initialize a water barrier
#ifdef __APPLE__
    pthread_mutex_init(&barrier_mutex, NULL);
    pthread_cond_init(&barrier_cv, NULL);
    barrier_thread_count = 0;
    barrier_thread_limit = 0;
    barrier_round = 0;
#else
    pthread_barrier_init(&water_barrier, NULL, 3);
#endif

    // 50 oxygen atoms and 10 hydrogen atoms are needed to form 50 water molecules
    pthread_t thread[150];

    // create oxygen threads
    for (int i = 0; i < 50; ++i) {
        if (pthread_create(thread + i, NULL, oxygen_thread_body, NULL)) {
            printf("Could not create an oxygen thread.\n");
            exit(1);
        }
    }

    // create hydrogen threads
    for (int i = 50; i < 150; ++i) {
        if (pthread_create(thread + i, NULL, hydrogen_thread_body, NULL)) {
            printf("Could not create a hydrogen thread.\n");
            exit(2);
        }
    }

    printf("Waiting for hydrogen and oxygen atoms to react ...\n");
    // wait for all threads to terminate
    for (int i = 0; i < 150; ++i) {
        if (pthread_join(thread[i], NULL)) {
            printf("The thread could not be joined.\n");
            exit(3);
        }
    }

    printf("Number of made water molecules: %d\n", num_of_water_molecules);

#ifdef __APPLE__
    sem_close(hydrogen_sem);
#else
    sem_destroy(hydrogen_sem);
#endif

    return 0;
}