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
        cout << "Static Stack is full.\n";
        return;
    }
    stack[++top] = item;
    cout << item << " pushed to static stack.\n";
}

void StaticStack::pop() {
    if (isEmpty()) {
        cout << "Static Stack is empty.\n";
        return;
    }
    cout << "Popped: " << stack[top--] << "\n";
}

void StaticStack::display() {
    if (isEmpty()) {
        cout << "Static Stack is empty.\n";
        return;
    }
    cout << "Static Stack (top to bottom): ";
    for (int i = top; i >= 0; --i)
        cout << stack[i] << (i ? " -> " : "\n");
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
    cout << item << " pushed to dynamic stack.\n";
}

void DynamicStack::pop() {
    if (isEmpty()) {
        cout << "Dynamic Stack is empty.\n";
        return;
    }
    StackNode* temp = top;
    cout << "Popped: " << temp->data << "\n";
    top = top->next;
    delete temp;
}

void DynamicStack::display() {
    if (isEmpty()) {
        cout << "Dynamic Stack is empty.\n";
        return;
    }
    cout << "Dynamic Stack (top to bottom): ";
    StackNode* temp = top;
    while (temp) {
        cout << temp->data << (temp->next ? " -> " : "\n");
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
        cout << "Static Queue is full.\n";
        return;
    }
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % MAX_SIZE;
    queue[rear] = caller;
    cout << caller << " added to static queue.\n";
}

void StaticQueue::dequeue() {
    if (isEmpty()) {
        cout << "Static Queue is empty.\n";
        return;
    }
    cout << "Handling: " << queue[front] << "\n";
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX_SIZE;
}

void StaticQueue::display() {
    if (isEmpty()) {
        cout << "Static Queue is empty.\n";
        return;
    }
    cout << "Static Queue: ";
    int i = front;
    while (true) {
        cout << queue[i];
        if (i == rear) break;
        cout << " <- ";
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
    cout << caller << " added to dynamic queue.\n";
}

void DynamicQueue::dequeue() {
    if (isEmpty()) {
        cout << "Dynamic Queue is empty.\n";
        return;
    }
    QueueNode* temp = front;
    cout << "Handling: " << temp->caller << "\n";
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void DynamicQueue::display() {
    if (isEmpty()) {
        cout << "Dynamic Queue is empty.\n";
        return;
    }
    cout << "Dynamic Queue: ";
    QueueNode* temp = front;
    while (temp) {
        cout << temp->caller;
        if (temp->next) cout << " <- ";
        temp = temp->next;
    }
    cout << "\n";
}