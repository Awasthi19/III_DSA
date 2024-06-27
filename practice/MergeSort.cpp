#include<iostream>
using namespace std;


void merge(int*arr,int s, int e){
    int mid= s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int mainArrayIndex=s;
    for (int i=0;i<len1;i++){
        arr1[i]=arr[mainArrayIndex++];
    }
    for (int i=0;i<len2;i++){
        arr2[i]=arr[mainArrayIndex++];
    }
    int i=0,j=0,k=s;
    while(i<len1 && j<len2){
        if (arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        } else {
            arr[k++]=arr2[j++];
        }
    }
    while(i<len1){
        arr[k++]=arr1[i++];
    }
    while(i<len2){
        arr[k++]=arr2[j++];
    }
}

void mergeSort(int *arr,int s, int e){
    if (s>=e){
        return;
    }
    int mid=s+(e-s)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

void printArray(int *arr, int size){
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
    mergeSort(arr,0,size-1);
    printArray(arr,size);

    return 0;

}

