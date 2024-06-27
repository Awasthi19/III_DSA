#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr , int low , int high){

    int pi = arr[high];
    int i=low-1;
    for (int j=low ; j<high;j++){
        if (arr[j]<pi){
            i++;
            swap(&arr[i],&arr[j]);
        } 
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void QuickSort(int *arr, int low , int high){
    if (low<high){
        int pi=partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }

}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 8, 6, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
