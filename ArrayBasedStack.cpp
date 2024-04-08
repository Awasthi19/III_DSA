#include <iostream>
using namespace std;

class ArrayBasedStack {
private:
    int *stack;
    int totalSize;
    int currentSize;
public:
    ArrayBasedStack(int size) {
        totalSize = size;
        stack = new int[size];
        currentSize = 0;
    }

    void push(int value) {
        if (currentSize == totalSize) {
            cout << "Stack is full" << endl;
            return;
        }
        stack[currentSize] = value;
        currentSize++;
    }

    void pop() {
        if (currentSize == 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        currentSize--;
    }

    int top() {
        if (currentSize == 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[currentSize - 1];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    int size() {
        return currentSize;
    }
};