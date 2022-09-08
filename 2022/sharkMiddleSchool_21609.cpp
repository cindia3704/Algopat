/*
    작성자: 김지수
    작성일: 2022/09/08
    백준 -- 상어 중학교 (21609번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 21
#define BLACK -1
#define RAINBOW 0
#define EMPTY -3
using namespace std; 

struct BLOCK{
    int sy,sx;
    int rainbowCnt;
    int boardCnt; 
};

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int boardSize, colorCnt;
int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];
vector<BLOCK> boardList; 
int totalScore = 0;

void print(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool cmp(BLOCK &a, BLOCK &b){
    if(a.boardCnt == b.boardCnt){
        if(a.rainbowCnt == b.rainbowCnt){
            if(a.sy == b.sy){
                return a.sx > b.sx;
            }
            return a.sy>b.sy;
        }
        return a.rainbowCnt>b.rainbowCnt;
    }
    return a.boardCnt>b.boardCnt;
}

void bfs(int y,int x){
    memset(visited,false,sizeof(visited));
    BLOCK newBlock;
    int boardColor = board[y][x];
    newBlock.sy = y;
    newBlock.sx = x; 
    newBlock.rainbowCnt = 0;
    newBlock.boardCnt=0;
    queue<pair<int,int> > q;
    visited[y][x] =true;
    q.push(make_pair(y,x));
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        newBlock.boardCnt++;
        if(board[now.first][now.second]==RAINBOW){
            newBlock.rainbowCnt++;
        }else{
            if(now.first<newBlock.sy){
                newBlock.sy = now.first;
                newBlock.sx = now.second;
            }else if(now.first==newBlock.sy){
                if(now.second<newBlock.sx){
                    newBlock.sy = now.first;
                    newBlock.sx = now.second;
                }
            }
            // newBlock.sy = min(newBlock.sy,now.first);
            // newBlock.sx = min(newBlock.sx,now.second);
        }
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(nextY<0 || nextY>=boardSize || nextX <0 || nextX>=boardSize){
                continue;
            }
            if(!visited[nextY][nextX] && (board[nextY][nextX] == RAINBOW || board[nextY][nextX]==boardColor)){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    if(newBlock.boardCnt>=2){
        boardList.push_back(newBlock);
    }
}

void gravity(){
    for(int i=0;i<boardSize;i++){
        for(int j=boardSize-1;j>=0;j--){
            if(board[j][i] == EMPTY){
                bool foundBlock = false;
                int idx = j;
                while(!foundBlock && idx>=0){
                    if(board[idx][i]==EMPTY){
                        idx--;
                    }else{
                        foundBlock = true;
                        if(board[idx][i] != BLACK){
                            //cout<<"SWAP ("<<idx<<" , "<<i<<")   &  ("<<j<<" , "<<i<<")"<<endl;
                            swap(board[idx][i],board[j][i]);
                        }
                    }
               }
            }
        }
    }
}
void turnCounterClock(){
    memset(temp,0,sizeof(temp));
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            temp[i][j] = board[j][boardSize-i-1];
        }
    }
     for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] = temp[i][j];
        }
    }
}

void removeBlock(BLOCK a){
    totalScore+=(a.boardCnt*a.boardCnt);

    bool removed[MAX][MAX];
    memset(removed,false,sizeof(removed));
    queue<pair<int,int> > q; 
    removed[a.sy][a.sx] = true;
    q.push(make_pair(a.sy,a.sx));
    int boardColor = board[a.sy][a.sx];

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        board[now.first][now.second] = EMPTY;
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(nextY<0 || nextY>=boardSize || nextX <0 || nextX>=boardSize){
                continue;
            }
            if(!removed[nextY][nextX] && (board[nextY][nextX] == RAINBOW || board[nextY][nextX]==boardColor)){
                removed[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}


void findBlockGroup(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]!=BLACK && board[i][j]!=EMPTY && board[i][j]!=RAINBOW){
                bfs(i,j);
            }
        }
    }
}

void startGame(){
    findBlockGroup();
    while(!boardList.empty()){
        sort(boardList.begin(),boardList.end(),cmp);
        removeBlock(boardList[0]);
        gravity();
        turnCounterClock();
        gravity();
        boardList.clear();
        findBlockGroup();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>colorCnt;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }

    startGame();
    cout<<totalScore;

}