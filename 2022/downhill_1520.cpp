/*
    작성자: 김지수
    작성일: 2022/07/18
    백준 -- 내리막 길 (1520번)
*/

#include <iostream>
#include <cstring>
#define MAX 501
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int height,width; 

int board[MAX][MAX];
bool visited[MAX][MAX];
int cache[MAX][MAX];

int dfs(int y,int x,int h){
    int &ret = cache[y][x];
    if(ret!=-1){
        return ret;
    }
    if(y == height-1 && x== width-1){
        return 1;
    }else{
        int temp =0;
        for(int i=0;i<4;i++){
            int nextY = y+dy[i];
            int nextX = x+dx[i];
            if(nextY<0 || nextY>=height || nextX<0 || nextX>=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]<h){
                visited[nextY][nextX] = true;
                temp+=dfs(nextY,nextX,board[nextY][nextX]);
                visited[nextY][nextX] = false;
            }
        }
        ret = temp;
        return ret;
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
    memset(visited,false,sizeof(visited));
    memset(cache,-1,sizeof(cache));
    visited[0][0] = true;
    cout<<dfs(0,0,board[0][0]);
}