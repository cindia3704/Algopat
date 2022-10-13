/*
    작성자: 김지수
    작성일: 2022/10/13
    코드트리 -- 바이러스 검사 (3번)
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

vector<int> store;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int storeCnt; 
    int leader,member;
    cin>>storeCnt;
    for(int i=0;i<storeCnt;i++){
        int num;
        cin>>num;
        store.push_back(num);
    }

    cin>>leader>>member;
    long long testerCnt = 0;

    for(int i=0;i<storeCnt;i++){
        int peopleNum = store[i];
        peopleNum = max(0,peopleNum-leader);
        testerCnt+=1; 
        if(peopleNum>0){
            testerCnt +=ceil((double)peopleNum / (double)member);
        }
    }
    cout<<testerCnt;
}