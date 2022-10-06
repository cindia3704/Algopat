/*
    작성자: 김지수
    작성일: 2022/10/06
    백준 -- 여왕벌 (10836번)
*/

#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
#define MAX 701
#define MAXN 1000001
using namespace std; 

int boardSize,totalDays;
int board[MAX][MAX];
int outside[MAX*MAX];

void print(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
           cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void increaseBorder(){
    int idx = 0;
    bool verticalDone = false;
    int y = boardSize-1;
    int x =0;
    while(true){
        if(idx == 2*boardSize-1){
            break;
        }
        board[y][x] = outside[idx];
        if(y==0 && x==0){
            verticalDone= true;
        }
        if(verticalDone){
            x++;
        }else{
            y--;
        }
        idx++;
    }
}

void increaseOthers(){
    for(int i=1;i<boardSize;i++){
        for(int j=1;j<boardSize;j++){
            board[i][j]=board[0][j];
        }
    }
}

void startGame(){
    increaseBorder();
    increaseOthers();    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>totalDays;
    for(int i=0;i<2*boardSize-1;i++){
        outside[i] = 1;
    }

    for(int j=0;j<totalDays;j++){
        int zeroCnt,oneCnt,twoCnt; 
        cin>>zeroCnt>>oneCnt>>twoCnt; 
        for(int i=zeroCnt;i<oneCnt+zeroCnt;i++){
            outside[i]+=1;
        }
        for(int i=zeroCnt+oneCnt;i<oneCnt+zeroCnt+twoCnt;i++){
            outside[i]+=2;
        }
    }
    
    startGame();
    print();
}