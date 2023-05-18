#include <iostream>
#include "../include/queue.h"

using namespace std;

Queue::Queue() {
    front = 0;
    rear = 0;
}

void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }
    data[rear] = value;
    rear++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int value = data[front];
    front++;
    return value;
}

bool Queue::isEmpty() {
    return front == rear;
}

bool Queue::isFull() {
    return rear == MAX_SIZE;
}

void Queue::print() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i < rear; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
