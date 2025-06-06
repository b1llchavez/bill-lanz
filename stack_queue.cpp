// stack_queue.cpp
#include "stack_queue.h"
#include <iostream>
using namespace std;

// Static Stack
StaticStack::StaticStack() : top(-1) {}

bool StaticStack::isFull() {
    return top == MAX_SIZE - 1;
}

bool StaticStack::isEmpty() {
    return top == -1;
}

void StaticStack::push(const string& item) {
    if (isFull()) {
        cout << "  Static Stack is full.\n";
        return;
    }
    stack[++top] = item;
    cout << " \033[1m \033[33m" << item << "\033[0m is pushed to the static stack." << endl;
}

void StaticStack::pop() {
    if (isEmpty()) {
        cout << "  The Static Stack is \033[31mEMPTY\033[0m." << endl;
        return;
    }
    cout << "  Popped: \033[1m\033[91m" << stack[top--] << "\033[0m\n";
}

void StaticStack::display() {
    if (isEmpty()) {
        cout << "  The Static Stack is \033[1m\033[31mEMPTY\033[0m." << endl;
        return;
    }
    cout << "  Static Stack Elements (top to bottom): ";
    for (int i = top; i >= 0; --i)
        cout << stack[i] << (i ? " \033[1m\033[33m->\033[0m " : "\n");
}

// Dynamic Stack
DynamicStack::DynamicStack() : top(nullptr) {}

DynamicStack::~DynamicStack() {
    while (!isEmpty()) pop();
}

bool DynamicStack::isEmpty() {
    return top == nullptr;
}

void DynamicStack::push(const string& item) {
    StackNode* newNode = new StackNode{item, top};
    top = newNode;
    cout << "  \033[1m\033[33m" << item << "\033[0m is pushed to the dynamic stack." << endl;
}

void DynamicStack::pop() {
    if (isEmpty()) {
        cout << "  The dynamic stack is \033[1m\033[31mEMPTY\033[0m." << endl;
        return;
    }
    StackNode* temp = top;
    cout << "  Popped: \033[1m\033[91m" << temp->data << "\033[0m\n";
    top = top->next;
    delete temp;
}

void DynamicStack::display() {
    if (isEmpty()) {
        cout << "  The dynamic stack is \033[1m\033[31mEMPTY\033[0m." << endl;
        return;
    }
    cout << "  Dynamic Stack (top to bottom): ";
    StackNode* temp = top;
    while (temp) {
        cout << temp->data << (temp->next ? " \033[1m\033[33m->\033[0m " : "\n");
        temp = temp->next;
    }
}

// Static Queue
StaticQueue::StaticQueue() : front(-1), rear(-1) {}

bool StaticQueue::isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

bool StaticQueue::isEmpty() {
    return front == -1;
}

void StaticQueue::enqueue(const string& caller) {
    if (isFull()) {
        cout << "  The Static Queue is \033[31mFULL\033[0m." << endl;
        return;
    }
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % MAX_SIZE;
    queue[rear] = caller;
    cout << "  " << caller << "\033[0m is \033[1m\033[33mADDED\033[0m to the Static Queue." << endl;
}

void StaticQueue::dequeue() {
    if (isEmpty()) {
        cout << "  The Static Queue is \033[1m\033[91mEMPTY\033[0m." << endl;
        return;
    }
    cout << "  \033[1m"<< queue[front] << " is \033[31mDEQUEUED\033[37m from the queue.\033[0m" << "\n";
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX_SIZE;
}

void StaticQueue::display() {
    if (isEmpty()) {
        cout << "  Static Queue is \033[1m\033[91mEMPTY\033[0m." << endl;
        return;
    }
    cout << "  Static Queue: ";
    int i = front;
    while (true) {
        cout << queue[i];
        if (i == rear) break;
        cout << " \033[1m\033[33m<-\033[0m ";
        i = (i + 1) % MAX_SIZE;
    }
    cout << "\n";
}

// Dynamic Queue
DynamicQueue::DynamicQueue() : front(nullptr), rear(nullptr) {}

DynamicQueue::~DynamicQueue() {
    while (!isEmpty()) dequeue();
}

bool DynamicQueue::isEmpty() {
    return front == nullptr;
}

void DynamicQueue::enqueue(const string& caller) {
    QueueNode* temp = new QueueNode{caller, nullptr};
    if (!rear) front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
    cout << " \033[1m \033[33m" << caller << " " << "\033[37mis \033[33mADDED\033[37m to the dynamic queue." << endl;
}

void DynamicQueue::dequeue() {
    if (isEmpty()) {
        cout << "  The Dynamic Queue is \033[1m\033[91mEMPTY\033[0m." << endl;
        return;
    }
    QueueNode* temp = front;
    cout << "\033[1m\033[37m  " << temp->caller << " is \033[1m\033[91mDEQUEUED\033[37m\033[0m.";
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void DynamicQueue::display() {
    if (isEmpty()) {
        cout << "  Dynamic Queue is \033[1m\033[91mEMPTY\033[0m." << endl;
        return;
    }
    cout << "  Dynamic Queue: ";
    QueueNode* temp = front;
    while (temp) {
        cout << temp->caller;
        if (temp->next) cout << " \033[1m\033[33m<-\033[0m ";
        temp = temp->next;
    }
    cout << "\n";
}
