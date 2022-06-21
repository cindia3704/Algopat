/*
    작성자: 김지수
    작성일: 2022/06/22
    백준 -- 좌표 압축 (18870번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std; 
int arr[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> lists1; // 더미 -> 중복제거전
    vector<int> lists2; // 중복제거 후 
    for(int i=0;i<n;i++){
        cin>>arr[i];    // 출력순서 유지 위해 필요
        lists1.push_back(arr[i]);  
    }
    sort(lists1.begin(),lists1.end());  // 정렬 -> 이렇게 하면 중복제거 할 수 있고, 추후 정렬 안해도 됨 

    for(int i=0;i<n;i++){
        if(i==0 || lists1[i-1] !=lists1[i]){    // 중복제거 
            lists2.push_back(lists1[i]);
        }
    }

    for(int i=0;i<n;i++){   // 이분탐색
        cout<<lower_bound(lists2.begin(),lists2.end(),arr[i]) - lists2.begin()<<" ";
    }
}