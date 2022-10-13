/*
    작성자: 김지수
    작성일: 2022/10/13
    코드트리 -- 전투 로봇 (19번)
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector> 
#define MAX 21
using namespace std; 

const int dy[4]={-1,0,0,1};
const int dx[4]={0,-1,1,0};

struct MONSTER{
    int y,x;
    int monstIdx;
    int level;
    bool alive;
};
int boardSize; 
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<MONSTER> monsterList;

int robotY,robotX;
int robotLevel;
int eatCnt;
int times = 0;

bool OOB(int y,int x){
    return (y<0 || y>=boardSize || x<0 || x>=boardSize);
}

void print(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool eatMonster(){
    bool notFound = true;
    memset(visited,false,sizeof(visited));
    queue<pair<pair<int,int>,int> > q; 
    visited[robotY][robotX] = true;
    q.push(make_pair(make_pair(robotY,robotX),0));
    int minDist = 0x7fffffff;
    int minY = boardSize;
    int minX = boardSize;

    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int nowDist = q.front().second;
        q.pop();
        if(board[now.first][now.second]>=0){
            MONSTER n = monsterList[board[now.first][now.second]];
            if(n.level<robotLevel && n.alive == true){
                if(minDist>nowDist){
                    minY = now.first;
                    minX = now.second;
                    minDist = nowDist;
                }else if(minDist == nowDist){
                    if(minY>now.first){
                        minY = now.first;
                        minX = now.second;
                    }else if(minY == now.first){
                        if(minX>now.second){
                            minY = now.first;
                            minX = now.second;
                        }
                    }
                }
                notFound = false;
            }
        }
        
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(OOB(nextY,nextX)){
                continue;
            }
            if(!visited[nextY][nextX]){
                visited[nextY][nextX] = true;
                if(board[nextY][nextX]==-1){
                    q.push(make_pair(make_pair(nextY,nextX),nowDist+1));
                }else{
                    int monstSize = monsterList[board[nextY][nextX]].level;
                    if(robotLevel>=monstSize && monsterList[board[nextY][nextX]].alive){
                        q.push(make_pair(make_pair(nextY,nextX),nowDist+1));
                    }
                }
            }
        }
    }

    if(!notFound){
        board[minY][minX] = -1;
        monsterList[board[minY][minX]].alive = false;
        eatCnt++;
        robotY = minY;
        robotX = minX;
        times+=minDist;
        if(eatCnt == robotLevel){
            robotLevel++;
            eatCnt = 0;
        }
    }

    return notFound;
}

void startGame(){
    int stop = false; 
    while(true){
        stop = eatMonster();
        if(stop){
            break;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int monIdx = 0;
    cin>>boardSize;

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] = -1;
            int num;
            cin>>num;
            if(num == 9){
                robotY = i;
                robotX = j;
                robotLevel =2;
            }else if(num>0 && num<7){
                MONSTER m;
                m.y = i;
                m.x = j;
                m.level = num;
                m.alive = true;
                m.monstIdx = monIdx;
                monsterList.push_back(m);
                board[i][j] = monIdx;
                monIdx++;
            }   
        }
    }
    startGame();
    cout<<times;
}