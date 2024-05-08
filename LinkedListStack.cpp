#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

class LinkedListStack {
private:
    Node *top;

public:
    LinkedListStack() {
        top = NULL; // Initializing the stack
    }

    bool push(int element) {
        addToHead(top, element);
        cout << "|  Pushed element: " << element << endl;
        return true;
    }

    int pop() {
        if (isEmpty()) {
            cout << "|  Stack Underflow" << endl;
            return -1;
        }
        int poppedValue = top->data;
        removeFromHead(top);
        cout << "|  Popped element: " << poppedValue << endl;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "|  Stack Underflow" << endl;
            return -1;
        }
        int topValue = top->data;
        cout << "|  Top element: " << topValue << endl;
        return topValue;
    }

    bool isEmpty() {
        return top == NULL;
    }
    void printedList(){
        cout<<"--------------------------------------\n";
        cout<<"|    STACK CONTENT    ";
        printList(top);
        cout<<"--------------------------------------\n";
    }

};

int main() {
    LinkedListStack stack;

    cout<<"----------------------------------------------\n";
    // Pushing elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.printedList();

    // Peeking at the top element
    cout<<"--------------------------------------\n";
    cout<<"|  Peeking at the top element"<<endl;
    stack.peek();
    cout<<"--------------------------------------\n";

    // Popping elements from the stack
    cout << "|  Popping..." << endl;
    stack.pop();
    stack.pop();

    stack.printedList();

    stack.pop();
    cout<<"|  Trying to pop an empty stack"<<endl;
    stack.pop(); // Trying to pop an empty stack
    cout<<"----------------------------------------------\n";
    return 0;
}
