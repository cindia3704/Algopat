/*
    작성자: 김지수
    작성일: 2022/10/12
    백준 -- 낚시왕 (17143번)
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 101
using namespace std;

// N S E W
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,1,-1};

struct SHARK{
    int y,x;
    int speed,direction;
    int sharkSize; 
    bool alive;
};

int eatSum=0;
int height,width,sharkCnt;  
vector<SHARK> sharkList; 
int sharkIdx[MAX][MAX];

void print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<sharkIdx[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void eatShark(int w){
    for(int i=0;i<height;i++){
        if(sharkIdx[i][w]!=-1){
            int idx = sharkIdx[i][w];
            sharkList[idx].alive = false;
            eatSum+=sharkList[idx].sharkSize;
            sharkIdx[i][w] = -1;
            break;
        }
    }
}

int reverseDir(int dir){
    if(dir == 0){
        return 1;
    }else if(dir ==1){
        return 0;
    }else if(dir ==2){
        return 3;
    }else{
        return 2;
    }
}

void moveShark(){
    int temp[MAX][MAX];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            temp[i][j] = -1;
        }
    }
    for(int i=0;i<sharkCnt;i++){
        SHARK now = sharkList[i];
        if(now.alive){
            int ny = now.y;
            int nx = now.x; 
            for(int j=0;j<now.speed;j++){
                int nextY = ny+dy[now.direction];
                int nextX = nx+dx[now.direction];
                if(nextY<0 || nextY>=height || nextX<0 || nextX>=width){
                    now.direction = reverseDir(now.direction);
                    nextY = ny+dy[now.direction];
                    nextX = nx+dx[now.direction];
                }
                ny = nextY;
                nx = nextX;
            }
            if(temp[ny][nx]==-1){
                temp[ny][nx] = i;
                sharkList[i].y = ny;
                sharkList[i].x = nx;
                sharkList[i].direction = now.direction;
            }else{
                int prevIdx = temp[ny][nx];
                SHARK prev = sharkList[prevIdx];
                if(prev.sharkSize > now.sharkSize){
                    sharkList[i].alive = false;
                }else{
                    sharkList[prevIdx].alive = false;
                    temp[ny][nx] = i;
                    sharkList[i].y = ny;
                    sharkList[i].x = nx;
                    sharkList[i].direction = now.direction;
                }
            }
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            sharkIdx[i][j] = temp[i][j];
        }
    }
}

void startGame(){
    for(int i=0;i<width;i++){
        eatShark(i);
        moveShark();
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>height>>width>>sharkCnt;
    for(int i=0;i<height;i++){
        fill(sharkIdx[i],sharkIdx[i]+width,-1);
    }
    for(int i=0;i<sharkCnt;i++){
        SHARK s; 
        cin>>s.y>>s.x>>s.speed>>s.direction>>s.sharkSize;
        s.y--;
        s.x--;
        s.direction--;
        s.alive =true;
        if(s.direction==0 || s.direction == 1){
            s.speed = (s.speed%(2*(height-1)));
        }else{
            s.speed = (s.speed%(2*(width-1)));
        }
        sharkList.push_back(s);
        sharkIdx[s.y][s.x] = i;
    }
    startGame();
    cout<<eatSum;
}