#ifndef STACK_QUEUE_H // if STACK_QUEUE_H is not defined,
#define STACK_QUEUE_H // define STACK_QUEUE_H to prevent multiple inclusions
#include <string> // string header file
using namespace std; // to not use std manually

const int MAX_SIZE = 5; // define a constant for the maximum size of the static stack and queue (5 was set to be the maximum)

// Static Stack
class StaticStack {
    
private: // static stack members that is/are protected
    string stack[MAX_SIZE]; // an array that will store stack elements
    int top;  // index of the top element inside the stack
    
public: // static stack operations
    StaticStack(); // static stack constructor (initializes the stack)
    bool isFull(); // checks if the static stack is full
    bool isEmpty(); // checks if the static stack is empty
    void push(const string& item); // push function
    void pop(); // pop function
    void display(); // display the elements of the static stack
};

// Dynamic Stack
struct StackNode { // structure named StackNode
    string data; // data that is held by the node
    StackNode* next; // a pointer to the next node in the stack
};

class DynamicStack { // class named DynamicStack

private: // dynamic stack data members that is/are protected
    StackNode* top; // a pointer to the top node inside the stack
    
public:
    DynamicStack(); // dynamic stack constructor (initializes the stack)
    ~DynamicStack(); // dynamic stack destructor (cleans/frees dynamically allocated memory)
    void push(const string& item); // push function
    void pop(); // pop function
    void display(); // display the elements of the dynamic stack
    bool isEmpty(); // checks if the dynamic stack is empty
};

// Static Queue
class StaticQueue {
    
private: // static queue data members that is/are protected
    string queue[MAX_SIZE]; // an array that will store the elements queued
    int front, rear; // front and rear of the queue
    
public: // static queue operations
    StaticQueue(); // static queue constructor (initializes the stack)
    bool isFull(); // checks if the static stack is full
    bool isEmpty(); // checks if the static stack is empty
    void enqueue(const string& caller); // enqueue function 
    void dequeue(); // dequeue function
    void display(); // display the elements of the static queue
};

// Dynamic Queue
struct QueueNode { // structure named QueueNode
    string caller; // the data that is held by the node
    QueueNode* next;  // a pointer to the next node in the queue
};

class DynamicQueue {
private:
    QueueNode* front; // a pointer to the front of the queue
    QueueNode* rear; // a pointer to the rear/end of the queue
    
// operations   
public:
    DynamicQueue(); // dynamic queue constructor (initializes the stack)
    ~DynamicQueue(); // dynamic queue destructor (cleans/frees dynamically allocated memory)
    void enqueue(const string& caller); // adds an item to the rear of the queue
    void dequeue(); // removes the data inputted at the front of the queue
    void display(); // display the elements of the dynamic queue
    bool isEmpty(); // checks if the dynamic queue is empty
};

#endif  //  closes the #ifndef (for prevention of multiple inclusions)
