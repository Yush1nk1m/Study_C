#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>

#include <semaphore.h>  // header to use semaphore

#define SHARED_MEM_SIZE 4
#define SH_SIZE 4

// shared file descriptor to refer to shared memory object
int shared_fd = -1;

// pointer to the shared counter
int32_t* counter = NULL;

// pointer to the shared semaphore
sem_t* semaphore = NULL;

void init_control_mechanism() {
    semaphore = sem_open("/sem0", O_CREAT | O_EXCL, 0600, 1);
    if (semaphore == SEM_FAILED) {
        fprintf(stderr, "ERROR: Opening the semaphore failed: %s\n", strerror(errno));
        exit(1);
    }
}

void shutdown_control_mechanism() {
    if (sem_close(semaphore) < 0) {
        fprintf(stderr, "ERROR: Closing the semaphore failed: %s\n", strerror(errno));
        exit(1);
    }
    if (sem_unlink("/sem0") < 0) {
        fprintf(stderr, "ERROR: Unlinking failed: %s\n", strerror(errno));
        exit(1);
    }
}

void init_shared_resource() {
    // open the shared memory object
    shared_fd = shm_open("/shm0", O_CREAT | O_RDWR, 0600);
    if (shared_fd < 0) {
        fprintf(stderr, "ERROR: Failed to create shared memory: %s\n", strerror(errno));
        exit(1);
    }
    fprintf(stdout, "Shared memory is created with fd: %d\n", shared_fd);
}

void shutdown_shared_resource() {
    if (shm_unlink("/shm0") < 0) {
        fprintf(stderr, "ERROR: Unlinking shared memory failed: %s\n", strerror(errno));
        exit(1);
    }
}

void inc_counter() {
    usleep(1);
    sem_wait(semaphore);    // need to check the return value
    int32_t temp = *counter;
    usleep(1);
    ++temp;
    usleep(1);
    *counter = temp;
    sem_post(semaphore);    // need to check the return value
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