/*
    작성자: 김지수
    작성일: 2022/08/22
    백준 -- 사탕 게임 (3085번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 51
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4]={-1,0,1,0};

int boardSize; 
char board[MAX][MAX];
char temp[MAX][MAX];
bool seen[MAX][MAX];
int ans = 0;

//모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행) 구하기 
void findRow(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            // 다음에 보는 같은 색은 이전에 보았다면 무조건 길이가 더 작음 -> 안봐도 되서 방문처리 
            if(!seen[i][j]){
                seen[i][j] = true;
                int count = 1;
                char now = temp[i][j];
                for(int k=j+1;k<boardSize;k++){
                    if(temp[i][k] == now){
                        seen[i][k] = true;
                        count++;
                    }
                    else{
                        break;
                    }
                }
                ans = max(ans,count);
            }
        }
    }
}
//모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(열) 구하기
void findCol(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!seen[j][i]){
                seen[j][i] = true;
                int count = 1;
                char now = temp[j][i];
                for(int k=j+1;k<boardSize;k++){
                    if(temp[k][i] == now){
                        seen[k][i] = true;
                        count++;
                    }
                    else{
                        break;
                    }
                }
                ans = max(ans,count);
            }
        }
    }
}

// 보드를 템프로 복사 
void copyBoard(){
     for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            temp[i][j] = board[i][j];
        }
     }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        string s; 
        cin>>s;
        for(int j=0;j<s.length();j++){
            board[i][j] = s[j];
            temp[i][j] = board[i][j];
        }
    }
    // 한번도 안옮겼을때 정답일수 있어서 
    memset(seen,false,sizeof(seen));
    findRow();
    memset(seen,false,sizeof(seen));
    findCol();

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            char now = board[i][j];
            // 현 위치에서 인접한 곳 보며 
            for(int k=0;k<4;k++){
                int nextY = i+dy[k];
                int nextX = j+dx[k];
                if(nextY<0 || nextY >=boardSize || nextX<0 || nextX>=boardSize){
                    continue;
                }
                // 현재와 색이 다르면 swap후 가장 긴 행 / 열 구하기 
                if(board[nextY][nextX]!=now){
                    copyBoard();
                    swap(temp[i][j],temp[nextY][nextX]);
                    memset(seen,false,sizeof(seen));
                    findRow();
                    memset(seen,false,sizeof(seen));
                    findCol();
                }
            }
        }
    }
    cout<<ans;

}
