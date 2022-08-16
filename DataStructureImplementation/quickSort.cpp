/*
    Merge Sort 알고리즘 구현 
    O(nlogn)
*/

#include <iostream>
using namespace std; 
int numList[8]={4,100,-1,8,2,7,-4,20};

void quickSort(int arr[],int left, int right){
    if(left<right){
        int pivot = left, i=left+1,j=right;
        while(i<=j){
            while(arr[pivot]>=arr[i])  i++;
            while(arr[pivot]<arr[j])   j--; 
            if(i<j){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i] = temp; 
            }
        }

        int temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quickSort(arr,left,j-1);
        quickSort(arr,j+1,right);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    quickSort(numList,0,7);
    for(int i=0;i<8;i++){
        cout<<numList[i]<<" ";
    }
}