/*
    작성자: 김지수
    작성일: 2022/07/05
    백준 -- 인구 이동 (16234번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 51
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4]={-1,0,1,0};
int boardSize, diffMin,diffMax; 
int board[MAX][MAX];
bool visited[MAX][MAX];
int temp[MAX][MAX];

bool bfs(int y,int x){
    vector<pair<int,int> > land; 
    queue<pair< pair<int,int>,int> > q;
    int totalSum=0;
    int totalLand = 0;
    visited[y][x] = true;
    q.push(make_pair(make_pair(y,x),board[y][x]));

    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int nowWeight = q.front().second;
        q.pop();
        land.push_back(now);
        totalLand++;
        totalSum+=nowWeight;
        
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(nextY<0 || nextY >=boardSize || nextX <0 || nextX>=boardSize){
                continue;
            }
            if(!visited[nextY][nextX]){
                int diff = abs(nowWeight-board[nextY][nextX]);
                if(diff>=diffMin && diff<=diffMax){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(make_pair(nextY,nextX),board[nextY][nextX]));
                }
            }
        }
    }
    if(totalLand ==1){
        return false;
    }else{
        int changeWeight = totalSum/totalLand;
        for(int i=0;i<totalLand;i++){
            temp[land[i].first][land[i].second] = changeWeight;
        }
        return true;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>diffMin>>diffMax;
    
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }

    bool found = false;
    int time = 0;
    while(true){
        memset(visited,false,sizeof(visited));
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                temp[i][j] = board[i][j];
            }
        }
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                if(!visited[i][j]){
                    bool tempFound = bfs(i,j);
                    if(tempFound){
                        found = true;
                    }
                }
            }
        }
        if(!found){
            break;
        }
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                board[i][j] = temp[i][j];
            }
        }
        time++;
        found = false;
    }
    cout<<time;
}