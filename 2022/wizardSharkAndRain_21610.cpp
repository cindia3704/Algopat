/*
    작성자: 김지수
    작성일: 2022/10/07
    백준 -- 마법사 상어와 비바라기 (21610번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 51
using namespace std;

const int dy[8]={0,-1,-1,-1,0,1,1,1};
const int dx[8]={-1,-1,0,1,1,1,0,-1};

const int diagY[4]={-1,-1,1,1};
const int diagX[4]={-1,1,-1,1};

int boardSize,commandCnt; 
int board[MAX][MAX];
vector<pair<int,int> > clouds; 
vector<pair<int,int> > rains;

void print(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void moveCloud(int dir, int speed){
    rains.clear();
    for(int i=0;i<clouds.size();i++){
        pair<int,int> now = clouds[i];
        int nextY = (now.first+ dy[dir]*speed)%boardSize;
        int nextX = (now.second + dx[dir]*speed)%boardSize;
        if(nextY<0){
            nextY+=boardSize;
        }
        if(nextX<0){
            nextX+=boardSize;
        }
        board[nextY][nextX]+=1;
        rains.push_back(make_pair(nextY,nextX));
    }
}
void magic(){
    for(int i=0;i<rains.size();i++){
        pair<int,int> now = rains[i];
        int cnt = 0;
        for(int k=0;k<4;k++){
            int nextY = now.first+diagY[k];
            int nextX = now.second+diagX[k];
            if(nextY<0 || nextY>=boardSize||nextX<0 || nextX>=boardSize){
                continue;
            }else{
                if(board[nextY][nextX]>0){
                    cnt++;
                }
            }
        }
        board[now.first][now.second]+=cnt;
    }
}

bool found(int y,int x){
    for(int i=0;i<rains.size();i++){
        if(rains[i].first == y && rains[i].second ==x){
            return true;
        }
    }
    return false;
}

void makeCloud(){
    vector<pair<int,int> > temp;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]>=2 && !found(i,j)){
                board[i][j] -=2;
                temp.push_back(make_pair(i,j));
            }
        }
    }
    clouds.clear();
    clouds = temp;
}

void play(int dir,int speed){
    moveCloud(dir,speed);  
    magic();
    makeCloud();
}

int getWaterSum(){
    int sum = 0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            sum+=board[i][j];
        }
    }
    return sum;
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
    clouds.push_back(make_pair(boardSize-1,0));
    clouds.push_back(make_pair(boardSize-1,1));
    clouds.push_back(make_pair(boardSize-2,0));
    clouds.push_back(make_pair(boardSize-2,1));

    for(int i=0;i<commandCnt;i++){
        int dir,speed; 
        cin>>dir>>speed;
        play(dir-1,speed);
    }
    cout<<getWaterSum();
}