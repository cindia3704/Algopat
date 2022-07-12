/*
    작성자: 김지수
    작성일: 2022/07/13
    백준 -- 스도쿠 (2239번)
*/

#include <iostream>
#include <cstring>
using namespace std; 

int board[9][9];
bool usedY[9][10];
bool usedX[9][10];
bool usedXY[9][10];
bool found = false;

int calcDir(int y,int x){
    int dir =0;
        if(y>=0 && y<3 && x>=0 && x<3){
            dir = 0;
        }else if(y>=0 && y<3 && x>=3 && x<6){
            dir = 1;
        }else if(y>=0 && y<3 && x>=6 && x<9){
            dir = 2;
        }else if(y>=3 && y<6 && x>=0 && x<3){
            dir = 3;
        }else if(y>=3 && y<6 && x>=3 && x<6){
            dir = 4;
        }else if(y>=3 && y<6 && x>=6 && x<9){
            dir = 5;
        }else if(y>=6 && y<9 && x>=0 && x<3){
            dir = 6;
        }else if(y>=6 && y<9 && x>=3 && x<6){
            dir = 7;
        }else if(y>=6 && y<9 && x>=6 && x<9){
            dir = 8;
        }
    return dir; 
}

void makeComb(int y,int x,bool canContinue){
    if(!found){ // 입력이 모두 0일때 여러개의 답이 나올 수  있음.
    if(y==9){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<board[i][j];
                }
                cout<<endl;
            }
            found = true;
        }
        if(!canContinue){
            return;
        }
        if(x==9){
            makeComb(y+1,0,canContinue);
        }
        if(board[y][x]!=0){
            makeComb(y,x+1,canContinue);
        }else{
            bool foundNext = false;
            int dir = calcDir(y,x);
            for(int i=1;i<=9;i++){
                if(!usedY[y][i] && !usedX[x][i] && !usedXY[dir][i]){
                    foundNext = true;
                    usedY[y][i] = true;
                    usedX[x][i] = true;
                    usedXY[dir][i]=true;
                    board[y][x] = i;
                    makeComb(y,x+1,foundNext);
                    usedY[y][i] = false;
                    usedX[x][i] = false;
                    usedXY[dir][i] = false;
                    board[y][x] = 0;
                }
            }
            if(!foundNext){
                makeComb(y,x,foundNext);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(usedX,false,sizeof(usedX));
    memset(usedY,false,sizeof(usedY));
    memset(usedXY,false,sizeof(usedXY));
    for(int i=0;i<9;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.size();j++){
            board[i][j] = l[j]-'0';
            if(board[i][j]!=0){
                usedY[i][board[i][j]] = true;
                usedX[j][board[i][j]] = true;
                int dir = calcDir(i,j);
                usedXY[dir][board[i][j]] = true;
            }
        }
    }
    makeComb(0,0,true);
}