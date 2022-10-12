/*
    작성자: 김지수
    작성일: 2022/10/12
    백준 -- 마법사 상어와 파이어볼 (20056번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 51
using namespace std; 

const int dx[8] = {0,1,1,1,0,-1,-1,-1};
const int dy[8] = {-1,-1,0,1,1,1,0,-1};

const int dirEO[4]={0,2,4,6};
const int dirOthers[4]={1,3,5,7};
struct FIREBALL{
    int idx; 
    int y,x;
    int mass;
    int speed, dir; 
    bool alive; 
};

int boardSize,fireballCnt, turnCnt;
vector<FIREBALL> fireballList; 
vector<int> fireIdx[MAX][MAX]; 
void moveFireBall(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            fireIdx[i][j].clear();
        }
    }

    for(int i=0;i<fireballList.size();i++){
        FIREBALL now = fireballList[i];
        if(now.alive){
            int nextY = (now.y+dy[now.dir]*now.speed)%boardSize;
            int nextX = (now.x+dx[now.dir]*now.speed)%boardSize;
            nextY = (nextY<0) ? nextY+boardSize: nextY;
            nextX = (nextX<0) ? nextX+boardSize: nextX;
            fireballList[i].y = nextY;
            fireballList[i].x = nextX; 
            fireIdx[nextY][nextX].push_back(i);
        }
    }
}

void divideFireBall(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(fireIdx[i][j].size()>=2){
                bool allEven = true;
                bool allOdd = true; 
                int massSum =0;
                int speedSum = 0;
                int cnt = fireIdx[i][j].size();
                for(int k=0;k<cnt;k++){
                    int idxNow = fireIdx[i][j][k];
                    FIREBALL now = fireballList[idxNow];
                    massSum +=now.mass;
                    speedSum +=now.speed;
                    if(now.dir%2==0){
                        allOdd = false;
                    }else{
                        allEven = false;
                    }
                    fireballList[idxNow].alive = false;
                }
                int newMass = floor((double)massSum / (double)5);
                int newSpeed = floor((double)speedSum / (double)cnt);
                if(newMass>0){
                for(int k=0;k<4;k++){
                    FIREBALL newFire;
                    newFire.y = i;
                    newFire.x = j;
                    newFire.alive = true;
                    newFire.idx =fireballCnt++;
                    newFire.mass = newMass;
                    newFire.speed = newSpeed;
                    if(allOdd || allEven){
                        newFire.dir = dirEO[k];
                    }else{
                        newFire.dir = dirOthers[k];
                    }
                    fireballList.push_back(newFire);
                }
                }

            }
        }
    }
}

void startGame(){
    for(int i=0;i<turnCnt;i++){
        moveFireBall();
        divideFireBall();
    }
}

int calcMassSum(){
    int sum = 0;
    for(int i=0;i<fireballList.size();i++){
        if(fireballList[i].alive){
            sum+=fireballList[i].mass;
        }
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>fireballCnt>>turnCnt; 
    for(int i=0;i<fireballCnt;i++){
        FIREBALL f;
        cin>>f.y>>f.x>>f.mass>>f.speed>>f.dir;
        f.y--;
        f.x--;
        f.alive = true;
        f.idx = i;
        fireballList.push_back(f);
    }
    startGame();
    cout<<calcMassSum();
}