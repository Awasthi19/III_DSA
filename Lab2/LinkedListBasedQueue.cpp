#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

class LinkedListBasedQueue {
private:
    Node *front;
    Node *rear;
public:
    LinkedListBasedQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int element) {
        addToTail(front, rear, element);
        cout << "|  Enqueued element: " << element << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "|  Queue Underflow" << endl;
            return -1;
        }
        int dequeuedValue = front->data;
        removeFromHead(front);
        cout << "|  Dequeued element: " << dequeuedValue << endl;
        return dequeuedValue;
    }

    int peekFront() {
        if (isEmpty()) {
            cout << "|  Queue Underflow" << endl;
            return -1;
        }
        int frontValue = front->data;
        cout << "|  Front element: " << frontValue << endl;
        return frontValue;
    }

    int peekBack() {
        if (isEmpty()) {
            cout << "|  Queue Underflow" << endl;
            return -1;
        }
        int frontValue = rear->data;
        cout << "|  Front element: " << frontValue << endl;
        return frontValue;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void printedList() {
        cout << "--------------------------------------\n";
        cout << "|    QUEUE CONTENT    ";
        printList(front);
        cout << "--------------------------------------\n";
    }
    
};

int main(){

    LinkedListBasedQueue queue;

    cout << "----------------------------------------------\n";
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.printedList();

    cout << "--------------------------------------\n";
    cout << "|  Peeking at the front element" << endl;
    queue.peekFront();
    cout << "--------------------------------------\n";

    cout << "--------------------------------------\n";
    cout << "|  Peeking at the back element" << endl;
    queue.peekBack();
    cout << "--------------------------------------\n";

    cout << "|  Dequeuing..." << endl;
    queue.dequeue();
    queue.dequeue();

    queue.printedList();
    queue.dequeue();
    cout << "|  Trying to dequeue an empty queue" << endl;
    queue.dequeue();
    cout << "----------------------------------------------\n";

    return 0;
}