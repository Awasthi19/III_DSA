#include <iostream>
#include <vector>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(std::vector<int>& arr, int n, int i){
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

void reheapUp(std::vector<int>& arr, int n, int i){
    int parent = (i-1)/2;
    while (i>0){
        if ( arr[parent]<arr[i]){
            swap(&arr[parent],&arr[i]);
            i = parent;
        }
        else {
            return;
        }
    }
}

void buildHeap(std::vector<int>& arr, int n){
    for (int i=n/2;i>=0;i--){
        heapify(arr,n,i);
    }
}

void printArray(const std::vector<int>& arr){
    for (int num : arr){
        std::cout << num <<" ";
    }
    std::cout << std::endl;
}

void insertIntoHeap(std::vector<int>& arr, int newValue){
    arr.push_back(newValue);
    int index = arr.size()-1 ;
    int parent;

    // reheap up
    while (index>0){
        parent= (index-1)/2;
        if (arr[parent]<arr[index]){
            swap(&arr[parent],&arr[index]);
            index = parent;
        }
        else {
            return;
        }
        
    }
}

void deletionIntoHeap(std::vector<int>& arr, int value){
    int i=0;
    int n= arr.size()-1;
    while (i<n && arr[i]!=value){
        i++;
    }
    swap(&arr[i],&arr[n]);
    arr.pop_back();
    heapify(arr,n,i);
}

int main(){
    std::vector<int> arr = {10 ,7 ,3 ,5 ,13 ,1};

    printArray(arr);
    buildHeap(arr,arr.size());
    printArray(arr);

    insertIntoHeap(arr, 9);
    printArray(arr);

    deletionIntoHeap(arr,13);
    printArray(arr);

    return 0;
}
