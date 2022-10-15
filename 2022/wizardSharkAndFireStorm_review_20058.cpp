/*
    작성자: 김지수
    작성일: 2022/10/15
    백준 -- 마법사 상어와 파이어스톰 (20058번)
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 70
using namespace std; 

const int dy[4] = {0,1,0,-1};
const int dx[4] ={-1,0,1,0};

int boardSize, turnCnt; 
int board[MAX][MAX];
int temp[MAX][MAX];
int decAmt[MAX][MAX];
bool visited[MAX][MAX];

void print(){
    cout<<"\n===board"<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool OOB(int y,int x){
    return (y<0 || y>=boardSize || x<0 || x>=boardSize);
}

void rotate(int bSize){
    int tmp[MAX][MAX];
    for(int i=0;i<bSize;i++){
        for(int j=0;j<bSize;j++){
            tmp[i][j] = temp[bSize-1-j][i];
        }
    }
   
    for(int i=0;i<bSize;i++){
        for(int j=0;j<bSize;j++){
            temp[i][j] = tmp[i][j];
        }
    }
}

void rotateBoard(int l){
    int bSize = pow(2,l);
    for(int i=0;i<boardSize;){
        for(int j=0;j<boardSize;){
            for(int k=0;k<bSize;k++){
                for(int m=0;m<bSize;m++){
                    temp[k][m] = board[i+k][j+m];
                }
            }
            rotate(bSize);
            for(int k=0;k<bSize;k++){
                for(int m=0;m<bSize;m++){
                    board[i+k][j+m] = temp[k][m];
                }
            }
            j+=bSize;
        }
        i+=bSize;
    }
}

void decreaseIce(){
    memset(decAmt,0,sizeof(decAmt));
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            int isIceCnt = 0;
            for(int k=0;k<4;k++){
                int nextY = i+dy[k];
                int nextX = j+dx[k];
                if(OOB(nextY,nextX)){
                    continue;
                }
                if(board[nextY][nextX]>0){
                    isIceCnt++;
                }
            }
            if(isIceCnt<3){
                decAmt[i][j]+=1;
            }
        }
    }

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] = max((board[i][j]-decAmt[i][j]),0);
        }
    }
}

void startGame(){
    for(int i=0;i<turnCnt;i++){
        int lev;
        cin>>lev; 
        rotateBoard(lev);
       // print();
        decreaseIce();
        // cout<<"\nAF DECREASE ICE"<<endl;
        // print();
    }
}

int sumIce(){
    int sum = 0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
             sum+=board[i][j];
        }
    }
    return sum;
}

int bfs(int y,int x){
    queue<pair<int,int> > q; 
    int iceSize = 0;
    visited[y][x] = true;
    q.push(make_pair(y,x));

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        iceSize++;

        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second+dx[i];
            if(OOB(nextY,nextX)){
                continue;
            }else{
                if(!visited[nextY][nextX] && board[nextY][nextX]>0){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextY,nextX));
                }
            }
        }
    }
    return iceSize;
}

int maxIce(){
    int maxSize =0;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!visited[i][j] && board[i][j]>0){
                maxSize= max(bfs(i,j),maxSize);
            }
        }
    }
    return maxSize; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n;
    cin>>n>>turnCnt;
    boardSize = pow(2,n);
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }
    startGame();
    cout<<sumIce()<<'\n';
    cout<<maxIce();
}