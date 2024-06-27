#include<iostream>
using namespace std;

void insertionSort(int *arr, int size) {
    int i, j;
    for (i = 1; i < size; i++) {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int printArray(int *arr, int size){
    int i;
    for (i=0;i<size;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;

}

int main(){

    int arr[] = {10 ,7 ,3 ,5 ,13 ,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
    insertionSort(arr,size);
    printArray(arr,size);

    return 0;
}