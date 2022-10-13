/*
    작성자: 김지수
    작성일: 2022/10/13
    코드트리 -- 미로 타워 디펜스 (39번)
*/

#include <iostream>
#include <algorithm>
#include <cstring> 
#include <deque>
#include <cmath>
#define MAX 26
using namespace std; 

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int scoreTotal=0;
int boardSize, stageCnt;
int board[MAX][MAX]; 
deque<int> arr;

void print(){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void attack(int dir,int dist){
    int sy = boardSize/2;
    int sx = boardSize/2; 

    for(int i=1;i<=dist;i++){
        int nextY = sy+dy[dir]*i;
        int nextX = sx+dx[dir]*i;
        if(board[nextY][nextX]>0){
            scoreTotal+=board[nextY][nextX];
            board[nextY][nextX] = 0;
        }
    }
}



void makeToArr(){
    arr.clear();
    int sy = boardSize/2;
    int sx = boardSize/2; 
    int dir = 2;
    int times = 1; 
    int i=0;

    while(true){
        for(int j=0;j<times;j++){
            int nextY = sy+dy[dir];
            int nextX = sx+dx[dir];
            if(board[nextY][nextX]!=0){
                arr.push_back(board[nextY][nextX]);
            }
            sy = nextY;
            sx = nextX;
        }
        if(sy == 0 && sx == 0){
            break;
        }
        dir = (dir-1+4)%4;
        i++;
        if(i!=0 && i%2==0){
            if(times==boardSize-1){
                continue;
            }else{
                times++;
            }
        }
    }
}

void bomb(){
    while(true){
        deque<int> tempDQ;
        bool foundPop = false;
        for(int i=0;i<arr.size();){
            int now = arr[i];
            int cnt = 1; 
            int ny = i;
            while(true){
                int next = ny+1; 
                if(next<arr.size() && arr[next]==now){
                    ny = next;
                    cnt++;
                }else{
                    break;
                }
            }
            if(cnt>=4){
                foundPop = true;
                scoreTotal+=(now*cnt);
            }else{
                for(int j=i;j<i+cnt;j++){
                    tempDQ.push_back(arr[j]);
                }
            }
            i+=cnt;
        }
        if(!foundPop){
            break;
        }
        arr = tempDQ;
    }
}

void makeFreq(){
    deque<int> freq;

    for(int i=0;i<arr.size();){
        int now = arr[i];
        int cnt = 1; 
        int ny = i;
        while(true){
            int next = ny+1; 
            if(next<arr.size() && arr[next]==now){
                ny = next;
                cnt++;
            }else{
                break;
            }
        }
        freq.push_back(cnt);
        freq.push_back(now);
        i+=cnt;
    }
    arr = freq;
}

void makeToBoard(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] = 0; 
        }
    }

    int sy = boardSize/2;
    int sx = boardSize/2; 
    int dir = 2;
    int times = 1; 
    int i=0;
    while(true){
        for(int j=0;j<times;j++){
            if(arr.size()>0){
                int nextY = sy+dy[dir];
                int nextX = sx+dx[dir];
                board[nextY][nextX] = arr.front();
                arr.pop_front();
                sy = nextY;
                sx = nextX;
            }else{
                break;
            }
        }
        if(arr.size()==0){
            break;
        }
        if(sy == 0 && sx == 0){
            break;
        }
        dir = (dir-1+4)%4;
        i++;
        if(i!=0 && i%2==0){
            if(times==boardSize-1){
                continue;
            }else{
                times++;
            }
        }
    }

}

void startGame(){
    for(int i=0;i<stageCnt;i++){
        int dir,dist;
        cin>>dir>>dist;
        attack(dir,dist);
        makeToArr();
        bomb();
        makeFreq();
        makeToBoard();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin>>boardSize>>stageCnt;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }
    startGame();
    cout<<scoreTotal<<endl;
}