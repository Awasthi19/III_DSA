#include <iostream>
using namespace std;

class ArrayBasedStack {
private:
    int *arr;
    int totalSize;
    int topIndex;

public:
    ArrayBasedStack(int size) {
        totalSize = size;
        arr = new int[size];
        topIndex = -1;
    }

    ~ArrayBasedStack() {
        delete[] arr;
    }

    bool push(int element) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return false;
        }
        else{
            arr[++topIndex] = element;
            cout <<"\033[1;32m" <<element << " pushed to stack\n";
            return true;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return -1;
        } else {
            return arr[topIndex--];
        }
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return 0; 
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == totalSize - 1;
    }
};

int main() {
    cout << "\033[1;37mCreating a stack of size 5\n";
    ArrayBasedStack stack(5);
    cout << "\033[1;37mPushing elements to stack:\n";
    stack.push(7);
    stack.push(3);
    stack.push(5);
    stack.push(10);
    stack.push(1);

    cout << "\033[1;37mTrying to push one more element to stack \n";
    stack.push(9);

    cout << "\033[1;34mTop element is " << stack.top() << endl;

    cout << "\033[1;37mPopping elements from the stack:\n";
    cout <<"\033[1;31m" <<stack.pop() << " popped from stack\n";
    cout <<"\033[1;31m" <<stack.pop() << " popped from stack\n";
    cout <<"\033[1;31m" <<stack.pop() << " popped from stack\n";
    cout <<"\033[1;31m" <<stack.pop() << " popped from stack\n";
    cout <<"\033[1;31m" <<stack.pop() << " popped from stack\n";

    cout << "\033[1;37mTrying to pop one more element from stack\n";
    cout << stack.pop() << endl;

    return 0;
}
