/*
    작성자: 김지수
    작성일: 2022/09/28
    백준 -- 낚시왕 (17143번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 101 
using namespace std; 

struct Shark{
    int y,x;
    int speed; 
    int dir; 
    int sharkSize; 
    bool alive;
};

const int dx[4] = {0,0,1,-1};
const int dy[4] = {-1,1,0,0};

int height,width,sharkCnt;

int board[MAX][MAX];
Shark sharkList[MAX*MAX]; 
int fishingScore=0;

void print(){
    cout<<"\n\n========="<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==-1){
                cout<<". ";
            }else{
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<sharkCnt;i++){
        cout<<"SHARK i:"<<i<<" "<<sharkList[i].y<<" , "<<sharkList[i].x<<" dir:"<<sharkList[i].dir<<"  size:"<<sharkList[i].sharkSize<<"  speed:"<<sharkList[i].speed<<" alive?"<<sharkList[i].alive<<endl;
    }
}

void catchShark(int col){
    for(int i=0;i<height;i++){
        if(board[i][col]!=-1){
            int sharkIdx = board[i][col];
            if(sharkList[sharkIdx].alive==true){
                fishingScore += sharkList[sharkIdx].sharkSize;
                board[i][col] = -1;
                sharkList[sharkIdx].alive = false;
            }
            return;
        }
    }
}

int revDir(int dir){
    if(dir == 0){
        return 1;
    }else if(dir ==1){
        return 0;
    }else if(dir ==2){
        return 3;
    }else if(dir == 3){
        return 2; 
    }
}

void moveShark(){
    int tempBoard[MAX][MAX];
    memset(tempBoard,-1,sizeof(tempBoard));
    for(int i=0;i<sharkCnt;i++){
        Shark now = sharkList[i];
        // 현재 상어가 살아있는 경우만 상어 움직임 
        if(now.alive==true){
            int nextY,nextX;
            for(int i=0;i<now.speed;i++){
                nextY = now.y+dy[now.dir];
                nextX = now.x+dx[now.dir];
                if(nextY <0 || nextY >= height || nextX<0 || nextX >=width){
                    now.dir = revDir(now.dir);
                    nextY = now.y+dy[now.dir];
                    nextX = now.x+dx[now.dir];
                }
                now.y = nextY;
                now.x = nextX;
            }

            // 다른 상어가 있는 경우 
            if(tempBoard[now.y][now.x]!=-1){
                Shark other = sharkList[tempBoard[now.y][now.x]];
                // 이전 상어보다 현재 상어가 더 크면 
                if(other.sharkSize<now.sharkSize){
                    // 이전상어 죽이고, 현재상어를 넣음 
                    sharkList[tempBoard[now.y][now.x]].alive = false;
                    tempBoard[now.y][now.x] = i;
                    sharkList[i].y = now.y;
                    sharkList[i].x = now.x;
                    sharkList[i].dir = now.dir;
                }else{
                    // 이전상어가 더 크면 현재상어 죽음 
                    sharkList[i].alive = false;
                }
            }else{
                // 다른 상어 없으면 현재칸에 상어 넣고, 상어 정보 업데이트 
                tempBoard[now.y][now.x] = i;
                sharkList[i].y = now.y;
                sharkList[i].x = now.x;
                sharkList[i].dir = now.dir;
            }
        }
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = tempBoard[i][j];
        }
    }
}

void startGame(){
    // 한칸씩 왼->오로 전진 
    for(int fisher = 0;fisher<width;fisher++){
        catchShark(fisher);
        moveShark();
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width>>sharkCnt;
    memset(board,-1,sizeof(board));
    for(int i=0;i<sharkCnt;i++){
        Shark newShark;
        cin>>newShark.y>>newShark.x>>newShark.speed>>newShark.dir>>newShark.sharkSize;
        newShark.y--;
        newShark.x--;
        newShark.dir--;
        int mod;
        if(newShark.dir == 0 || newShark.dir ==1){
            mod = (height-1)*2;
        }else{
             mod = (width-1)*2;
        }
        newShark.speed = newShark.speed%mod;
        newShark.alive = true;
        board[newShark.y][newShark.x] = i; 
        sharkList[i] = newShark;
    }
    startGame();
    cout<<fishingScore;
}