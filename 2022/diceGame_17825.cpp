/*
    작성자: 김지수
    작성일: 2022/10/05
    백준 -- 주사위 윷놀이 (17825번)
*/

#include <iostream>
#include <cstring> 
#include <algorithm>
using namespace std;

int graph[33][5]={
    {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9},
    {21,22,23,24,30},{7,8,9,10,11},{8,9,10,11,12},{9,10,11,12,13},{10,11,12,13,14},
    {25,26,24,30,31},{12,13,14,15,16},{13,14,15,16,17},{14,15,16,17,18},{15,16,17,18,19},
    {27,28,29,24,30},{17,18,19,20,32},{18,19,20,32,32},{19,20,32,32,32},{20,32,32,32,32},{20,32,32,32,32},
    {22,23,24,30,31},{23,24,30,31,20},{24,30,31,20,32},{30,31,20,32,32},{26,24,30,31,20},{24,30,31,20,32},
    {28,29,24,30,31},{29,24,30,31,20},{24,30,31,20,32},{31,20,32,32,32},{20,32,32,32,32},{32,32,32,32,32}
};
int score[33]={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,25,22,24,28,27,26,30,35,0};

int ans = 0;
int rollCnt[10];
int pick[10];
bool haveHorse[33];
int pos[4];


void calculateScore(){
    memset(pos,0,sizeof(pos));
    int sum =0;
    for(int i=0;i<10;i++){
        int nowHorse = pick[i];
        int nowPos = pos[nowHorse];
        int nowRoll = rollCnt[i];
        int nextPos = graph[nowPos][nowRoll-1];
        if(nowPos==32){
            continue;
        }
        if(haveHorse[nextPos] && nextPos!=32){
            return;
        }else{
            if(nowPos!=0){
                haveHorse[nowPos] = false;
            }
            haveHorse[nextPos] = true;
            sum+=score[nextPos];
            pos[nowHorse] = nextPos;
        }
    }
    ans = max(ans,sum);
}

void makeComb(int pickCount){
    if(pickCount == 10){
        memset(haveHorse,false,sizeof(haveHorse));
        calculateScore();
        return;
    }
    for(int i=0;i<4;i++){
        pick[pickCount] = i;
        makeComb(pickCount+1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0;i<10;i++){
        cin>>rollCnt[i];
    }

    makeComb(0);
    cout<<ans;
}