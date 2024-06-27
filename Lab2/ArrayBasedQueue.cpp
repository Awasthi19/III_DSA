#include <iostream>
using namespace std;

class ArrayBasedQueue {
private:
    int *arr;
    int totalSize;
    int frontIndex;
    int rearIndex;

public:
    ArrayBasedQueue(int size) {
        totalSize = size;
        arr = new int[totalSize];
        frontIndex = 0;
        rearIndex= -1;
    }

    ~ArrayBasedQueue() {
        delete[] arr;
    }

    bool enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return false;
        } else {
            arr[++rearIndex] = element;
            cout <<"\033[1;32m" <<element << " enqueued to queue.\n";
            return true;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        } else {
            int x = arr[frontIndex++];
            return x;
        }
    }

    bool isEmpty() {
        return frontIndex > rearIndex; 
    }

    bool isFull() {
        return rearIndex == (totalSize - 1);
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        } else {
            return arr[frontIndex];
        }
    }

    int back() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        } else {
            return arr[rearIndex];
        }
    }
};

int main() {

    cout << "\033[1;37mCreating a queue of size 5\n";
    ArrayBasedQueue queue(5);

    cout << "\033[1;37mEnqueuing elements to queue:\n";
    queue.enqueue(3);
    queue.enqueue(1);
    queue.enqueue(7);
    queue.enqueue(5);
    queue.enqueue(2);
    cout << "\033[1;37mEnqueuing elements to full queue:\n";
    queue.enqueue(6);

    cout << "\033[1;34mFront element of queue: " << queue.front() << endl;
    cout << "\033[1;35mBack element of queue: " << queue.back() << endl;

    cout << "\033[1;37mDequeuing elements from queue:\n";
    cout << "\033[1;31m"<<queue.dequeue() << " dequeued from queue.\n";
    cout << "\033[1;31m"<<queue.dequeue() << " dequeued from queue.\n";
    cout << "\033[1;31m"<<queue.dequeue() << " dequeued from queue.\n";
    cout << "\033[1;31m"<<queue.dequeue() << " dequeued from queue.\n";
    cout << "\033[1;31m"<<queue.dequeue() << " dequeued from queue.\n";
    cout << "\033[1;37mDequeuing elements from empty queue:\n";
    cout << queue.dequeue() << endl;

    
    return 0;
}
