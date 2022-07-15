#pragma

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 10;
struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};


int is_queue_empty(struct Queue *q) {
    return q->front == q->rear;
}

int is_queue_full(struct Queue *q) {
    return q->rear == q->size - 1;
}

void create_queue(struct Queue *q, int queue_size) {
    printf("---Creating a queue of size %d---\n", queue_size);
    q->size = queue_size;
    q->front = q->rear = -1;
    q->Q = (int*)malloc(sizeof(int) * (q->size));
    printf("---Queue created---\n");
}

void enqueue(struct Queue *q, int value) {
    if (is_queue_full(q)) {
        printf("---Queue is full, add more space to it now!---\n");
        int new_size = q->size + DEFAULT_SIZE;
        int *temp = (int*) malloc(sizeof(int)*new_size);
        for (int i = q->front + 1; i < q->size; i++) {
            temp[i] = q->Q[i];
        }
        free(q->Q);
        q->Q = temp;
        q->size = new_size;
    }
    q->rear++;
    q->Q[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (is_queue_empty(q)) {
        printf("---Queue is empty---\n");
        return -1;
    }
    q->front++;
    int result = q->Q[q->front];
    return result;
}

void display_queue(struct Queue *q) {
    if (is_queue_empty(q)) {
        printf("---Queue is empty---\n");
    } else {
        printf("---Queue size: %d, Queue front at: %d, Queue rear at: %d---\n", q->size, q->front, q->rear);
        for (int i = q->front + 1; i < q->size; i++) {
            printf("%d ", q->Q[i]);
        }
        printf("\n");
    }
}

void destroy_queue(struct Queue *q) {
    free(q->Q);
    q->size = 0;
    q->front = q->rear = -1;
    printf("---Queue destroyed---\n");
}