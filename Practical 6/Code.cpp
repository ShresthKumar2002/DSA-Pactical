#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node{data, head};
    if (!head) {
        head = newNode;
        head->next = head; // Point to itself to make it circular
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void deleteNode(Node*& head, int key) {
    if (!head) return;

    Node* temp = head;
    Node* prev = nullptr;

    do {
        if (temp->data == key) {
            if (prev == nullptr) {
                // Deleting the head node
                Node* tail = head;
                while (tail->next != head) {
                    tail = tail->next;
                }
                tail->next = head->next;
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
                if (head == tail) head = nullptr; // Single node case
            } else {
                prev->next = temp->next;
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    std::cout << "Circular Linked List: ";
    printList(head);

    deleteNode(head, 3);

    std::cout << "List after deleting 3: ";
    printList(head);

    deleteNode(head, 1);

    std::cout << "List after deleting 1: ";
    printList(head);

    return 0;
}
