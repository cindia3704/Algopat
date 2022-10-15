/*
    작성자: 김지수
    작성일: 2022/10/15
    백준 -- 미세먼지 안녕! (17144번)
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#include <cstring>
#define MAX 51
using namespace std; 
int height,width,turnCnt; 
int robotY1,robotX1,robotY2,robotX2; 

const int dy[4]={0,-1,0,1};
const int dx[4]={1,0,-1,0};

int board[MAX][MAX];

void print(){
    cout<<"\n ====  BOAD === "<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool OOB(int y,int x){
    return (y<0 || y>=height || x<0 || x>=width);
}

void spreadDust(){
    int temp[MAX][MAX];
    memset(temp,0,sizeof(temp));

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int now = board[i][j];
            if(now>0){
                int spreadCnt = 0;
                for(int d = 0;d<4;d++){
                    int nextY = i+ dy[d];
                    int nextX = j+ dx[d];
                    if(OOB(nextY,nextX) || board[nextY][nextX]==-1){
                        continue;
                    }else{
                        spreadCnt++;
                    }
                }
                int spreadAmt = floor((double)now / (double)5);
                for(int d = 0;d<4;d++){
                    int nextY = i+ dy[d];
                    int nextX = j+ dx[d];
                    if(OOB(nextY,nextX) || board[nextY][nextX]==-1){
                        continue;
                    }else{
                        temp[nextY][nextX]+=spreadAmt;
                    }
                }
                temp[i][j] += now-(spreadAmt*spreadCnt);
            }
        }
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = temp[i][j];
        }
    }
    board[robotY1][robotX1] = -1;
    board[robotY2][robotX2] = -1;
}

void moveRobot(int y,int x,int inc){
    int yDiff =y;
    if(inc != 1){
        yDiff = height-y-1;
    }
    int ny=y;
    int nx=x;
    int dir = 0;
    deque<int> dusts;
    for(int i=1;i<=width-1;i++){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        dusts.push_back(board[nextY][nextX]);
        ny = nextY;
        nx = nextX;
    }
    dir=(dir+inc)%4;
    for(int i=0;i<yDiff;i++){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        dusts.push_back(board[nextY][nextX]);
        ny = nextY;
        nx = nextX;
    }
    dir=(dir+inc)%4;
    for(int i=1;i<=width-1;i++){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        dusts.push_back(board[nextY][nextX]);
        ny = nextY;
        nx = nextX;
    }
    dir=(dir+inc)%4;
    for(int i=0;i<yDiff;i++){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        dusts.push_back(board[nextY][nextX]);
        ny = nextY;
        nx = nextX;
    }
    dusts.push_front(0);
    dusts.pop_back();
    dusts.pop_back();
    dusts.push_back(-1);
    ny=y;
    nx=x;
    dir = 0;
    for(int i=1;i<=width-1;i++){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        board[nextY][nextX] = dusts.front();
        dusts.pop_front();
        ny = nextY;
        nx = nextX;
    }
    dir=(dir+inc)%4;
    for(int i=0;i<yDiff;i++){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        board[nextY][nextX] = dusts.front();
        dusts.pop_front();
        ny = nextY;
        nx = nextX;
    }
    dir=(dir+inc)%4;
    for(int i=1;i<=width-1;i++){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        board[nextY][nextX] = dusts.front();
        dusts.pop_front();
        ny = nextY;
        nx = nextX;
    }
    dir=(dir+inc)%4;
    for(int i=0;i<yDiff;i++){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        board[nextY][nextX] = dusts.front();
        dusts.pop_front();
        ny = nextY;
        nx = nextX;
    }

}


void startGame(){
    for(int i=0;i<turnCnt;i++){
        spreadDust();
        moveRobot(robotY1,robotX1,1);
        moveRobot(robotY2,robotX2,3);
    }
}

int countDust(){
    int sum =0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]>0){
                sum+=board[i][j];
            }
        }
    }
    return sum; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>height>>width>>turnCnt;
    bool foundFirst = false;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
            if(board[i][j] == -1){
                if(!foundFirst){
                    foundFirst = true;
                    robotY1 = i;
                    robotX1 = j;
                }else{
                    robotY2 = i;
                    robotX2 = j; 
                }
            }
        }
    }
    startGame();
    cout<<countDust();
}