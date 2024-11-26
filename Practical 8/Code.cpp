#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Enqueue operation to add an element to the queue
void enqueue(Node*& rear, int data) {
    Node* newNode = new Node{data, nullptr};
    if (!rear) {
        // Queue is empty
        rear = newNode;
        rear->next = rear; // Make it circular by pointing to itself
    } else {
        newNode->next = rear->next; // Link new node to the front (head)
        rear->next = newNode;       // Update rear's next to the new node
        rear = newNode;             // Move rear to the new node
    }
}

// Dequeue operation to remove an element from the queue
void dequeue(Node*& rear) {
    if (!rear) {
        std::cout << "Queue is empty, cannot dequeue." << std::endl;
        return;
    }
    
    Node* head = rear->next;
    if (rear == head) {
        // Only one node in the queue
        delete head;
        rear = nullptr;
    } else {
        rear->next = head->next; // Link rear to the next node (new front)
        delete head;
    }
}

// Function to print the queue
void printQueue(Node* rear) {
    if (!rear) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    Node* temp = rear->next;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != rear->next);
    std::cout << std::endl;
}

// Function to check if the queue is empty
bool isEmpty(Node* rear) {
    return rear == nullptr;
}

// Function to get the front element of the queue
int front(Node* rear) {
    if (!rear) {
        std::cout << "Queue is empty." << std::endl;
        return -1; // Or an error code
    }
    return rear->next->data; // Front is the node next to rear
}

int main() {
    Node* rear = nullptr;
     if (isEmpty(rear)) {
        std::cout << "Queue is empty.\n" << std::endl;
    }

    enqueue(rear, 10);
    enqueue(rear, 20);
    enqueue(rear, 30);
     if (isEmpty(rear)) {
        std::cout << "Queue is empty." << std::endl;
    }
    else{
        std::cout << "Queue is not empty." << std::endl;
    }
    printQueue(rear); // Output: 10 20 30

    std::cout << "Front element: " << front(rear) << std::endl;

    dequeue(rear);
    printQueue(rear); // Output: 20 30


    return 0;
}
