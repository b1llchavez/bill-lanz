// stack_queue.h
#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H
#include <string>

const int MAX_SIZE = 5;

// Static Stack
class StaticStack {
private:
    std::string stack[MAX_SIZE];
    int top;
public:
    StaticStack();
    bool isFull();
    bool isEmpty();
    void push(const std::string& item);
    void pop();
    void display();
};

// Dynamic Stack
struct StackNode {
    std::string data;
    StackNode* next;
};

class DynamicStack {
private:
    StackNode* top;
public:
    DynamicStack();
    ~DynamicStack();
    void push(const std::string& item);
    void pop();
    void display();
    bool isEmpty();
};

// Static Queue
class StaticQueue {
private:
    std::string queue[MAX_SIZE];
    int front, rear;
public:
    StaticQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(const std::string& caller);
    void dequeue();
    void display();
};

// Dynamic Queue
struct QueueNode {
    std::string caller;
    QueueNode* next;
};

class DynamicQueue {
private:
    QueueNode* front;
    QueueNode* rear;
public:
    DynamicQueue();
    ~DynamicQueue();
    void enqueue(const std::string& caller);
    void dequeue();
    void display();
    bool isEmpty();
};

#endif