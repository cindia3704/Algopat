/*
    작성자: 김지수
    작성일: 2022/08/09
    백준 -- 가운데를 말해요
*/

#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //maxQ=> 오름차순(top이 제일 큼)
    // minQ=> 내림차순 (top이 제일 작음)
    // maxQ의 크기 = minQ의 크기와 같거나 1개만 더 커야함 
    // => maxQ의 top = 가운데 값!! (항상!)
    priority_queue<int> minQ,maxQ; 
    int opCnt;
    cin>>opCnt;
    for(int i=0;i<opCnt;i++){
        int num;
        cin>>num;
        if(maxQ.empty()){
            maxQ.push(num);
        }else if(num>maxQ.top()){
            minQ.push(-num);
            if(minQ.size()==maxQ.size()+1){
                maxQ.push(-minQ.top());
                minQ.pop();
            }
        }else{
            maxQ.push(num);
            if(maxQ.size()>minQ.size()+1){
                minQ.push(-maxQ.top());
                maxQ.pop();
            }
        }
        cout<<maxQ.top()<<'\n';
    }

}