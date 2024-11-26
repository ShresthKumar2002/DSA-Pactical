#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void deleteNode(Node*& head, int key) 
{ 
    Node* temp = head; Node* prev = nullptr; 
    if (temp != nullptr && temp->data == key) 
    { head = temp->next; delete temp; return; } 
    while (temp != nullptr && temp->data != key) 
    { prev = temp; temp = temp->next; } 
    if (temp == nullptr) return; prev->next = temp->next; 
    delete temp; 
} 
int main() 
{
     Node* head = nullptr;
     insert(head, 1); insert(head, 2); insert(head, 3); insert(head, 4); insert(head, 5); 
     std::cout << "Original Linked List: "; 
     printList(head); 
     deleteNode(head, 3); 
     std::cout << "Linked List after deleting 3: "; printList(head); 
     return 0; 
}