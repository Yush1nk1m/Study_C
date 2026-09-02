#include <stdio.h>  // header for printf function
#include <stdlib.h> // header for heap memory function
#include <string.h> // header for strcmp function

void fill(int* matrix, int rows, int columns) {
    int counter = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            *(matrix + i * columns + j) = counter;
        }
        ++counter;
    }
}

void print_matrix(int* matrix, int rows, int columns) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", *(matrix + i * columns + j));
        }
        printf("\n");
    }
}

void print_flat(int* matrix, int rows, int columns) {
    printf("Flat matrix: ");
    for (int i = 0; i < (rows * columns); ++i) {
        printf("%d ", *(matrix + i));
    }
    printf("\n");
}

int cache_friendly_sum(int* matrix, int rows, int columns) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sum += *(matrix + i * columns + j);
        }
    }
    return sum;
}

int non_cache_friendly_sum(int* matrix, int rows, int columns) {
    int sum = 0;
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            sum += *(matrix + i * columns + j);
        }
    }
    return sum;
}

int main(int argc, char** argv) {

    if (argc < 4) {
        printf("Usage: %s [print|cache-friendly-sum|non-cache-friendly-sum] ", argv[0]);
        printf("[number-of-rows] [number-of-columns]\n");
        exit(1);
    }
    char* operation = argv[1];
    int rows = atol(argv[2]);
    int columns = atol(argv[3]);

    int* matrix = (int*) malloc(rows * columns * sizeof(int));
    fill(matrix, rows, columns);

    if (strcmp(operation, "print") == 0) {
        print_matrix(matrix, rows, columns);
        print_flat(matrix, rows, columns);
    } else if (strcmp(operation, "cache-friendly-sum") == 0) {
        int sum = cache_friendly_sum(matrix, rows, columns);
        printf("Cache friendly sum: %d\n", sum);
    } else if (strcmp(operation, "non-cache-friendly-sum") == 0) {
        int sum = non_cache_friendly_sum(matrix, rows, columns);
        printf("Non cache friendly sum: %d\n", sum);
    } else {
        printf("FATAL: Not supported operation!\n");
        exit(1);
    }

    free(matrix);
    return 0;
}