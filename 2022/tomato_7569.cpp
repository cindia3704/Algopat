/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 토마토 (7569번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 101
#define NO_TOMAO -1
#define RIPE 1
#define NOT_RIPE 0
using namespace std;
long long ans = -1; 

const int dx[6]={0,0,1,0,0,-1}; // 위 y위 오 아래 y아래 왼
const int dy[6] ={0,-1,0,0,1,0}; 
const int dz[6]={-1,0,0,1,0,0};
int height,width,totLevel; 
int board[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
struct BOARD{
    int level,y,x; 
    long long count; 
};
queue<BOARD> q;

void bfs(){
    while(!q.empty()){
        int nowY = q.front().y;
        int nowX = q.front().x;
        int nowLevel = q.front().level;
        long long nowCount = q.front().count;
        q.pop();
        if(nowCount > ans){
            ans = nowCount;
        }
        for(int i=0;i<6;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            int nextLevel = nowLevel + dz[i];
            if(nextY<0 || nextY >=height || nextX <0 || nextX >=width || nextLevel <0 || nextLevel>=totLevel){
                continue;
            }
            if(!visited[nextLevel][nextY][nextX] && board[nextLevel][nextY][nextX]==0){
                visited[nextLevel][nextY][nextX] = true;
                BOARD next;
                next.y = nextY;
                next.x = nextX; 
                next.level = nextLevel;
                next.count = nowCount+1; 
                q.push(next);
            }
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>width>>height>>totLevel;

    memset(visited,false,sizeof(visited));

    for(int i=0;i<totLevel;i++){
        for(int j=0;j<height;j++){
            for(int k=0;k<width;k++){
                cin>>board[i][j][k];

                if(board[i][j][k]==1){
                    BOARD n;
                    n.level=i;
                    n.y=j;
                    n.x=k;
                    n.count=0;
                    q.push(n);
                    visited[i][j][k] = true;
                }
            }
        }
    }
    bfs();

    for(int i=0;i<totLevel;i++){
        for(int j=0;j<height;j++){
            for(int k=0;k<width;k++){
                if((board[i][j][k] == 0 || board[i][j][k]==1) && !visited[i][j][k]){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<ans;
}