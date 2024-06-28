#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void addtotail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void addtohead(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void deleteNode(int data) {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp != nullptr && temp->data != data) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void insertAfter(int predecessorData, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != predecessorData) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Predecessor not found." << std::endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.addtotail(10);
    dll.addtotail(20);
    dll.addtotail(30);
    dll.display();  // Output: 10 20 30

    dll.addtohead(0);
    dll.display();  // Output: 0 10 20 30

    dll.insertAfter(20, 25);
    dll.display();  // Output: 0 10 20 25 30

    dll.deleteNode(20);
    dll.display();  // Output: 0 10 25 30

    return 0;
}
