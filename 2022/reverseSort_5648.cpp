/*
    작성자: 김지수
    작성일: 2022/06/16
    백준 -- 역원소 정렬 (5648번)
*/

#include <iostream>
#include <string> 
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<long long> pq; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        string num;
        cin>>num;
        reverse(num.begin(),num.end());

        long long inputNum = stoll(num);
        pq.push(-inputNum);
    }

    while(!pq.empty()){
        cout<<pq.top()*-1<<'\n';
        pq.pop();
    }
}