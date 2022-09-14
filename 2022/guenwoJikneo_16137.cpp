/*
    작성자: 김지수
    작성일: 2022/09/15
    백준 -- 견우와 직녀 (16137번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 11
using namespace std; 

const int dx[4] = {0,1,-1,0};
const int dy[4] = {1,0,0,-1};

int boardSize,period;
int board[MAX][MAX];
bool used[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0x7fffffff;
// 적벽 교차할때는 오작교 넣을 수 없음 
bool check(int y,int x){
    bool h1 = false;
    bool h2 = false;
    bool w1 = false;
    bool w2 = false;
    if(y-1 >=0){
        h1 = (board[y-1][x] == 0);
    }
    if(y+1<boardSize){
        h2 = (board[y+1][x]==0);
    }
    if(x-1 >=0){
        w1 = (board[y][x-1] == 0);
    }
    if(x+1<boardSize){
        w2 = (board[y][x+1]==0);
    }

    bool h = h1||h2;
    bool w = w1||w2;

    if(h==true &&w == true){
        return false;
    }
    return true;
}
struct Block{
    int y,x;
    bool bfIsBridge;
    int dist;
};

void bfs(){
    bool foundRoute = false;
    memset(visited,false,sizeof(visited));
    visited[0][0] = true;
    Block start;
    start.y = 0;
    start.x = 0;
    start.bfIsBridge = false;
    start.dist = 0;
    queue<Block> q; 
    q.push(start);

    while(!q.empty()){
        Block now = q.front();
        q.pop();
        if(now.y == boardSize-1 && now.x == boardSize-1){
            foundRoute = true;
            ans = min(ans,now.dist);
            break;
        }else{
        bool inserted = false;
        for(int i=0;i<4;i++){
            // 상하좌우 돌고 
            int nextY = now.y + dy[i];
            int nextX = now.x + dx[i];
            if(nextY <0 || nextX <0 || nextY >=boardSize || nextX>=boardSize){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]!=0){
                Block next; 
                if(board[nextY][nextX]==1){
                    next.y = nextY;
                    next.x = nextX;
                    next.bfIsBridge = false;
                    next.dist = now.dist+1;
                    visited[nextY][nextX] = true;
                    q.push(next);
                }else if(board[nextY][nextX]<=(now.dist+1) && (now.dist+1)%board[nextY][nextX]==0 && now.bfIsBridge==false){
                    //두 번 연속으로 오작교를 건너지는 않기로 했다 & 주기에 따라 이동 가능성 확인
                    next.y = nextY;
                    next.x = nextX;
                    next.bfIsBridge = true;
                    next.dist = now.dist+1;
                    visited[nextY][nextX] = true;
                    q.push(next);
                }
                else{
                   // 갈수 없으면 현재위치에서 시간만 늘림 
                    if(!inserted){
                        inserted = true;
                        next.y = now.y;
                        next.x = now.x;
                        next.bfIsBridge = now.bfIsBridge;
                        next.dist = now.dist+1;
                        q.push(next);
                    }
                }
            }
        }
        }
    }
}

// 주기를 갖는 오작교 1개 설치 가능 
void makeComb(int pickCount, int sy,int sx){
    if(pickCount ==1){
        bfs();
        return;
    }
    for(int i=sy;i<boardSize;i++){
        for(int j=sx;j<boardSize;j++){
            if(!used[i][j] && check(i,j) && board[i][j]==0){
                used[i][j] = true;
                board[i][j] = period;
                makeComb(pickCount+1,i,j);
                used[i][j] = false;
                board[i][j] = 0;
            }
        }
        sx=0;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>period;
    int wallCnt = 0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
            if(board[i][j]==0){
                wallCnt++;
            }
        }
    }
    memset(used,false,sizeof(used));
    if(wallCnt>0){
        // 절벽 있을 경우 1개의 오작교 설치 
        makeComb(0,0,0);
    }else{
        // 절벽 없으면 바로 확인
        bfs();
    }
    cout<<ans;
}