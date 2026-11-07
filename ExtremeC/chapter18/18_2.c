#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>

#include <pthread.h> // header to use pthread_mutex_*

#define SHARED_MEM_SIZE 4

// file descriptor to refer to the shared memory object
int shared_fd = -1;

// file descriptor to refer to the mutex's shared memory object
int mutex_shm_fd = -1;

// pointer to the shared counter
int32_t* counter = NULL;

// pointer to the shared mutex
pthread_mutex_t* mutex = NULL;

void init_control_mechanism() {
    // open the mutex shared memory
    mutex_shm_fd = shm_open("/mutex0", O_CREAT | O_RDWR, 0600);
    if (mutex_shm_fd < 0) {
        fprintf(stderr, "ERROR: Failed to create shared memory: %s\n", strerror(errno));
        exit(1);
    }
    // allocate and truncate mutex's shared memory space
    if (ftruncate(mutex_shm_fd, sizeof(pthread_mutex_t) < 0)) {
        fprintf(stderr, "ERROR: Truncation of mutex failed: %s\n", strerror(errno));
        exit(1);
    }
    // map mutex's shared memory
    void* map = mmap(0, sizeof(pthread_mutex_t), PROT_READ | PROT_WRITE, MAP_SHARED, mutex_shm_fd, 0);
    if (map == MAP_FAILED) {
        fprintf(stderr, "ERROR: Mapping failed: %s\n", strerror(errno));
        exit(1);
    }
    mutex = (pthread_mutex_t*) map;
    // initialize mutex object
    int ret = -1;
    pthread_mutexattr_t attr;
    if ((ret = pthread_mutexattr_init(&attr))) {
        fprintf(stderr, "ERROR: Failed to init mutex attrs: %s\n", strerror(ret));
        exit(1);
    }
    if ((ret = pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED))) {
        fprintf(stderr, "ERROR: Failed to set the mutex attr: %s\n", strerror(ret));
        exit(1);
    }
    if ((ret = pthread_mutex_init(mutex, &attr))) {
        fprintf(stderr, "ERROR: Initializing the mutex failed: %s\n", strerror(ret));
        exit(1);
    }
    if ((ret = pthread_mutexattr_destroy(&attr))) {
        fprintf(stderr, "ERROR: Failed to destroy mutex attrs: %s\n", strerror(ret));
        exit(1);
    }
}

void shutdown_control_mechanism() {
    int ret = -1;
    if ((ret = pthread_mutex_destroy(mutex))) {
        fprintf(stderr, "ERROR: Failed to destroy mutex: %s\n", strerror(ret));
        exit(1);
    }
    if (munmap(mutex, sizeof(pthread_mutex_t)) < 0) {
        fprintf(stderr, "ERROR: Unmapping the mutex failed: %s\n", strerror(errno));
        exit(1);
    }
    if (close(mutex_shm_fd) < 0) {
        fprintf(stderr, "ERROR: Closing the mutex failed: %s\n", strerror(errno));
        exit(1);
    }
    if (shm_unlink("/mutex0") < 0) {
        fprintf(stderr, "ERROR: Unlinking the mutex failed: %s\n", strerror(errno));
        exit(1);
    }
}

void inc_counter() {
    usleep(1);
    pthread_mutex_lock(mutex);      // need to check the return value
    int32_t temp = *counter;
    usleep(1);
    ++temp;
    usleep(1);
    *counter = temp;
    pthread_mutex_unlock(mutex);    // need to check the return value
    usleep(1);
}

int main(int argc, char** argv) {

    // parent process need to initialize the shared resources
    init_shared_resource();

    // parent process need to initialize the control mechanism
    init_control_mechanism();

    // allocate the shared memory area and truncate
    if (ftruncate(shared_fd, SH_SIZE * sizeof(char)) < 0) {
        fprintf(stderr, "ERROR: Truncation failed: %s\n", strerror(errno));
        return 1;
    }
    fprintf(stdout, "The memory region is truncated.\n");

    // map the shared memory and initialize the counter
    void* map = mmap(0, SH_SIZE, PROT_WRITE, MAP_SHARED, shared_fd, 0);
    if (map == MAP_FAILED) {
        fprintf(stderr, "ERROR: Mapping failed: %s\n", strerror(errno));
        return 1;
    }
    counter = (int32_t*) map;
    *counter = 0;

    // fork a new process
    pid_t pid = fork();
    if (pid) {  // parent process
        // increment the counter
        inc_counter();
        fprintf(stdout, "The parent process sees the counter as %d.\n", *counter);

        // wait the child process to terminate
        int status = -1;
        wait(&status);
        fprintf(stdout, "The child process finished with status %d.\n", status);
    } else {    // child process
        // increment the counter
        inc_counter();
        fprintf(stdout, "The child process sees the counter as %d.\n", *counter);
    }

    // both process need to unmap the shared memory area and close the file descriptor
    if (munmap(counter, SH_SIZE) < 0) {
        fprintf(stderr, "ERROR: Unmapping failed: %s\n", strerror(errno));
        return 1;
    }
    if (close(shared_fd) < 0) {
        fprintf(stderr, "ERROR: Closing shared memory fd failed: %s\n", strerror(errno));
        return 1;
    }

    // only the parent process need to shutdown the shared resource
    if (pid) {
        shutdown_shared_resource();
        shutdown_control_mechanism();
    }
}