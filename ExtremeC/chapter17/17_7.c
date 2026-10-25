#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define SH_SIZE 4

// a file descriptor to point to the shared file
int shared_fd = -1;

// a pointer to point to the shared counter
int32_t* counter = NULL;

void init_shared_resource() {
    // open file
    shared_fd = open("data.bin", O_CREAT | O_RDWR, 0600);
    if (shared_fd < 0) {
        fprintf(stderr, "ERROR: Failed to create the file: %s\n", strerror(errno));
        exit(1);
    }
    fprintf(stdout, "File is created and opened with fd: %d\n", shared_fd);
}

void shutdown_shared_resource() {
    if (remove("data.bin") < 0) {
        fprintf(stderr, "ERROR: Removing the file failed: %s\n", strerror(errno));
        exit(1);
    }
}

void inc_counter() {
    usleep(1);
    int32_t temp = *counter;
    usleep(1);
    ++temp;
    usleep(1);
    *counter = temp;
    usleep(1);
}

int main(int argc, char** argv) {

    // parent process need to initialize the shared resource
    init_shared_resource();

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
    }

    return 0;
}