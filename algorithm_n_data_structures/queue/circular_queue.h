/*
Implement queue using array
*/

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
        Queue() { front = rear = 0; size = 10; Q = new int[size]; }
        Queue(int size) { front = rear = 0; this->size = size; Q = new int[this->size]; }
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
    return (this->rear + 1) % this->size == this->front;
}

void Queue::enqueue(int value) {
    if (this->is_full()) {
        cout << "---Inserting " << value << " but queue is full!---" << endl;
    } else {
        cout << "---Inserting " << value << " to queue!---" << endl;
        this->rear = (this->rear + 1) % this->size;
        this->Q[this->rear] = value;
    }
}

int Queue::dequeue() {
    if (this->is_empty()) {
        cout << "---Trying to dequeue but queue is empty!---" << endl;
        return -1;
    }
    this->front = (this->front + 1) % this->size;
    return this->Q[this->front];
}

void Queue::display() {
    if (this->is_empty()) {
        cout << endl;
        cout << "---Queue is empty, there's nothing to display!---" << endl;
    } else {
        int i = this->front + 1;
        cout << "---[DISPLAY] Queue size: " << this->size << "---" << endl;
        cout << "----------------------------------------------------------------" << endl;
        do {
            cout << this->Q[i] << "\t";
            i = (i + 1) % this->size;
        } while (i != (this->rear + 1) % this->size);
        cout << endl << "----------------------------------------------------------------" << endl;
    }
}

void Queue::destroy() {
    cout << "---Queue has been destroyed!---" << endl;
    this->front = this->rear = -1;
    this->size = 0;
    free(this->Q);
}