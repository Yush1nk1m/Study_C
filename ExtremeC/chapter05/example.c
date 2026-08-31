#include <string.h>

int main(int argc, char** argv) {
    char str[10];
    strcpy(str, argv[1]);
    printf("Hello %s!\n", str);
}