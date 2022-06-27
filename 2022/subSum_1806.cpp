/*
    작성자: 김지수
    작성일: 2022/06/27
    백준 -- 부분합 (1806번)
*/

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std; 

int arr[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,s; 
    cin>>n>>s; 
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int en=0;
    int sum=0;
    int minDiff = 0x7fffffff;  // 큰 값으로 초기화 
    for(int st=0;st<n;st++){
        // 합이 s 미만이고, en이 배열 범위 안에 있을때 
        while(sum<s && en<n){
            sum+=arr[en];   // 현재 en위치를 더하고 en 증가 
            en++;
        }
        if(sum>=s){ // 합이 s 이상일 경우 
            if(minDiff>en-st){  // 최소 구간 찾으면 업데이트 
                minDiff = en-st;
            }
        }
        sum-=arr[st];   // 시작위치 하나 옮길때 마다 합에서 빼줌 
    }
    // 못찾으면 0 출력 
    if(minDiff == 0x7fffffff){
        cout<<0;
    }else{
        cout<<minDiff;
    }
}