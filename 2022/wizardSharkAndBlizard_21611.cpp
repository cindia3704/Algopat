/*
    작성자: 김지수
    작성일: 2022/09/15
    백준 -- 마법사 상어와 블리자드 (21611번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
#include <vector>
#define MAX 50 
using namespace std; 

const int dy[4]={0,1,0,-1};
const int dx[4]={-1,0,1,0};

const int dirY[4]={-1,1,0,0};
const int dirX[4]={0,0,-1,1};

int boardSize,commandCnt;
int board[MAX][MAX];
int sharkY,sharkX;
int popCnt[4];
vector<int> marbles;
vector<int> finalMarbles;

void attack(int dir, int dist){
    for(int i=1;i<=dist;i++){
        int nextY = sharkY+dirY[dir]*i;
        int nextX = sharkX + dirX[dir]*i;
        if(nextY<0 || nextY>=boardSize || nextX<0 || nextX>=boardSize || board[nextY][nextX]==0){
            break;
        }
        if(board[nextY][nextX]>0){
            board[nextY][nextX] = 0;
        }
    }
    return;
}

void convertToVec(){
    marbles.clear();
    int ny = sharkY;
    int nx = sharkX;
    int dir = 0;
    int times = 1;
    int cnt =0;

    while(true){
        if(ny == 0 && nx==0){
            break;
        }
        cnt++;
        for(int i=0;i<times;i++){
            int nextY = ny+dy[dir];
            int nextX = nx+dx[dir];
            if(nextY <0 || nextY>=boardSize || nextX <0 || nextX>=boardSize){
                break;
            }
            if(board[nextY][nextX]!=0){
                marbles.push_back(board[nextY][nextX]);
            }
            ny =nextY;
            nx = nextX;
        }
        dir=(dir+1)%4;
        if(cnt%2==0 && times!=boardSize-1){
            times++;
        }
    }
}

void popMarbles(){
    vector<int> temp; 
    bool popExist = false;
    while(!marbles.empty()){
        int num = marbles[0];
        int numCnt =1; 
        for(int i=1;i<marbles.size();i++){
            if(marbles[i]==num){
                numCnt++;
            }else{
                if(numCnt>=4){
                    popExist = true;
                    popCnt[num]+=numCnt;
                }else{
                    for(int j=0;j<numCnt;j++){
                        temp.push_back(num);
                    }
                }
                numCnt = 1;
                num = marbles[i];
            }
        }
        if(numCnt>=4){
            popExist = true;
            popCnt[num]+=numCnt;
        }else{
            for(int j=0;j<numCnt;j++){
                temp.push_back(num);
            }
        }
        marbles = temp;
        temp.clear();
        if(!popExist || marbles.empty()){
            break;
        }
        popExist = false;
    }
}

void finalizeMarble(){
    finalMarbles.clear();
    int idx = 0;
    while(idx<marbles.size()){
        int now = marbles[idx];
        int nowCnt = 1;
        while(true){
            if(idx+1>=marbles.size()){
                finalMarbles.push_back(nowCnt);
                finalMarbles.push_back(now);
                break;
            }
            if(marbles[idx+1]==now){
                nowCnt++;
            }else{
                finalMarbles.push_back(nowCnt);
                finalMarbles.push_back(now);
                break;
            }
            idx++;
            if(idx>=marbles.size()){
                break;
            }
        }

        idx++;
    }
}   

void convertToBoard(){
    int ny = sharkY;
    int nx = sharkX;
    int dir = 0;
    int times = 1;
    int cnt =0;
    int marbIdx = 0;

    while(marbIdx<finalMarbles.size()){
        if(ny == 0 && nx==0){
            break;
        }
        cnt++;
        for(int i=0;i<times;i++){
            int nextY = ny+dy[dir];
            int nextX = nx+dx[dir];
            if(nextY <0 || nextY>=boardSize || nextX <0 || nextX>=boardSize){
                break;
            }
            board[nextY][nextX]=finalMarbles[marbIdx++];            
            ny =nextY;
            nx = nextX;
            if(marbIdx>=finalMarbles.size()){
                break;
            }
        }
        dir=(dir+1)%4;
        if(cnt%2==0 && times!=boardSize-1){
            times++;
        }
    }
}

void startGame(int dir,int dist){
    attack(dir,dist);
    convertToVec();

    memset(board,0,sizeof(board));
    if(!marbles.empty()){
        popMarbles(); 
        finalizeMarble();
        convertToBoard();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>commandCnt;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }
    sharkY = boardSize/2;
    sharkX = boardSize/2; 
    for(int i=0;i<commandCnt;i++){
        int dir,dist; 
        cin>>dir>>dist;
        startGame(dir-1,dist);
    }
    cout<<popCnt[1]+(2*popCnt[2])+(3*popCnt[3]);
}