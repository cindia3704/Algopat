/*
    작성자: 김지수
    작성일: 2022/06/27
    백준 -- 수 고르기 (2230번)
*/

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std; 
int arr[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; 
    cin>>n>>m; 

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    int en = 0;
    int minNum = 0x7fffffff;
    for(int st=0;st<n;st++){
        // 차이가 m 보다 작을때 계속 en ++ 
        while(en<n && arr[en]-arr[st]<m){
            en++;
        }
        //en 이 배열 범위 넘어가면 그만 
        if(en==n)   break;
        // 찾은 차이가 현재 답보다 작으면 업데이트 
        if(arr[en]-arr[st] < minNum){
            minNum = arr[en]-arr[st];
        }
    }
    cout<<minNum;
    
}