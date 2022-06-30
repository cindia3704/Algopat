/*
    작성자: 김지수
    작성일: 2022/06/30
    백준 -- 구간 합 구하기 4 (11659번)
*/

#include <iostream>
#define MAX 100002
using namespace std;

int numList[MAX];
int rangeSum[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int numCount,rangeCount; 
    cin>>numCount>>rangeCount;
    for(int i=0;i<numCount;i++){
        cin>>numList[i];
    }
    for(int i=1;i<=numCount;i++){
        rangeSum[i] = rangeSum[i-1]+numList[i-1];
    }

    for(int i=0;i<rangeCount;i++){
        int start,end;
        cin>>start>>end;
        cout<<rangeSum[end]-rangeSum[start-1]<<'\n';
    }
}