#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>

#include <pthread.h>    // header to use pthread_mutex_* function

typedef uint16_t bool_t;

#define TRUE 1
#define FALSE 0

#define MUTEX_SHM_NAME "/mutex0"
#define SHM_NAME "/shm0"

// shared file descriptor to refer to the shared memory object including cancel flag
int cancel_flag_shm_fd = -1;

// flag to indicate whether the current process owns the shared memory object or not
bool_t cancel_flag_shm_owner = FALSE;

// file descriptor to refer to the mutex's shared memory object
int mutex_shm_fd = -1;

// shared mutex
pthread_mutex_t* mutex = NULL;

// flag to indicate whether the current process owns the shared memory object
bool_t mutex_owner = FALSE;

// pointer to the cancel flag in the shared memory object
bool_t* cancel_flag = NULL;

void init_shared_resource() {
    // open the shared memory object
    cancel_flag_shm_fd = shm_open(SHM_NAME, O_RDWR, 0600);
    if (cancel_flag_shm_fd >= 0) {
        cancel_flag_shm_owner = FALSE;
        fprintf(stdout, "The shared memory object is opened.\n");
    } else if (errno == ENOENT) {
        fprintf(stderr, "WARN: The shared memory object doesn't exist.\n");
        fprintf(stdout, "Creating the shared memory object ...\n");
        cancel_flag_shm_fd = shm_open(SHM_NAME, O_CREAT | O_EXCL | O_RDWR, 0600);
        if (cancel_flag_shm_fd >= 0) {
            cancel_flag_shm_owner = TRUE;
            fprintf(stdout, "The shared memory object is created.\n");
        } else {
            fprintf(stderr, "ERROR: Failed to create shared memory: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        fprintf(stderr, "ERROR: Failed to create shared memory: %s\n", strerror(errno));
        exit(1);
    }
    if (cancel_flag_shm_owner) {
        // allocate and truncate the shared memory space
        if (ftruncate(cancel_flag_shm_fd, sizeof(bool_t)) < 0) {
            fprintf(stderr, "ERROR: Truncation failed: %s\n", strerror(errno));
            exit(1);
        }
        fprintf(stdout, "The memory region is truncated.\n");
    }
    // map the shared memory and initialize the cancel flag
    void* map = mmap(0, sizeof(bool_t), PROT_WRITE, MAP_SHARED, cancel_flag_shm_fd, 0);
    if (map == MAP_FAILED) {
        fprintf(stderr, "ERROR: Mapping failed: %s\n", strerror(errno));
        exit(1);
    }
    cancel_flag = (bool_t*) map;
    if (cancel_flag_shm_owner) {
        *cancel_flag = FALSE;
    }
}

void shutdown_shared_resource() {
    if (munmap(cancel_flag, sizeof(bool_t)) < 0) {
        fprintf(stderr, "ERROR: Unmapping failed: %s\n", strerror(errno));
        exit(1);
    }
    if (close(cancel_flag_shm_fd) < 0) {
        fprintf(stderr, "ERROR: Closing the shared memory fd failed: %s\n", strerror(errno));
        exit(1);
    }
    if (cancel_flag_shm_owner) {
        sleep(1);
        if (shm_unlink(SHM_NAME) < 0) {
            fprintf(stderr, "ERROR: Unlinking the shared memory failed: %s\n", strerror(errno));
            exit(1);
        }
    }
}

void init_control_mechanism() {
    // open the mutex's shared memory
    mutex_shm_fd = shm_open(MUTEX_SHM_NAME, O_RDWR, 0600);
    if (mutex_shm_fd >= 0) {
        // mutex's shared object exists and the current process is not the owner
        mutex_owner = FALSE;
        fprintf(stdout, "The mutex's shared memory object is opened.\n");
    } else if (errno == ENOENT) {
        fprintf(stderr, "WARN: Mutex's shared memory doesn't exist.\n");
        fprintf(stdout, "Creating the mutex's shared memory object ...\n");
        mutex_shm_fd = shm_open(MUTEX_SHM_NAME, O_CREAT | O_EXCL | O_RDWR, 0600);
        if (mutex_shm_fd >= 0) {
            mutex_owner = TRUE;
            fprintf(stdout, "The mutex's shared memory object is created.\n");
        } else {
            fprintf(stderr, "ERROR: Failed to create mutex's shared memory: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        fprintf(stderr, "ERROR: Failed to create mutex's shared memory: %s\n", strerror(errno));
        exit(1);
    }
    if (mutex_owner) {
        // allocate and truncate the mutex's shared memory space
        if (ftruncate(mutex_shm_fd, sizeof(pthread_mutex_t)) < 0) {
            fprintf(stderr, "ERROR: Truncation of the mutex failed: %s\n", strerror(errno));
            exit(1);
        }
    }
    // map the mutex's shared memory
    void* map = mmap(0, sizeof(pthread_mutex_t), PROT_READ | PROT_WRITE, MAP_SHARED, mutex_shm_fd, 0);
    if (map == MAP_FAILED) {
        fprintf(stderr, "ERROR: Mapping failed: %s\n", strerror(errno));
        exit(1);
    }
    mutex = (pthread_mutex_t*) map;
    if (mutex_owner) {
        int ret = -1;
        pthread_mutexattr_t attr;
        if ((ret = pthread_mutexattr_init(&attr))) {
            fprintf(stderr, "ERROR: Initialiing mutex attributes failed: %s\n", strerror(ret));
            exit(1);
        }
        if ((ret = pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED))) {
            fprintf(stderr, "ERROR: Setting the mutex attribute failed: %s\n", strerror(ret));
            exit(1);
        }
        if ((ret = pthread_mutex_init(mutex, &attr))) {
            fprintf(stderr, "ERROR: Initializing the mutex failed: %s\n", strerror(ret));
            exit(1);
        }
        if ((ret = pthread_mutexattr_destroy(&attr))) {
            fprintf(stderr, "ERROR: Destruction of mutex attributes failed: %s\n", strerror(ret));
            exit(1);
        }
    }
}