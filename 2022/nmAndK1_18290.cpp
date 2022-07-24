/*
    작성자: 김지수
    작성일: 2022/07/22
    백준 -- NM과 K (1)(18290번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 11
using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int height,width,totalPick; 

int board[MAX][MAX];
bool visited[MAX][MAX];

long long ans = -0x7fffffff;    // 다 음수인경우 답도 음수 여야 함 => 최대음수값이 초기값 


// 상하좌우 중 이미 방문한게 있으면 못넣음 
bool checks(int y,int x){
    for(int i=0;i<4;i++){
        int nextY = y + dy[i];
        int nextX = x+dx[i];
        if(nextY <0 || nextY >=height || nextX<0 || nextX >=width){
            continue;
        }
        if(visited[nextY][nextX]){
            return false;
        }
    }
    return true;
}

void makeComb(int pickCount, int sy,int sx,long long totalSum){
    if(pickCount == totalPick){
        ans = max(ans,totalSum);
        return;
    }else{
        for(int i=sy;i<height;i++){
            for(int j=sx;j<width;j++){
                if(!visited[i][j] && checks(i,j)){
                    visited[i][j] = true;
                    makeComb(pickCount+1,i,j,totalSum+board[i][j]);
                    visited[i][j] = false;
                }
            }
            sx =0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width>>totalPick;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }

    memset(visited,false,sizeof(visited));
    makeComb(0,0,0,0);
    cout<<ans; 
}