// this code is needed to use non-POSIX functions
#define _GNU_SOURCE

#include <unistd.h>

// this header does not belong to POSIX
#include <sys/syscall.h>

int main(int argc, char** argv) {
    char message[20] = "Hello, world!\n";
    // call 'write' system call to write bytes to standard output
    syscall(__NR_write, STDOUT_FILENO, message, 14);
    return 0;
}