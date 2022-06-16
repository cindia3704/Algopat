/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 그림 (1926번)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 501
using namespace std; 
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int height,width; 
int maxArea = 0;
int board[MAX][MAX];
bool visited[MAX][MAX];
struct PIC{
    int y,x,count;
};

void bfs(int y,int x){
    queue<PIC> q;
    PIC start;
    start.y = y;
    start.x = x; 
    start.count = 1; 
    visited[y][x] = true;
    q.push(start);
    
    int nowSize = 0; 
    while(!q.empty()){
        int nowY = q.front().y;
        int nowX = q.front().x;
        int nowCount = q.front().count;
        nowSize++;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY<0 || nextY>=height || nextX <0 || nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]==1){
                visited[nextY][nextX] = true; 
                PIC next; 
                next.y = nextY;
                next.x = nextX; 
                next.count = nowCount+1;
                q.push(next);
            }
        }
    }
    if(maxArea <nowSize){
        maxArea = nowSize;
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
        fill(visited[i],visited[i]+MAX,false);
    }
    
    int countPicNum =0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j] == 1 && !visited[i][j]){
                bfs(i,j);
                countPicNum++;
            }
        }
    }

    cout<<countPicNum<<'\n';
    cout<<maxArea;
}