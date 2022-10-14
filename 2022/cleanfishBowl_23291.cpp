/*
    작성자: 김지수
    작성일: 2022/10/14
    백준 -- 어항 정리 (23291번)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <deque>
#define MAX 101
using namespace std;

int tankCnt,targetDiff;
int board[MAX][MAX];
int rotateArr[MAX][MAX];

const int dx[2]={0,1};
const int dy[2] = {1,0};

void printRotateArr(int h,int w){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<rotateArr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void printBoard(){
    cout<<"\n BOARD"<<endl;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool OOB(int y,int x){
    return (y<0 || y>=tankCnt || x<0 || x>=tankCnt);
}
void addToMinTank(){
    vector<int> idx; 
    int minNum = 0x7fffffff;
    for(int i=0;i<tankCnt;i++){
        if(minNum>board[0][i] && board[0][i]!=-1){
            idx.clear();
            minNum = board[0][i];
            idx.push_back(i);
        }else if(minNum == board[0][i]){
            idx.push_back(i);
        }
    }
    for(int i=0;i<idx.size();i++){
        board[0][idx[i]]+=1;
    }
}

bool check(){
    int maxNum = -1;
    int minNum = 0x7fffffff;
    for(int i=0;i<tankCnt;i++){
        minNum = min(minNum,board[0][i]);
        maxNum = max(maxNum,board[0][i]);
    }
    if(maxNum-minNum <=targetDiff){
        return true;
    }else{
        return false;
    }
}

void rotate(int h,int w){
    int tempArr[MAX][MAX];
    int boardS = max(h,w);
    for(int i=0;i<boardS;i++){
        for(int j=0;j<boardS;j++){
            tempArr[i][j]= -1;
        }
    }

    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            tempArr[i][j] = rotateArr[j][w-1-i];
        }
    }

    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            rotateArr[i][j] = tempArr[i][j];
        }
    }
}

void clean(){
    int idx = 0;
    int w = 1; 
    int h = 1; 
    while(tankCnt-(idx+w-1)>h){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                rotateArr[i][j] = board[i][j+idx];
                board[i][j+idx] = -1;
            }
        }
        rotate(h,w);
        swap(w,h);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                board[i+1][j+idx+h] = rotateArr[i][j];
            }
        }
        idx+=h;
        h++;
    }
}

void moveFish(){
    int tempArr[MAX][MAX];
    for(int i=0;i<tankCnt;i++){
        for(int j=0;j<tankCnt;j++){
            tempArr[i][j]= board[i][j];
        }
    }

    for(int i=0;i<tankCnt;i++){
        for(int j=0;j<tankCnt;j++){
            if(board[i][j] != -1){
                int now = board[i][j];
                for(int k=0;k<2;k++){
                    int nextY = i+dy[k];
                    int nextX = j+dx[k];
                    if(OOB(nextY,nextX) || board[nextY][nextX]==-1){
                        continue;
                    }else{
                        int next = board[nextY][nextX];
                        int d = floor((double)abs(next-now)/(double)5);
                        if(d>0){
                        if(now>next){
                            tempArr[i][j] -=d;
                            tempArr[nextY][nextX]+=d;
                        }else{
                            tempArr[i][j] +=d;
                            tempArr[nextY][nextX]-=d;
                        }
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<tankCnt;i++){
        for(int j=0;j<tankCnt;j++){
            board[i][j]= tempArr[i][j];
        }
    }
}

void toArr(){
    deque<int> dq; 
    for(int i=0;i<tankCnt;i++){
        if(board[0][i]==-1){
            continue;
        }else{
            for(int j=0;j<tankCnt;j++){
                if(board[j][i]!=-1){
                    dq.push_back(board[j][i]);
                }else{
                    break;
                }
            }
        }
    }
    memset(board,-1,sizeof(board));
    for(int i=0;i<2;i++){
        for(int j=tankCnt/2-1;j>=0;j--){
            if(i==0){
                board[i][j] = dq.back();
                dq.pop_back();
            }else{
                board[i][j] = dq.front();
                dq.pop_front();
            }
        }
    }
    int w = tankCnt/4;
    int h = 2;  
    int quart = tankCnt/4;

    for(int i=0;i<2;i++){
        for(int j=0;j<w;j++){
            rotateArr[i][j] = board[i][j];
            board[i][j] = -1;
        }
    }
    rotate(h,w);
    swap(h,w);
    rotate(h,w);
    swap(h,w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            board[i+2][j+tankCnt/4] = rotateArr[i][j];
        }
    }

    moveFish();

    for(int i=0;i<tankCnt;i++){
        if(board[0][i]==-1){
            continue;
        }else{
            for(int j=0;j<tankCnt;j++){
                if(board[j][i]!=-1){
                    dq.push_back(board[j][i]);
                }else{
                    break;
                }
            }
        }
    }

    memset(board,-1,sizeof(board));
    for(int i=0;i<tankCnt;i++){
        board[0][i] = dq.front();
        dq.pop_front();
        
    }
    
}

void startGame(){
    int stage=1; 
    bool found = false;
    while(stage){
        addToMinTank();
        clean();
        moveFish();
        toArr();
        found = check();
        if(found){
            break;
        }
        stage++;
    }
    cout<<stage; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>tankCnt>>targetDiff;
    for(int i=0;i<tankCnt;i++){
        fill(board[i],board[i]+tankCnt,-1);
    }
    for(int i=0;i<tankCnt;i++){
        cin>>board[0][i]; 
    }

    startGame();
}
