/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 연구소 (14502번)
*/

#include <iostream>
#include <cstring> 
#include <queue>
#define MAX 9
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4]={-1,0,1,0};
int ans =0;

int board[MAX][MAX];
bool visited[MAX][MAX];
int height,width; 

void bfs(int y,int x){
    queue<pair<int,int> > q; 
    visited[y][x] = true; 
    q.push(make_pair(y,x));

    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY<0 || nextY >=height || nextX <0 || nextX >=width){
                continue;
            }
            if(visited[nextY][nextX] ==false && board[nextY][nextX] == 0){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}

void spread(){
    memset(visited,false,sizeof(visited));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==2 && !visited[i][j]){
                bfs(i,j);
            }
        }
    }
}

int countSafeArea(){
    int safeArea = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==0 && visited[i][j] ==false){
                safeArea++;
            }
        }
    }
    return safeArea;
}

void makeComb(int pickCount, int sy,int sx){
    // 빈공간중 벽 세울 공간 3개 고리기 
    if(pickCount ==3){
        // 바이러스 퍼지게 
        spread();
        // 바이러스 퍼진 후 현재 안전구역 개수 구하기 
        int temp = countSafeArea();
        if(temp>ans){
            ans = temp;
        }
        return; 
    }else{
        for(int i=sy;i<height;i++){
            for(int j=sx;j<width;j++){
                if(board[i][j]==0){
                    board[i][j] = 1; 
                    makeComb(pickCount+1,i,j+1);
                    board[i][j] = 0; 
                }
            }
            sx = 0;
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
    cout<<ans;

}   