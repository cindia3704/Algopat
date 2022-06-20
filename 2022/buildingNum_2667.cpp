/*
    작성자: 김지수
    작성일: 2022/06/21
    백준 -- 단지번호붙이기 (2667번)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 26
using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

char board[MAX][MAX];
bool visited[MAX][MAX];
int boardSize; 
vector<int> buildingSizes; 

int bfs(int y,int x){
    queue<pair<int ,int > > q;
    visited[y][x] = true;
    
    q.push(make_pair(y,x));
    int nowBuilding = 0;

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        nowBuilding++;

        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX = now.second+dx[i];
            if(nextY<0 || nextY >=boardSize || nextX <0 || nextX >=boardSize){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX] == '1'){
                visited[nextY][nextX] = true; 
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    return nowBuilding;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            board[i][j] = l[j];
        }
    }
    for(int i=0;i<MAX;i++){
        fill(visited[i],visited[i]+MAX,false);
    }

    int num = 1; 
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j] == '1' && !visited[i][j]){
                int buildingSize = bfs(i,j);
                buildingSizes.push_back(buildingSize);
                num++;
            }
        }
    }

    sort(buildingSizes.begin(),buildingSizes.end());

    cout<<num-1<<'\n';
    for(int i=0;i<buildingSizes.size();i++){
        cout<<buildingSizes[i]<<'\n';
    }
}