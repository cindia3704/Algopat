/*
    작성자: 김지수
    작성일: 2022/10/14
    코드트리 -- 술래 잡기 (44번)
*/

#include <iostream> 
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 101
#define MAX_P 10001;
using namespace std;

//NESW
const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};

struct PEOPLE{
    int y,x;
    int dir;
    int idx;
    bool alive;
};

vector<PEOPLE> peopleList;

int boardSize,peopleCnt,treeCnt,turnCnt;
vector<int> board[MAX][MAX];
int tree[MAX][MAX];
int turnPoint[MAX][MAX];    // 1= 방향바꿈, 2 = 뒤집기 , 0= nothing
int chaserY,chaserX, chaserDir;
int score;

void print(){
    cout<<"\n======"<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j].size()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool OOB(int y,int x){
    return (y<0 || y>=boardSize || x<0 || x>=boardSize);
}

int reverseDir(int dir){
    if(dir ==0){
        return 2;
    }else if(dir == 1){
        return 3;
    }else if(dir ==2){
        return 0; 
    }else{
        return 1;
    }
}

void movePoeple(){
    vector<int> tempArr[MAX][MAX];
    for(int i=0;i<peopleCnt;i++){
        PEOPLE now = peopleList[i];
        int dist = abs(now.y-chaserY) + abs(now.x-chaserX);
        if(now.alive && dist<=3){
            int nextY = now.y+dy[now.dir];
            int nextX = now.x+dx[now.dir];
            if(OOB(nextY,nextX)){
                now.dir = reverseDir(now.dir);
                nextY = now.y+dy[now.dir];
                nextX = now.x+dx[now.dir];
                if(!OOB(nextY,nextX) && !(nextY==chaserY && nextX==chaserX)){
                    tempArr[nextY][nextX].push_back(i);
                    peopleList[i].y = nextY;
                    peopleList[i].x = nextX;
                    peopleList[i].dir = now.dir;
                }
            }else{
                if(nextX == chaserX && nextY==chaserY){
                    tempArr[now.y][now.x].push_back(i);
                    continue;
                }else{
                    tempArr[nextY][nextX].push_back(i);
                    peopleList[i].y = nextY;
                    peopleList[i].x = nextX;
                    peopleList[i].dir = now.dir;
                }
            }
        }
    }

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] = tempArr[i][j];
        }
    }
}

void moveChaser(int turn){
    int round = turn/(boardSize*boardSize);
    
    int nextY = chaserY+dy[chaserDir];
    int nextX = chaserX+dx[chaserDir];
    if(turnPoint[nextY][nextX]==1){
        if(round%2==0){
            chaserDir = (chaserDir+1)%4;
        }else{
            chaserDir = (chaserDir-1+4)%4;
        }
    }else if(turnPoint[nextY][nextX]==2){
        chaserDir=(chaserDir+2)%4;
    }
    chaserY = nextY;
    chaserX = nextX;

    for(int i=0;i<3;i++){
        int ny = chaserY + dy[chaserDir]*i;
        int nx = chaserX + dx[chaserDir]*i;
        if(OOB(ny,nx)){
            break;
        }else{
            if(board[ny][nx].size()>0 && tree[ny][nx]==0){
                score+=turn*board[ny][nx].size();
                for(int k=0;k<board[ny][nx].size();k++){
                    int idx = board[ny][nx][k];
                    peopleList[idx].alive = false;
                }
                board[ny][nx].clear();
            }
        }
    }
    

}


void startGame(){
    chaserY = boardSize/2;
    chaserX = boardSize/2; 
    chaserDir = 0;
    int times =1; 
    for(int i=1;i<=turnCnt;i++){
        movePoeple();
        moveChaser(i);
    }
}
void findTurnPoint(){
    memset(turnPoint,0,sizeof(turnPoint));
    int ny = boardSize/2;
    int nx = boardSize/2; 
    turnPoint[ny][nx] = 2;
    int nowDir = 0;
    int times = 1;
    int idx = 0;
    while(true){
        for(int i=0;i<times;i++){
            int nextY = ny+dy[nowDir];
            int nextX = nx+dx[nowDir];
            ny=nextY;
            nx=nextX;
        }
        turnPoint[ny][nx] = 1;
        if(ny == 0 && nx ==0){
            turnPoint[ny][nx] = 2;
            break;
        }
        idx++;
        nowDir=(nowDir+1)%4;
        if(idx%2==0){
            if(times!=boardSize-1){
                times++;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>peopleCnt>>treeCnt>>turnCnt;
    findTurnPoint();

    for(int i=0;i<peopleCnt;i++){
        PEOPLE p;
        cin>>p.y>>p.x>>p.dir;
        p.y--;
        p.x--;
        p.alive = true;
        p.idx = i;
        board[p.y][p.x].push_back(i);
        peopleList.push_back(p);
    }

    for(int i=0;i<treeCnt;i++){
        int ty,tx; 
        cin>>ty>>tx;
        tree[ty-1][tx-1] = 1;
    }

    startGame();
    cout<<score;
}

