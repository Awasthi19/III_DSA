#include <iostream>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n) {
    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<=n;j++) {
            if ( arr[j] < arr[minIndex] ) {
                minIndex=j;
            }
            
        }
        if ( minIndex!= i) {
            swap(&arr[minIndex], &arr[i]);
        }
    }
    
}

int main() {
    int arr[] = {5, 2, 8, 12, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, size);

    selectionSort(arr, size-1);

    std::cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}