/*
    작성자: 김지수
    작성일: 2022/07/17
    백준 -- 알파벳 (1987번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 21
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int height,width;
char board[MAX][MAX];
bool used[26];  // 알파벳 총 26개라서 크기 26으로 
int ans =0; 

void dfs(int y,int x,int count){
    // 현재 칸의 알파벳 방문처리 
    int alpha = board[y][x] -'A';
    used[alpha] = true;
    // 최댓값 업데이트 
    ans = max(ans,count);
    // 상하좌우 보면서 
    for(int i=0;i<4;i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(nextY<0 || nextY >=height ||nextX<0 || nextX>=width){
            continue;
        }
        // 다음으로 방문할 곳의 알파벳 사용했는지 확인 
        int nextAlpha = board[nextY][nextX]-'A';
        if(!used[nextAlpha]){
            // 사용안했으면 사용처리 하고 
            used[nextAlpha] = true;
            // 다음 위치 보고 
            dfs(nextY,nextX,count+1);
            // 돌아오면 다시 안씀으로 바꾸기 
            used[nextAlpha] = false;
        }
    }
    return;
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

    memset(used,false,sizeof(used));
    // 첫 칸도 포함하니까 count =1 로 시작 
    dfs(0,0,1);
    cout<<ans;
}