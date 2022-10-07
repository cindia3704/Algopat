/*
    작성자: 김지수
    작성일: 2022/10/07
    코드트리 -- 나무박멸 (47번)
*/
#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 21
using namespace std; 

const int dy[4] = {0,1,0,-1};
const int dx[4] = {-1,0,1,0};

const int diagY[4] = {-1,-1,1,1};
const int diagX[4] = {-1,1,-1,1};
int boardSize,yearCnt,spreadRange,spreadYear;
int board[MAX][MAX];
bool isStopped[MAX][MAX];
int yearLeft[MAX][MAX];
int stopCnt = 0;

void print(){
    cout<<"\n======"<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j] << " ";
        }
        cout<<endl;
    }
}

bool OOB(int y,int x){
    if(y<0 || y>=boardSize || x<0 || x>=boardSize){
        return true;
    }
    return false;
}

void growTree(){
    int addCnt[MAX][MAX];
    memset(addCnt,0,sizeof(addCnt));
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]>0){
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int nextY = i+dy[k];
                    int nextX = j+dx[k];
                    if(OOB(nextY,nextX)){
                        continue;
                    }
                    if(board[nextY][nextX]>0){
                        cnt++;
                    }
                }
                addCnt[i][j]=cnt;
            }
        }
    }

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] += addCnt[i][j];
        }
    }

}

void spreadTree(){
    int temp[MAX][MAX];
    memset(temp,0,sizeof(temp));

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]>0){
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int nextY = i+dy[k];
                    int nextX = j+dx[k];
                    if(OOB(nextY,nextX)){
                        continue;
                    }
                    if(board[nextY][nextX]==0 &&!isStopped[nextY][nextX]){
                        cnt++;
                    }
                }
                if(cnt>0){
                    int treeCnt = floor(board[i][j]/cnt);
                    for(int k=0;k<4;k++){
                        int nextY = i+dy[k];
                        int nextX = j+dx[k];
                        if(OOB(nextY,nextX)){
                            continue;
                        }
                        if(board[nextY][nextX]==0 && !isStopped[nextY][nextX]){
                            temp[nextY][nextX] +=treeCnt;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] += temp[i][j];
        }
    }

}

pair<int,int> findLargestSpread(){
    int maxSpreadCnt = 0;
    int y=boardSize;
    int x=boardSize;
    int spreadCnt[MAX][MAX];
    memset(spreadCnt,0,sizeof(spreadCnt));
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]>0){
                int addAmt = board[i][j];
                for(int dir=0;dir<4;dir++){
                    for(int k=1;k<=spreadRange;k++){
                        int nextY = i+diagY[dir]*k;
                        int nextX = j+diagX[dir]*k;
                        if(OOB(nextY,nextX)){
                            break;
                        }else{
                            if(board[nextY][nextX]==-1 || board[nextY][nextX]==0 || board[nextY][nextX]==-2){
                                break;
                            }else{
                                addAmt+=board[nextY][nextX];
                            }
                        }
                    }
                }
                spreadCnt[i][j] = addAmt;
            }
        }
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(spreadCnt[i][j]>maxSpreadCnt){
                maxSpreadCnt = spreadCnt[i][j];
                y=i;
                x=j;
            }
        }
    }
    stopCnt+=spreadCnt[y][x];
    return make_pair(y,x);
}

void spreadChemical(int y,int x){
    board[y][x]=-2;
    yearLeft[y][x] = spreadYear;
    for(int dir=0;dir<4;dir++){
        for(int k=1;k<=spreadRange;k++){
            int nextY = y+diagY[dir]*k;
            int nextX = x+diagX[dir]*k;
            if(OOB(nextY,nextX)){
                break;
            }else{
                if(board[nextY][nextX]==-1 || board[nextY][nextX]==0 || board[nextY][nextX]==-2){
                    if(board[nextY][nextX]==0|| board[nextY][nextX]==-2){
                        board[nextY][nextX] = -2;
                        yearLeft[nextY][nextX] = spreadYear;
                    }
                    break;
                }
                else{
                    board[nextY][nextX] = -2;
                    yearLeft[nextY][nextX] = spreadYear;
                }
            }
        }
    }
}
void decreaseSpreadYear(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(yearLeft[i][j]>0){
                yearLeft[i][j]--;
                if(yearLeft[i][j]==0){
                    board[i][j]=0;
                }
            }
        }
    }
}

void startGame(){
    for(int i=0;i<yearCnt;i++){
        growTree();
        spreadTree();
        if(i!=0){
            decreaseSpreadYear();
        }
        pair<int,int> pos = findLargestSpread();
        spreadChemical(pos.first,pos.second);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>boardSize>>yearCnt>>spreadRange>>spreadYear;
    memset(isStopped,false,sizeof(isStopped));

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }
    startGame();
    cout<<stopCnt;
}