/*
    작성자: 김지수
    작성일: 2022/10/05
    백준 -- 붐버맨 (16918번)
*/

#include <iostream>
#include <cstring>
#define MAX 201
using namespace std; 

const int dy[4]={0,0,1,-1};
const int dx[4]={1,-1,0,0};

int height,width,totalTime;
int board[MAX][MAX];
int temp[MAX][MAX];

void print(){
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<endl;
}

void fillOtherArea(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==0){
                board[i][j] = 3;
            }else{
                board[i][j]--;
            }
        }
    }
}

void react(int y,int x){
    temp[y][x]=0;
    for(int i=0;i<4;i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(nextY<0 || nextY>=height || nextX<0 || nextX >=width){
            continue;
        }
        temp[nextY][nextX] = 0;
    }
}

void bomb(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            temp[i][j] = board[i][j];
        }
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j] == 1){
                react(i,j);
            }else{
                if(temp[i][j]>0){
                    temp[i][j]--;
                }
            }
        }
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = temp[i][j];
        }
    }
}

void startGame(){
    for(int i=0;i<totalTime;i++){
        if(i%2==0){
            fillOtherArea();
        }else{
            bomb();
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width>>totalTime;

    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            if(l[j]=='.'){
                board[i][j] =0;
            }else{
                board[i][j] = 2;
            }
        }
    }
    totalTime--;
    startGame();
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==0){
                cout<<'.';
            }else{
                cout<<"O";
            }
        }
        cout<<"\n";
    }
}