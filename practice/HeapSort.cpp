#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr,int n, int i){
    int largest =i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if (right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}

void buildHeap(int *arr,int n){
    for (int i=n/2;i>=0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int *arr,int n){

    while(n>0){
        swap(&arr[0],&arr[n]);
        n--;
        heapify(arr,n,0);

    }
}

void printArray(int *arr, int size){
    int i;
    for (i=0;i<size;i++){
        std::cout << arr[i] <<" ";
    }
    std::cout << std::endl;

}

int main(){
    int arr[] = {10 ,7 ,3 ,5 ,13 ,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,size);
    buildHeap(arr,size-1);
    printArray(arr,size);
    heapSort(arr,size-1);
    printArray(arr,size);



    return 0;
}