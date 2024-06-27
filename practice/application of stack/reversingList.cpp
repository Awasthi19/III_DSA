#include <iostream>
#include <stack>
using namespace std;

// Function to reverse the list using a stack
void reverseList(int arr[], int size) {
    stack<int> s;

    // Push all the elements onto the stack
    for (int i = 0; i < size; i++) {
        s.push(arr[i]);
    }

    // Pop the elements from the stack and update the array
    for (int i = 0; i < size; i++) {
        arr[i] = s.top();
        s.pop();
    }
}

// Function to print the list
void printList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    // Create a sample array
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original list: ";
    printList(arr, size);

    // Reverse the list
    reverseList(arr, size);

    cout << "Reversed list: ";
    printList(arr, size);

    return 0;
}
