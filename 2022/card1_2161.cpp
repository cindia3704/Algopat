/*
    작성자: 김지수
    작성일: 2022/09/22
    백준 -- 카드 1 (2161번)
*/

#include <iostream>
#include <deque>
using namespace std; 
deque<int> dq;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }   

    while(dq.size()>1){
        cout<<dq.front()<<" ";
        dq.pop_front();
        int temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
    }
    cout<<dq.front();
}