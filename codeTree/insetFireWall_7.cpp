/*
    작성자: 김지수
    작성일: 2022/10/13
    코드트리 -- 방화벽 설치하기 (7번)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 9 
#define FIRE 2
#define WALL 1
#define EMPTY 0
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};
int maxSafeArea = 0;
int height,width;
int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];
bool OOB (int y, int x){
    return (y<0 || y>=height || x<0 || x>=width);
}

void bfs(int y,int x){
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        temp[now.first][now.second] = FIRE;
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(OOB(nextY, nextX)){
                continue;
            }
            if(!visited[nextY][nextX] && temp[nextY][nextX]!=WALL){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}

int countEmpty(){
    int cnt = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(temp[i][j] == EMPTY){
                cnt++;
            }
        }
    }
    return cnt; 
}

void makeComb(int pickCount,int sy,int sx){
    if(pickCount == 3){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                temp[i][j] = board[i][j];
            }
        }

        for(int i=0;i<height;i++){
            fill(visited[i],visited[i]+width,false);
        }
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(temp[i][j] == FIRE && !visited[i][j]){
                    bfs(i,j);
                }
            }
        }
        int tempAns = countEmpty();
        maxSafeArea = max(maxSafeArea,tempAns);
        return;
    }

    for(int i=sy;i<height;i++){
        for(int j=sx;j<width;j++){
            if(board[i][j] == EMPTY){
                board[i][j] = WALL;
                makeComb(pickCount+1,sy,sx);
                board[i][j] = EMPTY;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>height>>width;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }
    makeComb(0,0,0);
    cout<<maxSafeArea;
}