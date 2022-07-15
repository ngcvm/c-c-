#include "queue_c.h"

int main (int argc, char *argv[]) {
    struct Queue q;
    create_queue(&q, 10);
    enqueue(&q, 10);
    enqueue(&q, 22);
    enqueue(&q, 1);
    enqueue(&q, 9);
    enqueue(&q, 3);
    enqueue(&q, 14);
    enqueue(&q, 99);
    enqueue(&q, 33);
    enqueue(&q, 23);
    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 76);
    display_queue(&q);
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    printf("---Dequeue value: %d ---\n", dequeue(&q));
    display_queue(&q);
    destroy_queue(&q);
    return 0;
}
