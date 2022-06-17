/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 영역 구하기 (2583번)
*/

#include <iostream>
#include <vector>
#include <queue> 
#include <cstring> 
#include <algorithm>
#define MAX 101
using namespace std; 

int height,width,squareNum;
int board[MAX][MAX]; 
bool visited[MAX][MAX]; 
vector<int> ans; 

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int bfs(int y,int x){
    queue<pair<int,int> > q; 
    visited[y][x] = true; 
    q.push(make_pair(y,x));
    int count =0;

    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        count++;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY<0 || nextY >=height || nextX<0 || nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX] == 0){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    return count;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(visited,false,sizeof(visited));
    memset(board,0,sizeof(board));

    cin>>height>>width>>squareNum;
    for(int i=0;i<squareNum;i++){
        int lx,ly,rx,ry; 
        cin>>lx>>ly>>rx>>ry; 
        for(int j=height-ry;j<=height-1-ly;j++){
            for(int k=lx; k<rx;k++){
                board[j][k] = 1; 
            }
        }
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j] == 0 && !visited[i][j]){
                int area = bfs(i,j);
                ans.push_back(area);
            }
        }
    }

    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}