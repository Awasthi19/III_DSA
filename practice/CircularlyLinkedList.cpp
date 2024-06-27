#include <iostream>

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail; // tail->next is the head

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void addToHead(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (tail == nullptr) {
            // If the list is empty, new node points to itself
            newNode->next = newNode;
            tail = newNode; // Since it's the only node, it is both head and tail
        } else {
            newNode->next = tail->next; // New node points to the current head
            tail->next = newNode; // Tail points to the new node
        }
    }

    void removeFromHead() {
        if (tail == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* temp = tail->next; // Head
        tail->next = temp->next; // Tail points to the next node
        delete temp;
    }

    void addToTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (tail == nullptr) {
            
            newNode->next = newNode;
            tail = newNode; 
        } else {
            newNode->next = tail->next;
            tail->next = newNode; 
            tail = newNode; // only difference between addToHead and addToTail
        }
    }



    void printList() {
        if (tail == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* temp = tail->next; // Start from the head

        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);

        std::cout << std::endl;
    }
};

class Stack {
private:
    CircularLinkedList list;

public:
    void push(int value) {
        list.addToHead(value);
    }

    void pop() {
        list.removeFromHead();
    }

    void printStack() {
        list.printList();
    }
};

class Queue {
private:
    CircularLinkedList list;

public:
    void enqueue(int value) {
        list.addToTail(value);
    }

    void dequeue() {
        list.removeFromHead();
    }

    void printQueue() {
        list.printList();
    }
};

