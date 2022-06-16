/*
    작성자: 김지수
    작성일: 2022/06/16
    백준 -- 유기농 배추 (1012번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 51
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int board[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int y,int x,int height,int width){
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));
    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = nowY+dy[i];
            int nextX = nowX+dx[i];
            if(nextY<0 || nextY >=height || nextX<0 || nextX>=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]==1){
                visited[nextY][nextX]=true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    return;
}

int calcNumWorm(int height,int width){
    int countWorm = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(!visited[i][j] && board[i][j] ==1){
                bfs(i,j,height,width);
                countWorm++;
            }
        }
    }
    return countWorm;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; 
    cin>>tc; 

    while(tc--){  
        memset(visited,false,sizeof(visited));
        memset(board,0,sizeof(board));

        int height,width,numCabbage;
        cin>>width>>height>>numCabbage; 
        
        for(int i=0;i<numCabbage;i++){
            int x,y;
            cin>>x>>y; 
            board[y][x] = 1;
        }

        int worm = calcNumWorm(height,width);
        cout<<worm<<'\n';        
    }
}