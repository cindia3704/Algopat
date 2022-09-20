/*
    작성자: 김지수
    작성일: 2022/09/20
    백준 -- 용액 합성하기 (14921 번)
*/

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std; 
int arr[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arrSize; 
    cin>>arrSize;
    for(int i=0;i<arrSize;i++){
        cin>>arr[i];
    }

    int sum = 0;
    int right = arrSize-1; 
    int left = 0;
    int diff = 0x7fffffff;
    while(left<right){
        if(left==0&&right==arrSize-1){
            sum = arr[left]+arr[right];
        }
        if(abs(sum)<abs(diff)){
            diff = sum;
        }
        if(sum<=0){
            sum-=arr[left];
            left++;
            sum+=arr[left];
        }else{
            sum-=arr[right];
            right--;
            sum+=arr[right];
        }
    }
    cout<<diff;
}