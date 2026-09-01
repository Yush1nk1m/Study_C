#include <stdio.h>  // header for printf function
#include <stdlib.h> // header for heap memory function

#define QUEUE_MAX_SIZE 100

typedef struct {
    int front;
    int rear;
    double* arr;
} queue_t;

void init(queue_t* q) {
    q->front = q->rear = 0;
    // queue object owns the allocated heap memory block
    q->arr = (double*) malloc(QUEUE_MAX_SIZE * sizeof(double));
}

void destroy(queue_t* q) {
    free(q->arr);
}

int size(queue_t* q) {
    return q->rear - q->front;
}

void enqueue(queue_t* q, double item) {
    q->arr[q->rear++] = item;
}

double dequeue(queue_t* q) {
    return q->arr[q->front++];
}

int main(int argc, char** argv) {
    // main function owns the allocated heap memory block
    queue_t* q = (queue_t*) malloc(sizeof(queue_t));

    // allocate necessary memory for the queue object
    init(q);

    enqueue(q, 6.5);
    enqueue(q, 1.3);
    enqueue(q, 2.4);

    printf("%f\n", dequeue(q));
    printf("%f\n", dequeue(q));
    printf("%f\n", dequeue(q));

    // queue object destroy(q) frees the allocated resource
    destroy(q);

    // main function frees the allocated memory for the queue object
    free(q);
    return 0;
}