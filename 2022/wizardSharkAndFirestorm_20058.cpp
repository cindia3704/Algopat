/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 마법사 상어와 파이어스톰 (20058번)
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define MAX 65  // 최대가 
using namespace std; 

const int dy[4] = {1,0,-1,0};
const int dx[4] = {0,1,0,-1};

int boardSize, totalTurn; 
int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];

void rotate(int y,int x,int divSize){
    // 일단 돌리려는 보드 부분 복사하기 
    int tempArr[divSize][divSize];
    for(int i=0;i<divSize;i++){
        for(int j=0;j<divSize;j++){
            tempArr[i][j] = board[i+y][j+x];
        }
    }
    // 90도 회전 
    for(int i=0;i<divSize;i++){
        for(int j=0;j<divSize;j++){
            temp[i+y][j+x] = tempArr[divSize-j-1][i];
        }
    }
}

//먼저 격자를 2L × 2L 크기의 부분 격자로 나눈다.
void divideBoard(int divSize){
    // 모든 칸 돌면서 2^L x 2^L 첫 위치 정하기 
    for(int i=0;i<boardSize;){
        for(int j=0;j<boardSize;){
            rotate(i,j,divSize);
            j+=divSize; // 2^L 만큼 증가 
        }
        i+=divSize; // 2^L 만큼 증가 
    }

    // 보드 돌린 결과 보드에 옮기기 
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] = temp[i][j];
        }
    }
}

void findIce(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            int IceCnt = 0;
            for(int k=0;k<4;k++){
                int nextY = i+dy[k];
                int nextX = j+dx[k];
                if(nextY<0 || nextY >=boardSize || nextX <0 || nextX>=boardSize){
                    continue;
                }else{
                    if(board[nextY][nextX]>0){
                        IceCnt++;
                    }
                }
            }
            if(IceCnt<3){
                temp[i][j] = max(temp[i][j]-1 , 0);
            }
        }
    }

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] = temp[i][j];
        }
    }
}

//남아있는 얼음 A[r][c]의 합
long long findSum(){
    long long sum = 0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            sum+=board[i][j];
        }
    }
    return sum;
}

int bfs(int y,int x){
    int cnt = 0;
    queue<pair<int,int> > q; 
    q.push(make_pair(y,x));
    visited[y][x] = true;
    while(!q.empty()){
        pair<int,int> now = q.front();
        cnt++;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second +dx[i];
            if(nextY<0 ||nextY>=boardSize || nextX <0 || nextX >=boardSize){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]>0){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    return cnt; 
}

//남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
int findMaxIce(){
    int maxIce = 0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!visited[i][j] && board[i][j]>0){
                maxIce = max(maxIce,bfs(i,j));
            }
        }
    }
    return maxIce;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int boardExp;
    memset(visited,false,sizeof(visited));
    cin>>boardExp>>totalTurn;
    boardSize = pow(2,boardExp);

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<totalTurn;i++){
        int num;
        cin>>num;
        divideBoard(pow(2,num));
        findIce();
    }

    cout<<findSum()<<'\n';
    cout<<findMaxIce();

}