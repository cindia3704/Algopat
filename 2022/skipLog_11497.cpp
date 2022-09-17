/*
    작성자: 김지수
    작성일: 2022/09/17
    백준 -- 통나무 건너뛰기 (11497번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 10001
using namespace std;
int arrSize; 
int arr[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; 
    cin>>tc;
    while(tc--){
        cin>>arrSize;
        priority_queue<int> q; 
        for(int i=0;i<arrSize;i++){
            int num;
            cin>>num;
            q.push(num);
        }
        int idxFront = 0;
        int idxBack = arrSize-1;
        int cnt=1;
        for(int i=0;i<arrSize;i++){
            int num = q.top();
            q.pop();
            if(cnt%2==1){
                arr[idxFront++] = num;
            }else{
                arr[idxBack--]=num;
            }
            cnt++;
        }
        int maxDiff = 0;
        for(int i=0;i<arrSize;i++){
            int tempDiff = abs(arr[i]-arr[(i+1)%arrSize]);
            maxDiff = max(maxDiff,tempDiff);
        }
        cout<<maxDiff<<'\n';
    }
}