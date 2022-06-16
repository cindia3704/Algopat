/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 미로탐색 (2178번)
*/

#include <iostream>
#include <algorithm> 
#include <queue> 
#define MAX 101
using namespace std; 

const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
char board[MAX][MAX];
bool visited[MAX][MAX];
int height, width;
long long ans = 987654321;

bool bfs(int y,int x){
    queue<pair<pair<int ,int> , int> >q; 
    visited[y][x] = true;
    q.push(make_pair(make_pair(y,x),1));
    bool found = false; 
    while(!q.empty()){
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int nowCount = q.front().second;
        q.pop();
        if(nowY == height-1 && nowX == width-1){
            if(nowCount<ans){
                ans = nowCount;
            }
            found = true; 
            break;
        }
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY<0 || nextY >=height || nextX <0 || nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]=='1'){
                visited[nextY][nextX] = true; 
                q.push(make_pair(make_pair(nextY,nextX),nowCount+1));
            }
        }
    }
    return found;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width;
    for(int i=0;i<height;i++){
        string l;
        cin>>l; 
        for(int j=0;j<l.size();j++){
            board[i][j] = l[j];
        }
        fill(visited[i],visited[i]+MAX,false);
    }

    bool foundRoute = false; 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(!visited[i][j] && board[i][j] == '1'){
                foundRoute = bfs(i,j);
                if(foundRoute){
                    break;
                }
            }
        }
    }
    cout<<ans;

}