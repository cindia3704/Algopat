/*
    작성자: 김지수
    작성일: 2022/07/20
    백준 -- 시험 감독 (13458번)
*/

#include <iostream>
#include <math.h>
#define MAX 1000001
using namespace std;

int peopleNum[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int placeNum;
    cin>>placeNum;
    for(int i=0;i<placeNum;i++){
        cin>>peopleNum[i];
    }
    int mainNum,subNum;
    cin>>mainNum>>subNum;

    long long totalCount = 0;
    for(int i=0;i<placeNum;i++){
        totalCount+=1;
        int peopleLeft = peopleNum[i] - mainNum;
        if(peopleLeft>0){
           int temp=ceil((float)peopleLeft / float(subNum));
            if(temp >0){
                totalCount+=temp;
            }
        }
    }
    cout<<totalCount;
}