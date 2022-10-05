/*
    작성자: 김지수
    작성일: 2022/10/05
    백준 -- 어른 상어 (19237번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 21
#define MAXSHARK 500
using namespace std; 

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

struct SHARK{
    int y,x;
    bool alive;
    int idx;
    int dir;
};

int boardSize, sharkCnt,k;
int smell[MAX][MAX];
int timeLeft[MAX][MAX];

SHARK sharkPos[MAXSHARK]; 
vector<int> sharkDirPri[MAXSHARK][4];

void printTimeLeft(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<timeLeft[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<smell[i][j]<<" ";
        }
        cout<<endl;
    }
}

void moveShark(){
    int tempArr[MAX][MAX];
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            tempArr[i][j] = smell[i][j];
        }
    }

    for(int i=1;i<=sharkCnt;i++){
        SHARK now = sharkPos[i];
        if(now.alive){
            bool foundWay = false;
            vector<pair<pair<int,int>,int> > temp; 
            for(int j=0;j<4;j++){
                int nextDir = sharkDirPri[i][now.dir][j];
                int nextY = now.y+dy[nextDir];
                int nextX = now.x+dx[nextDir];
                if(nextY<0 || nextY >=boardSize || nextX <0 || nextX>=boardSize){
                    continue;
                }
                if(smell[nextY][nextX]==0){
                    foundWay =true;
                    if(tempArr[nextY][nextX]!=0){
                        sharkPos[i].alive = false;
                    }else{
                        tempArr[nextY][nextX] = i;
                        timeLeft[nextY][nextX] = k+1;
                        sharkPos[i].y = nextY;
                        sharkPos[i].x = nextX;
                        sharkPos[i].dir = nextDir;
                    }
                    break;
                }
                else{
                    if(smell[nextY][nextX]==i){
                        temp.push_back(make_pair(make_pair(nextY,nextX),nextDir));
                    }
                }
            }
            if(!foundWay){
               if(temp.size()>0){
                int nextY = temp[0].first.first;
                int nextX = temp[0].first.second;
                tempArr[nextY][nextX] = i;
                timeLeft[nextY][nextX] = k+1;
                sharkPos[i].y = nextY;
                sharkPos[i].x = nextX;
                sharkPos[i].dir = temp[0].second;
               }else{
                sharkPos[i].alive = false;
               }
            }
        }
    }

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            smell[i][j] = tempArr[i][j];
        }
    }
}

int countAliveShark(){
    int cnt =0;
    for(int i=1;i<=sharkCnt;i++){
        if(sharkPos[i].alive){
            cnt++;
        }
    }
    return cnt;
}

void decreaseTimeLeft(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(timeLeft[i][j]>0){
                timeLeft[i][j]--;
                if(timeLeft[i][j]==0){
                    smell[i][j] = 0;
                }
            }
        }
    }
}

int startGame(){
    int stage=1;
    bool found = false;

    while(stage<=1000){
        decreaseTimeLeft();
        moveShark();
        int sharkAliveCnt = countAliveShark();
        
        if(sharkAliveCnt==1){
            found = true;
            break;
        }
        stage++;
    }

    if(!found){
        return -1;
    }else{
        return stage; 
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>sharkCnt>>k;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>smell[i][j];
            if(smell[i][j]>0){
                SHARK now; 
                now.y = i;
                now.x = j;
                now.alive = true;
                now.idx = smell[i][j];
                sharkPos[smell[i][j]] = now;
                timeLeft[i][j] = k+1;
            }
        }
    }
    for(int i=1;i<=sharkCnt;i++){
        int startDir;
        cin>>startDir;
        sharkPos[i].dir = startDir-1;
    }
    for(int i=1;i<=sharkCnt;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                int num;
                cin>>num;
                sharkDirPri[i][j].push_back(num-1);
            }
        }
    }
    cout<<startGame();
}