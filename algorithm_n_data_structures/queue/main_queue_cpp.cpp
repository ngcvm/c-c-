#include "queue_cpp.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    Queue *q = new Queue(5);
    q->enqueue(10);
    q->enqueue(22);
    q->enqueue(1);
    q->enqueue(9);
    q->enqueue(3);
    q->enqueue(14);
    q->enqueue(99); 
    q->enqueue(33);
    q->enqueue(23);
    q->enqueue(32);
    q->enqueue(11);
    q->enqueue(76);
    q->enqueue(20);
    q->display();
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    cout << "---Dequeue value: " << q->dequeue() << "---" << endl;
    q->display();
    q->destroy();
    return 0;
}
