/*
    작성자: 김지수
    작성일: 2022/10/15
    백준 -- 마법사 상어와 토네이도 (20057번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 500
using namespace std; 

const int dy[4] = {0,1,0,-1};
const int dx[4] = {-1,0,1,0};

const int dustY[10]={-1,1,-1,1,-2,2,-1,1,0,0};
const int dustX[10]={1,1,0,0,0,0,-1,-1,-2,-1};
const double dustPer[10]={0.01,0.01,0.07,0.07,0.02,0.02,0.1,0.1,0.05,0};

int boardSize; 
int dustOutAmt = 0;
int board[MAX][MAX]; 

void print(){
    cout<<"\n==== BOARD"<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool OOB(int y,int x){
    return (y<0 || y>=boardSize || x<0||x>=boardSize);
}

void moveDust(int y,int x,int dir){
    int nowDust = board[y][x];
    board[y][x] = 0;
    if(dir==0){
        int totalDustMoved =0;
        for(int i=0;i<9;i++){
            int nextY = y+dustY[i];
            int nextX = x+dustX[i];
            int addDustAmt = floor((double)nowDust*(double)(dustPer[i]));
            totalDustMoved+=addDustAmt;
            if(OOB(nextY,nextX)){
                dustOutAmt+=addDustAmt;
                continue;
            }
            else{
                board[nextY][nextX] += addDustAmt;
            }
        }
        int alphaY = y + dustY[9];
        int alphaX = x + dustX[9];
        int alphaAdd = max((nowDust-totalDustMoved),0);

        if(OOB(alphaY,alphaX)){
            dustOutAmt+=alphaAdd;
        }else{
            board[alphaY][alphaX]+=alphaAdd;
        }
    }
    else if(dir==1){
        int totalDustMoved =0;
        for(int i=0;i<9;i++){
            int nextY = y+dustX[i]*-1;
            int nextX = x+dustY[i];
            int addDustAmt = floor((double)nowDust*(double)(dustPer[i]));
            totalDustMoved+=addDustAmt;
            if(OOB(nextY,nextX)){
                dustOutAmt+=addDustAmt;
                continue;
            }
            else{
                board[nextY][nextX] += addDustAmt;
            }
        }
        int alphaY = y + dustX[9]*-1;
        int alphaX = x + dustY[9];
        int alphaAdd = max((nowDust-totalDustMoved),0);
        if(OOB(alphaY,alphaX)){
            dustOutAmt+=alphaAdd;
        }else{
            board[alphaY][alphaX]+=alphaAdd;
        }
    }
    else if(dir==2){
        int totalDustMoved =0;
        for(int i=0;i<9;i++){
            int nextY = y+dustY[i];
            int nextX = x+dustX[i]*-1;
            int addDustAmt = floor((double)nowDust*(double)(dustPer[i]));
            totalDustMoved+=addDustAmt;
            if(OOB(nextY,nextX)){
                dustOutAmt+=addDustAmt;
                continue;
            }
            else{
                board[nextY][nextX] += addDustAmt;
            }
        }
        int alphaY = y + dustY[9];
        int alphaX = x + dustX[9]*-1;
        int alphaAdd = max((nowDust-totalDustMoved),0);
        if(OOB(alphaY,alphaX)){
            dustOutAmt+=alphaAdd;
        }else{
            board[alphaY][alphaX]+=alphaAdd;
        }
    }
    else if(dir==3){
        int totalDustMoved =0;
        for(int i=0;i<9;i++){
            int nextY = y+dustX[i];
            int nextX = x+dustY[i];
            int addDustAmt = floor((double)nowDust*(double)(dustPer[i]));
            totalDustMoved+=addDustAmt;
            if(OOB(nextY,nextX)){
                dustOutAmt+=addDustAmt;
                continue;
            }
            else{
                board[nextY][nextX] += addDustAmt;
            }
        }
        int alphaY = y + dustX[9];
        int alphaX = x + dustY[9];
        int alphaAdd = max((nowDust-totalDustMoved),0);
        if(OOB(alphaY,alphaX)){
            dustOutAmt+=alphaAdd;
        }else{
            board[alphaY][alphaX]+=alphaAdd;
        }
    }
}

void startGame(){
    int ny = boardSize/2;
    int nx = boardSize/2; 
    int nDir = 0;
    int times = 1; 
    int idx = 0;
    while(true){
        for(int i=0;i<times;i++){
            ny = ny+dy[nDir];
            nx = nx + dx[nDir];
            moveDust(ny,nx,nDir);
        }
        
        if(ny == 0 && nx==0){
            break;
        }
        idx++;
        nDir = (nDir+1)%4;
        if(idx%2==0 && times!=boardSize-1){
            times++;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }
    startGame();
    cout<<dustOutAmt;
}