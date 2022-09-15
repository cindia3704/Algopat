/*
    작성자: 김지수
    작성일: 2022/09/15
    백준 -- 청소년 상어 (19236번)
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define EMPTY -1
#define SHARK -2
#define MAX 5
using namespace std; 

struct Fish{
    int fishIdx;
    int y,x;
    int dir;
    bool alive; 
};

struct Turn{
    int sharkY,sharkX;
    int board[MAX][MAX];
    int eatSum;
    int sharkDir; 
    Fish fishList[17];
};

const int dx[8]={0,-1,-1,-1,0,1,1,1};
const int dy[8]={-1,-1,0,1,1,1,0,-1};
int ans = 0;

void print(Turn t){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<t.board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

Turn moveFish(Turn now){
    for(int i=1;i<=16;i++){
        Fish nowFish = now.fishList[i];
        int nowDir = nowFish.dir;
        if(now.fishList[i].alive){
            // 갈수 있는 위치 있을때 까지 총 8개의 위치 확인 (45도씩 반시계방향 회전)
            for(int j=0;j<8;j++){
                int nextDir = (nowDir+j)%8;
                int nextY = nowFish.y+dy[nextDir];
                int nextX = nowFish.x+dx[nextDir];
                // 가려는 곳에 상어없고 보드 밖 아닐때 
                if(nextY>=0 && nextY<4 && nextX<4 && nextX>=0 && now.board[nextY][nextX]!=SHARK){
                    // 비었으면 해당 물고기 이동 
                    if(now.board[nextY][nextX]==EMPTY){
                        now.board[nowFish.y][nowFish.x] = EMPTY;
                        now.fishList[i].y = nextY;
                        now.fishList[i].x = nextX;
                        now.fishList[i].dir = nextDir;
                        now.board[nextY][nextX] = i;
                    }else{
                        // 다른 물고기 있으면 물고기랑 swap 
                        int swapFishID = now.board[nextY][nextX];
                        swap(now.board[nowFish.y][nowFish.x],now.board[nextY][nextX]);
                        now.fishList[swapFishID].y = nowFish.y;
                        now.fishList[swapFishID].x = nowFish.x;
                        now.fishList[i].y = nextY;
                        now.fishList[i].x = nextX;
                        now.fishList[i].dir = nextDir;
                    }
                    break;
                }
            }
        }
    }
    return now;
}

void startGame(Turn t){
    // 상어가 물고기 잡아먹음 
    if(t.board[t.sharkY][t.sharkX]!=EMPTY){
        int fishID = t.board[t.sharkY][t.sharkX];
        t.eatSum+=fishID;
        t.fishList[fishID].alive = false;
        t.board[t.sharkY][t.sharkX] = SHARK;
        t.sharkDir = t.fishList[fishID].dir;
        ans = max(ans,t.eatSum);
    }
    // 물고기 방향에 따라 움직임. 가려는 방향이 보드 밖 / 상어위치 => 45도 반시계 방향 회전 
    t = moveFish(t);
    
    // 상어의 방향에 따라 갈수 있는 모든 곳 방문해보기 
    int times = 1;
    int oriY =t.sharkY;
    int oriX = t.sharkX;
    while(true){
        int nextSY = t.sharkY+dy[t.sharkDir]*times;
        int nextSX = t.sharkX+dx[t.sharkDir]*times;
        // 갈수 없으면 (보드 밖이면) while문 나가기 
        if(nextSY<0 || nextSY>=4 || nextSX<0 || nextSX>=4){
            break;
        }else{
            if(t.board[nextSY][nextSX]!=EMPTY){
                int nextIDX = t.board[nextSY][nextSX];
                t.board[t.sharkY][t.sharkX] = EMPTY;
                t.sharkY = nextSY;
                t.sharkX = nextSX;
                startGame(t);
                t.sharkY = oriY;
                t.sharkX = oriX;
                t.board[t.sharkY][t.sharkX] = SHARK;
            }
        }
        times++;
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Turn start; 

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            Fish now; 
            cin>>now.fishIdx>>now.dir;
            start.board[i][j]= now.fishIdx;
            now.dir--;
            now.alive = true;
            now.x=j;
            now.y=i;
            start.fishList[now.fishIdx] = now;
        }
    }
    start.eatSum=0;
    start.sharkX=0;
    start.sharkY=0;
    startGame(start);
    cout<<ans;
}