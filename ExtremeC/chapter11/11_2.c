// this code is necessary to use non-POSIX things
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>

// this is non-POSIX
#include <sys/syscall.h>

int main(int argc, char** argv) {
    char str[20] = "Kam";
    char message[64] = "";

    // hello world 시스템 호출 부르기
    int ret_val = syscall(999, str, 4, message, 64);
    if (ret_val < 0) {
        printf("[ERR] Ret val: %d\n", ret_val);
        return 1;
    }
    printf("Message: %s\n", message);
    return 0;
}