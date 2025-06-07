#include "stack_queue.h" // includes the HEADER FILE stack_queue.h
#include <iostream> // includes the input & output stream library 
using namespace std; // to not use std manually

// Static Stack
StaticStack::StaticStack() : top(-1) {} // static stack constructor that initializes the stack by setting the top to -1 (empty)

bool StaticStack::isFull() { // checks if the static stack is full by comparing top to the maximum allowed index
    return top == MAX_SIZE - 1;
}

bool StaticStack::isEmpty() { // checks if the static stack is empty by checking if the top is still at -1 (empty)
    return top == -1;
}

void StaticStack::push(const string& item) { // pushes a new item onto the static stack
    if (isFull()) { // if the static stack is full,
        cout << "  Static Stack is full." << endl; // displays that the static stack is full
        return;  // function exit
    }
    stack[++top] = item; // and if the static stack is not full, increment the top part and assign the new item to that position
    cout << " \033[1m \033[33m" << item << "\033[0m is pushed to the static stack." << endl; // displays that the item is pushed (added) to the top part of the static stack
}

void StaticStack::pop() { // pops (removes) the item (by latest order) onto the static stack
    if (isEmpty()) { // if the static stack is empty,
        cout << "  The Static Stack is \033[31mEMPTY\033[0m." << endl; // displays that the static stack is empty
        return; // function exit
    } // and if the static stack is not empty,
    cout << "  Popped: \033[1m\033[91m" << stack[top--] << "\033[0m\n"; // displays that the item is popped (removed in order of newest to oldest) in the static stack
}

void StaticStack::display() { // displays the static stack 
    if (isEmpty()) { // if the static stack is empty, 
        cout << "  The Static Stack is \033[1m\033[31mEMPTY\033[0m." << endl; // displays that the static stack is empty
        return; // function exit
    } // if the static stack contains an item/elements,
    cout << "  Static Stack Elements (top to bottom): "; // display the contents of the static stack
    for (int i = top; i >= 0; --i)
        cout << stack[i] << (i ? " \033[1m\033[33m->\033[0m " : "\n"); // add an arrow -> for formality and clarity of the stack items displayed
}

// Dynamic Stack
DynamicStack::DynamicStack() : top(nullptr) {} // dynamic stack constructor that initializes the stack by setting top pointer to nullptr (empty stack)

DynamicStack::~DynamicStack() { // dynamic stack destructor that cleans up all the nodes to prevent memory leaks by popping until empty
    while (!isEmpty()) pop(); // keep popping/removing the nodes until the stack is empty
}

bool DynamicStack::isEmpty() { // checks if the dynamic stack is empty
    return top == nullptr; // by testing if top pointer is also the same as nullptr
}

void DynamicStack::push(const string& item) { // pushes (adds) a new item onto the dynamic stack
    StackNode* newNode = new StackNode{item, top}; // creates a new node with item as its data that points to the current top
    top = newNode; // updates the top pointer to the new node, placing it on top
    cout << "  \033[1m\033[33m" << item << "\033[0m is pushed to the dynamic stack." << endl; // displays that the item is pushed to the dynamic stack
}

void DynamicStack::pop() { // pops (removes) an item that is in the dynamic stack
    if (isEmpty()) { // if the dynamic stack is empty,
        cout << "  The dynamic stack is \033[1m\033[31mEMPTY\033[0m." << endl; // displays that the stack is empty
        return; // function exit
    }
    StackNode* temp = top; // temporarily store the current top node
    cout << "  Popped: \033[1m\033[91m" << temp->data << "\033[0m\n"; // displays the data being popped
    top = top->next; // moves the top pointer to the next node (removing the current top)
    delete temp; // frees the memory of the old top node for memory leak prevention 
}

void DynamicStack::display() { // dynamic stack display function
    if (isEmpty()) { // if the dynamic stack is empty,
        cout << "  The dynamic stack is \033[1m\033[31mEMPTY\033[0m." << endl; // displays that the stack is empty
        return; // function exit
    } // if the dynamic stack contains an item/elements,
    cout << "  Dynamic Stack (top to bottom): "; // display its contents
    StackNode* temp = top; // start from the top node
    while (temp) { // traverse through the stack nodes existing
        cout << temp->data << (temp->next ? " \033[1m\033[33m->\033[0m " : "\n");   // display the data of current node (with added -> for clarity)
        temp = temp->next; // move to the next node
    }
}

// Static Queue
// Static Queue

StaticQueue::StaticQueue() : front(-1), rear(-1) {} // initialize the front and rear to -1 (empty queue)

bool StaticQueue::isFull() { // checks if the static queue is full
    return (rear + 1) % MAX_SIZE == front; // return true if the next rear position is equal to front
}

bool StaticQueue::isEmpty() {  // checks if the static queue is empty
    return front == -1; // return true if front is -1 (empty queue)
}

void StaticQueue::enqueue(const string& caller) { // enqueues/adds an item to the static queue
    if (isFull()) { // if the static queue is full
        cout << "  The Static Queue is \033[31mFULL\033[0m." << endl; // displays that the queue is full
        return; // exit function
    }
    if (isEmpty()) front = rear = 0; // if the queue is empty, set front and rear to 0
    else rear = (rear + 1) % MAX_SIZE; // else, move the rear forward (wrap around)
    queue[rear] = caller;  //stores the new item at the rear
    cout << "  " << caller << "\033[0m is \033[1m\033[33mADDED\033[0m to the Static Queue." << endl;  // display message if the item was added to the queue
}

void StaticQueue::dequeue() { // removes an item from the static queue
    if (isEmpty()) { // if the static queue is empty
        cout << "  The Static Queue is \033[1m\033[91mEMPTY\033[0m." << endl;  // displays message that queue is empty
        return; // exit function
    } // if the static queue is not empty,
    cout << "  \033[1m"<< queue[front] << " is \033[31mDEQUEUED\033[37m from the queue.\033[0m" << "\n";  // display the dequeued item/s
    if (front == rear) front = rear = -1;  // if there is only one item, reset the queue to empty
    else front = (front + 1) % MAX_SIZE;  // else, move front forward (wrap around)
}

void StaticQueue::display() {  // display all items in the static queue
    if (isEmpty()) {  // if static queue is empty
        cout << "  Static Queue is \033[1m\033[91mEMPTY\033[0m." << endl; // display that the queue is empty
        return; //exit function
    }
    cout << "  Static Queue: "; // prints the queue label
    int i = front; // start from the front index
    while (true) { // loop through queue items
        cout << queue[i]; // displays the current item
        if (i == rear) break; //stops if item has reached the rear
        cout << " \033[1m\033[33m<-\033[0m "; // displays an arrow between items (for clarity of display)
        i = (i + 1) % MAX_SIZE; // move the index forward circularly
    }
    cout << endl; // new line (for spacing)
}


// Dynamic Queue

DynamicQueue::DynamicQueue() : front(nullptr), rear(nullptr) {}  // constructor for initializing the front and rear to nullptr (empty queue)

DynamicQueue::~DynamicQueue() {  //destructor for clearing memory
    while (!isEmpty()) dequeue(); // keep removing nodes until the dynamic queue becomes empty
}

bool DynamicQueue::isEmpty() { // checks if the dynamic queue is empty
    return front == nullptr; // true if front is nullptr
}

void DynamicQueue::enqueue(const string& caller) {  // void dynamic queue function for enqueuing
    QueueNode* temp = new QueueNode{caller, nullptr};  // creates a new node with caller name

    if (!rear) front = rear = temp; // if the dynamic queue is empty, the front and rear are both the new node
    else { 
        rear->next = temp; // links the current rear to the new node
        rear = temp; // moves the rear to point to the new node
    }

    cout << " \033[1m \033[33m" << caller << " " << "\033[37mis \033[33mADDED\033[37m to the dynamic queue." << endl; // display message if the caller was added to the queue
}

void DynamicQueue::dequeue() { // void dynamic queue function for dequeuing
    if (isEmpty()) { // if the dynamic queue is empty,
        cout << "  The Dynamic Queue is \033[1m\033[91mEMPTY\033[0m." << endl; // display that the dynamic queue is empty
        return; // exit function
    }

    QueueNode* temp = front; // temp points to the node being removed
    cout << "\033[1m\033[37m  " << temp->caller << " is \033[1m\033[91mDEQUEUED\033[37m\033[0m.";  // displays the dequeued name (caller)

    front = front->next; // moves the front to the next node
    if (!front) rear = nullptr; // if the dynamic queue is empty, set rear to nullptr
    delete temp; // frees the memory of the removed node
}

void DynamicQueue::display() { // void function that will display the content/s of the dynamic queue
    if (isEmpty()) { // if the dynamic queue is empty,
        cout << "  Dynamic Queue is \033[1m\033[91mEMPTY\033[0m." << endl; // display that the dynamic queue is empty
        return; //exit function
    }

    cout << "  Dynamic Queue: "; // displays the label for the dynamic queue
    QueueNode* temp = front;  // start from front

    while (temp) {  //loop through nodes
        cout << temp->caller; // display the current caller's name/value
        if (temp->next) // if there is a next node,
            cout << " \033[1m\033[33m<-\033[0m "; // displays an arrow between the two nodes for formality
        temp = temp->next; // moves to next node
    }

    cout << endl; // end line for spacing
}
