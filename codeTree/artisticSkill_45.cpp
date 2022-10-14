/*
    작성자: 김지수
    작성일: 2022/10/14
    코드트리 -- 예술성 (45번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 30
using namespace std; 

const int dy[4]={0,1,0,-1};
const int dx[4] = {-1,0,1,0};

int boardSize; 
bool visited[MAX][MAX];
bool visitedGroup[MAX*MAX];
int board[MAX][MAX];    // 보드 
int group[MAX][MAX];    // 보드 각 위치가 어떤 그룹에 속하는지 
int groupCnt[MAX*MAX];  // 각 그룹이 몇개의 칸으로 이루어져 있는지 
int groupColor[MAX*MAX];
int adjCnt[MAX*MAX][MAX*MAX];
int rotateTemp[MAX][MAX];
int totalGroups;
long long score=0;

void printGroup(){
    cout<<"\n===group"<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<group[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"GROUP CNT:"<<endl;
    for(int i=0;i<totalGroups;i++){
        cout<<"group # "<<i<<"  =  "<<groupCnt[i]<<endl;
    }
    cout<<endl;
}

void printBoard(){
    cout<<"\n===BOARD"<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool OOB(int y,int x){
    return (y<0 || y>=boardSize || x<0 || x>=boardSize);
}

void bfs(int y,int x,int groupIdx){
    int targetNum = board[y][x];
    groupColor[groupIdx] = targetNum;
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));
    int cnt = 0;
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        group[now.first][now.second] = groupIdx;
        cnt++;
        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX =now.second+dx[i];
            if(OOB(nextY,nextX)){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]==targetNum){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    groupCnt[groupIdx] = cnt;
}

void findGroup(){
    memset(visited,false,sizeof(visited));
    memset(groupCnt,0,sizeof(groupCnt));

    int groupNum = 0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!visited[i][j]){
                bfs(i,j,groupNum);
                groupNum++;
            }
        }
    }
    totalGroups= groupNum;
}

void cntAdj(int y,int x){
    int targetNum = group[y][x];
    queue<pair<int,int> > q; 
    visitedGroup[targetNum] = true;
    visited[y][x] = true;
    q.push(make_pair(y,x));
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX =now.second+dx[i];
            if(OOB(nextY,nextX)){
                continue;
            }
            if(!visited[nextY][nextX] && group[nextY][nextX]==targetNum){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }else{
                if(group[nextY][nextX]!=targetNum){
                    adjCnt[targetNum][group[nextY][nextX]]++;
                }
            }
        }
    }
    
}

// 각 그룹이 서로 몇개의 칸을 맞닫는지 확인
void findAdjCnt(){
    memset(visitedGroup,false,sizeof(visitedGroup));
    memset(adjCnt,0,sizeof(adjCnt));

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!visitedGroup[group[i][j]]){
                memset(visited,false,sizeof(visited));
                cntAdj(i,j);
            }
        }
    }
}
void calcScore(){
    long long roundScore = 0;
    for(int i=0;i<totalGroups-1;i++){
        for(int j=i+1;j<totalGroups;j++){
            roundScore+=((groupCnt[i]+groupCnt[j])*groupColor[i]*groupColor[j]*adjCnt[i][j]);
        }
    }
    score+=roundScore;
}

void rotate(int bSize){
    int tempArr[MAX][MAX];
    for(int i=0;i<bSize;i++){
        for(int j=0;j<bSize;j++){
            tempArr[i][j] = rotateTemp[bSize-j-1][i];
        }
    }
    for(int i=0;i<bSize;i++){
        for(int j=0;j<bSize;j++){
            rotateTemp[i][j] = tempArr[i][j];
        }
    }
}
void rotatePart(int y,int x,int bSize){
    for(int i=0;i<bSize;i++){
        for(int j=0;j<bSize;j++){
            rotateTemp[i][j] = board[i+y][j+x];
        }
    }
    rotate(bSize);
}


void rotateArr(){
    int tempArr[MAX][MAX];
    memset(tempArr,0,sizeof(tempArr));
    int cy=boardSize/2;
    int cx = boardSize/2; 
    tempArr[cy][cx] = board[cy][cx];
    int nowDir = 0;
    for(int i=0;i<4;i++){
        int toDir = (nowDir+1)%4;
        for(int j=1;j<=boardSize/2;j++){
            int nextY = cy+dy[nowDir]*j;
            int nextX = cx+dx[nowDir]*j;
            int toY = cy+dy[toDir]*j;
            int toX = cx+dx[toDir]*j;
            tempArr[toY][toX] = board[nextY][nextX];
        }
        nowDir =(nowDir+1)%4;
    }

    int halfSize = boardSize/2;
    int ny = 0;
    int nx = 0;
    rotatePart(ny,nx,halfSize);
    for(int i=0;i<halfSize;i++){
        for(int j=0;j<halfSize;j++){
            tempArr[i+ny][j+nx] = rotateTemp[i][j];
        }
    }
    ny = halfSize+1;
    nx = 0;
    rotatePart(ny,nx,halfSize);
    for(int i=0;i<halfSize;i++){
        for(int j=0;j<halfSize;j++){
            tempArr[i+ny][j+nx] = rotateTemp[i][j];
        }
    }
    
    nx = halfSize+1;
    ny = 0;
    rotatePart(ny,nx,halfSize);
    for(int i=0;i<halfSize;i++){
        for(int j=0;j<halfSize;j++){
            tempArr[i+ny][j+nx] = rotateTemp[i][j];
        }
    }
    ny = halfSize+1;
    nx = halfSize+1;
    rotatePart(ny,nx,halfSize);
    for(int i=0;i<halfSize;i++){
        for(int j=0;j<halfSize;j++){
            tempArr[i+ny][j+nx] = rotateTemp[i][j];
        }
    }

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] = tempArr[i][j];
        }
    }
}

void startGame(){
    findGroup();
    findAdjCnt();
    calcScore();
    for(int i=0;i<3;i++){
        rotateArr();
        findGroup();
        findAdjCnt();
        calcScore();
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }
    startGame();
    cout<<score;
}