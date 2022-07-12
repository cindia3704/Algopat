/*
    작성자: 김지수
    작성일: 2022/07/13
    백준 -- 데스 나이트 (16948번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 200
using namespace std;

const int dy[6]={-2,-2,0,0,2,2};
const int dx[6] ={-1,1,-2,2,-1,1};

int boardSize;
int sy,sx,ey,ex; 
bool visited[MAX][MAX];
int ans = 0x7fffffff;

void bfs(){
    queue<pair<pair<int,int> ,int> > q; 
    visited[sy][sx] = true;
    q.push(make_pair(make_pair(sy,sx),0));
    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int count = q.front().second;
        q.pop();
        if(now.first == ey && now.second == ex){
            ans = min(ans,count);
            continue;
        }
        for(int i=0;i<6;i++){
            int nextY = now.first+dy[i];
            int nextX = now.second + dx[i];
            if(nextY <0 || nextY >=boardSize || nextX <0 || nextX >=boardSize){
                continue;
            }
            if(!visited[nextY][nextX]){
                visited[nextY][nextX] = true;
                q.push(make_pair(make_pair(nextY,nextX),count+1));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize;
    cin>>sy>>sx>>ey>>ex; 
    bfs();
    if(ans == 0x7fffffff){
        cout<<-1;
    }else{
        cout<<ans;
    }
}