/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 마법사 상어와 토네이도 (20057번)
*/
#include <iostream>
#include <cstring>
#define MAX 500
using namespace std; 

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

int boardSize;
int board[MAX][MAX];
int dustAmt=0;

void print(){
    cout<<"\n=====PRINT===="<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<" dustAmt: "<<dustAmt<<endl;
}

void check(int y,int x,int amount){
    if(y<0 || y>=boardSize ||x<0|| x>=boardSize){
        dustAmt+=amount;
    }else{
        board[y][x]+=amount;
    }
}

void calcBoard(int tarY,int tarX,int dir){
    int resultY = tarY+dy[dir];
    int resultX = tarX+dx[dir];
    int total = board[tarY][tarX];
    int resultAmt = total;
    int add2 = total*0.02;
    int add7 = total*0.07;
    int add10 = total*0.10;
    int add1= total*0.01;
    int add5 = total*0.05;
    resultAmt -=2*add2;
    resultAmt -=2*add7;
    resultAmt -=2*add10;
    resultAmt -=2*add1;
    resultAmt -=add5;
    if(dir == 0){        
        check(tarY-2,tarX,add2);
        check(tarY-1,tarX,add7);
        check(tarY-1,tarX-1,add10);
        check(tarY-1,tarX+1,add1);
        check(tarY,tarX-2,add5);
        check(tarY+1,tarX-1,add10);
        check(tarY+1,tarX,add7);
        check(tarY+1,tarX+1,add1);
        check(tarY+2,tarX,add2);
    }
    if(dir == 1){
        check(tarY,tarX-2,add2);
        check(tarY,tarX-1,add7);
        check(tarY+1,tarX-1,add10);
        check(tarY-1,tarX-1,add1);
        check(tarY+2,tarX,add5);
        check(tarY+1,tarX+1,add10);
        check(tarY,tarX+1,add7);
        check(tarY-1,tarX+1,add1);
        check(tarY,tarX+2,add2);
    }
    if(dir == 2){
        check(tarY-2,tarX,add2);
        check(tarY-1,tarX,add7);
        check(tarY-1,tarX+1,add10);
        check(tarY-1,tarX-1,add1);
        check(tarY,tarX+2,add5);
        check(tarY+1,tarX+1,add10);
        check(tarY+1,tarX,add7);
        check(tarY+1,tarX-1,add1);
        check(tarY+2,tarX,add2);
    }
    if(dir == 3){
        check(tarY,tarX-2,add2);
        check(tarY,tarX-1,add7);
        check(tarY-1,tarX-1,add10);
        check(tarY+1,tarX-1,add1);
        check(tarY-2,tarX,add5);
        check(tarY-1,tarX+1,add10);
        check(tarY,tarX+1,add7);
        check(tarY+1,tarX+1,add1);
        check(tarY,tarX+2,add2);
    }
    if(resultY<0 || resultY>=boardSize || resultX<0 || resultX>=boardSize){
        dustAmt+=resultAmt;
    }else{
        board[resultY][resultX]+=resultAmt;
    }
    board[tarY][tarX]=0;
}

void startGame(){
    int ny = boardSize/2;
    int nx = boardSize/2; 
    int stage = 1;
    int dir = 0;
    int nextY= 0;
    int nextX = 0;
    int cnt =1;
    while(cnt<=2*boardSize-1){
        //cout<<"ny: "<<ny<<" nx:"<<nx<<" stage:"<<stage<<"  cnt:"<<cnt<<"  dir:"<<dir<<endl;
        if(ny==0 && nx ==0){
            break;
        }
        for(int i=1;i<=stage;i++){
            nextY = ny+dy[dir]*i;
            nextX = nx+dx[dir]*i;
            //cout<<"    to: "<<nextY<<" , "<<nextX<<endl;
            calcBoard(nextY,nextX,dir);
            //print();
        }
        ny = nextY;
        nx = nextX;
        dir=(dir+1)%4;
        cnt++;
        if(cnt%2==1){
            if(cnt!=2*boardSize-1){
                stage++;
            }
        }
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
    cout<<dustAmt;
}