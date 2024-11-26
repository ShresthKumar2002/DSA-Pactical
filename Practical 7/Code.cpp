#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to push an element onto the stack
void push(Node*& head, int data) {
    Node* newNode = new Node{data, head};
    head = newNode;
}

// Function to pop an element from the stack
void pop(Node*& head) {
    if (!head) {
        std::cout << "Stack is empty, cannot pop." << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to print the stack
void printStack(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to check if the stack is empty
bool isEmpty(Node* head) {
    return head == nullptr;
}

// Function to get the top element of the stack
int top(Node* head) {
    if (!head) {
        std::cout << "Stack is empty." << std::endl;
        return -1; // Or an error code
    }
    return head->data;
}

int main() {
    Node* stack = nullptr;

    if (isEmpty(stack)) {
        std::cout << "Stack is empty.\n" << std::endl;
    }

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printStack(stack); // Output: 30 20 10
    if (isEmpty(stack)) {
        std::cout << "Stack is empty." << std::endl;
    }
    else{
        std::cout << "Stack is not empty." << std::endl;
    }

    std::cout << "Top element: " << top(stack) << std::endl;
    return 0;
}
