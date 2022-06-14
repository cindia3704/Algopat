/*
    작성자: 김지수
    작성일: 2022/06/15
    백준 -- 최솟값 찾기 (11003번)
*/

#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std; 

deque<pair<int,int> >dq;
int n,k;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;

        // 오름차순 유지 
        // 덱의 마지막이 현재 숫자보다 크거나 같으면 pop
        while(!dq.empty() && dq.back().second >=num){
            dq.pop_back();
        }

        // 현재값 넣음 
        dq.push_back(make_pair(i,num));

        // Di 구간 유지 위해 구간 밖은 다 제거 
        if(dq.front().first <= i-k){
            dq.pop_front();
        }
        
        // 오름차순 유지하니 맨 앞 = 최소 원소 
        cout<<dq.front().second<<" ";
    }

}