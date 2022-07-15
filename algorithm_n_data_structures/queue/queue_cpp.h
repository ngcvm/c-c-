#pragma

#include <iostream>
using namespace std;

#define DEFAULT_SIZE 10;

class Queue {
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue() { front = rear = -1; size = 10; Q = new int[size]; }
        Queue(int size) { front = rear = -1; this->size = size; Q = new int[this->size]; }
        int is_empty();
        int is_full();
        void enqueue(int value);
        int dequeue();
        void display();
        void destroy();
};

int Queue::is_empty() {
    return this->front == this->rear;
}

int Queue::is_full() {
    return this->rear == this->size - 1;
}

void Queue::enqueue(int value) {
    if (this->is_full()) {
        cout << "---Queue is full, extending the size!---" << endl;
        int new_size = this->size + DEFAULT_SIZE;
        int *new_q = (int*)malloc(sizeof(int) * new_size);
        for (int i = this->front; i < this->size; i++) {
            new_q[i] = this->Q[i];
        }
        free(this->Q);
        this->Q = new_q;
        this->size = new_size;
    }
    this->rear++;
    this->Q[this->rear] = value;
}

int Queue::dequeue() {
    if (this->is_empty()) {
        cout << "---Queue is empty!---" << endl;
        return -1;
    }
    this->front++;
    return this->Q[this->front];
}

void Queue::display() {
    if (this->is_empty()) {
        cout << endl;
        cout << "---Queue is empty!---" << endl;
    } else {
        for (int i = this->front; i < this->size; i++) {
            cout << this->Q[i] << "\t";
        }
        cout << endl;
    }
}

void Queue::destroy() {
    cout << "---Queue has been destroyed!---";
    this->front = this->rear = -1;
    this->size = 0;
    free(this->Q);
}