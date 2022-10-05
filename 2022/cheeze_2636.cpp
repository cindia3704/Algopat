/*
    작성자: 김지수
    작성일: 2022/10/05
    백준 -- 치즈 (2636번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 101
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};
int height,width;
int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];
int totalCheezeCnt;

void bfs(){
    memset(visited,false,sizeof(visited));
    queue<pair<int,int> > q; 
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        board[now.first][now.second] = -1;
        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX = now.second+dx[i];
            if(nextY<0 || nextX<0 || nextY>=height || nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX] !=1 ){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}

bool check(int y,int x){
    for(int i=0;i<4;i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(nextY<0 || nextX<0 || nextY>=height || nextX >=width){
            continue;
        }
        if(board[nextY][nextX] == -1){
            return true;
        }
    }
    return false;
}

void copyToBoard(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = temp[i][j];
        }
    }
}

void copyToTemp(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            temp[i][j] = board[i][j];
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
            if(board[i][j] == 1){
                totalCheezeCnt++;
            }
        }
    }

    int stage = 1;
    while(true){
        bfs();
        copyToTemp();
        int meltCnt = 0;

        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(board[i][j] == 1 && check(i,j)){
                    temp[i][j] = 0;
                    meltCnt++;
                }
            }
        }
        if(totalCheezeCnt == meltCnt){
            cout<<stage<<'\n';
            cout<<meltCnt;
            break;
        }else{
            totalCheezeCnt-=meltCnt;
            copyToBoard();
            stage++;
        }
    }
}