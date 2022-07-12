/*
    작성자: 김지수
    작성일: 2022/07/13
    백준 -- 보물섬 (2589번)
*/

#include <iostream>
#include <queue> 
#include <cstring>
#include <queue>
#define MAX 51
using namespace std; 

const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};

int height,width;
char board[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;

void bfs(int y,int x){
    queue<pair<pair<int,int> ,int > > q; 
    visited[y][x]= true;
    q.push(make_pair(make_pair(y,x),0));

    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int count = q.front().second;
        ans = max(ans,count);
        q.pop();

        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(nextY < 0 || nextY>=height || nextX <0 || nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX] == 'L'){
                visited[nextY][nextX] = true; 
                q.push(make_pair(make_pair(nextY,nextX),count+1));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>height>>width;
    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            board[i][j] = l[j];
        }
    }
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j] == 'L'){
                memset(visited,false,sizeof(visited));
                bfs(i,j);
            }
        }
    }
    cout<<ans;
}