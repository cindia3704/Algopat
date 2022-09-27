/*
    작성자: 김지수
    작성일: 2022/09/27
    백준 -- 로봇 청소기 (14503번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 51
using namespace std; 

const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};

int height,width;
int startY,startX,startDir;
int board[MAX][MAX];
int visited[MAX][MAX];
int ans = 0;

struct Block{
    int y,x;
    int cleanCnt;
    int dir; 
};

// 왼쪽으로 돌리기 
int turn(int dir){
    if(dir==0){
        return 3;
    }else if(dir ==1){
        return 0;
    }else if(dir ==2){
        return 1;
    }else {
        return 2;
    }
}

// 현재 방향에서 후진할때 방향 구하기 
int reverseDir(int dir){
    if(dir==0){
        return 2;
    }else if(dir ==1){
        return 3;
    }else if(dir ==2){
        return 0;
    }else {
        return 1;
    }
}


void bfs(){
    stack<Block> q; 
    visited[startY][startX] = 1;
    Block st; 
    st.y = startY;
    st.x = startX;
    st.dir = startDir;
    st.cleanCnt = 1;
    q.push(st);

    while(!q.empty()){
        Block now = q.top();
        q.pop();
        // 최대 청소 칸 매번 업데이트 
        ans = max(ans,now.cleanCnt);

        bool foundWay = false;
        int tempDir = now.dir;
        // 4번 왼쪽으로 회전하며 해당칸 갈수 있는지 확인 
        for(int i=0;i<4;i++){
            int nextDir = turn(tempDir);
            int nextY = now.y + dy[nextDir];
            int nextX = now.x+ dx[nextDir];
            tempDir = nextDir;
            if(nextY<0 || nextY>=height || nextX<0 || nextX >=width){
                continue;
            }
            // 아직 방문 안했고, 벽이 아니면 방문 가능! (foundWay 업데이트 )
            if(visited[nextY][nextX]==-1 && board[nextY][nextX]!=1){
                visited[nextY][nextX] = now.cleanCnt+1;
                Block next; 
                next.y = nextY;
                next.x = nextX;
                next.dir = nextDir;
                next.cleanCnt = now.cleanCnt+1;
               // cout<<"push & break!!"<<endl;
                q.push(next);
                foundWay = true;
                break;
            }
        }
        // 갈수 있는 칸 못찾은 경우 뒤로 후진 
        if(!foundWay){
            int revDir = reverseDir(now.dir);
            int nextY = now.y + dy[revDir];
            int nextX = now.x+dx[revDir];
            
            if(nextY<0 || nextY>=height || nextX<0 || nextX >=width){
                break;
            }
            // 후진하려는 곳이 벽이 아닌경우에만 가능 
            if(board[nextY][nextX]!=1){
                Block next; 
                next.y = nextY;
                next.x = nextX;
                next.dir = now.dir;
                next.cleanCnt = now.cleanCnt;
                // 아직 방문 안한칸이면 방문 처리 & 청소칸 ++ 
                if(visited[nextY][nextX]==-1){
                    visited[nextY][nextX] = now.cleanCnt+1;
                    next.cleanCnt++;
                }
                q.push(next);
            }
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>height>>width;
    cin>>startY>>startX>>startDir;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }
    memset(visited,-1,sizeof(visited));
    bfs();
    cout<<ans;
}