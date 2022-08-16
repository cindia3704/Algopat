/*
    Merge Sort 알고리즘 구현 
    O(nlogn)
*/

#include <iostream>
using namespace std;
int numList[8]={10,2,50,9,-1,7,4,-29};

void mergeSort(int arr[],int size){
    if(size == 1){
        return;
    }
    int mid = size/2; 
    mergeSort(arr,mid); // 왼쪽 반  
    mergeSort(arr+mid,size-mid);    // 오른쪽 반  

    int *buf = new int[size];
    int i=0, j = mid,k=0;
    // 두개 합치는 대상이 모두 남아있을 경우 
    while(i<mid && j<size){
        buf[k++] = arr[i]<arr[j]? arr[i++]:arr[j++];
    }
    // 외쪽꺼만 남았을때 
    while(i<mid){
        buf[k++] = arr[i++];
    }
    // 오른쪽꺼만 남았을때 
    while(j<size){
        buf[k++] = arr[j++];
    }

    for(int i=0;i<size;i++){
        arr[i] = buf[i];
    }
    delete[] buf;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    mergeSort(numList,8);
    for(int i=0;i<8;i++){
        cout<<numList[i]<<" ";
    }
}

