/*
    작성자: 김지수
    작성일: 2022/06/21
    백준 -- 빙산 (2573번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 301
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int height,width;
int board[MAX][MAX];
bool visited[MAX][MAX];
int seaAdj[MAX][MAX];


void decreaseSeaLevel(){
    // copy
    int copy[MAX][MAX];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            copy[i][j] = board[i][j]; 
        }
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int countWater =0;
            for(int wat=0;wat<4;wat++){
                int nextY = i+dy[wat];
                int nextX = j+dx[wat];
                if(nextY<0 || nextY>=height || nextX<0 || nextX >=width){
                    continue;
                }else{
                    if(copy[nextY][nextX]==0){
                        countWater++;
                    }
                }
            }
            board[i][j] = max(copy[i][j]-countWater , 0);
        }
    }
}

void bfs(int y,int x){
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(nextY <0 || nextY >=height || nextX <0 || nextX >=width){
                continue;
            }

            if(!visited[nextY][nextX] && board[nextY][nextX]>0){
                visited[nextY][nextX]=true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}

pair<int,int> findSeparateArea(){
    memset(visited,false,sizeof(visited));
    int countIsland = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(!visited[i][j] && board[i][j]>0){
                bfs(i,j);
                countIsland++;
            }
        }
    }
    // 분리되었거나 , 다 없어진경우 (다 없어졌을때 0 출력위해 Pair로 반환)
    if(countIsland>1 || countIsland==0){
        return make_pair(true,countIsland);
        
    }else{
        // 분리 안되고 계속 1개면 계속 진행 
        return make_pair(false,countIsland);
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

    int countYear=0;
    while(true){
        pair<bool,int> separated = findSeparateArea();
        if(separated.first){
            if(separated.second == 0){
                countYear =0;
            }
            break;
        }
        decreaseSeaLevel();
        countYear++;
    }
    cout<<countYear;

}