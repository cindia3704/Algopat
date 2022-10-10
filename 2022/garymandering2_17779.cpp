/*
    작성자: 김지수
    작성일: 2022/10/10
    백준 -- 게리맨더링 2 (17779번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 21
using namespace std; 
int ans = 0x7fffffff;
int boardSize; 
int population[MAX][MAX];
int board[MAX][MAX];
int totalSum;
void print(){
    for(int i=1;i<=boardSize;i++){
        for(int j=1;j<=boardSize;j++){
            if(board[i][j] == 0){
                cout<<5<<" ";
            }else{
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

// 1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
void fillArea1(int x,int y,int d1,int d2){
    for(int i=1;i<x+d1;i++){
        for(int j=1;j<=y;j++){
            if(board[i][j]!=0){
                break;
            }else{
                board[i][j] = 1;
            }
        }
    }
}

//2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
void fillArea2(int x,int y,int d1,int d2){
    for(int i=1;i<=x+d2;i++){
        for(int j=boardSize;j>y;j--){
            if(board[i][j]!=0){
                break;
            }else{
                board[i][j] = 2;
            }
        }
    }
}

//3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
void fillArea3(int x,int y,int d1,int d2){
    for(int i=x+d1;i<=boardSize;i++){
        for(int j=1;j<y-d1+d2;j++){
            if(board[i][j]!=0){
                break;
            }else{
                board[i][j] = 3;
            }
        }
    }
}

//4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
void fillArea4(int x,int y,int d1,int d2){
    for(int i=x+d2+1;i<=boardSize;i++){
        for(int j=boardSize;j>=x-d1+d2;j--){
            if(board[i][j]!=0){
                break;
            }else{
                board[i][j] = 4;
            }
        }
    }
}

/*
(x, y), (x+1, y-1), ..., (x+d1, y-d1)
(x, y), (x+1, y+1), ..., (x+d2, y+d2)
(x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
*/
void fillArea5(int x,int y,int d1,int d2){
    for(int i=0;i<=d1;i++){
        board[x+i][y-i] = 5;
        board[x+d2+i][y+d2-i]=5;
    }
    for(int i=0;i<=d2;i++){
        board[x+i][y+i] = 5;
        board[x+d1+i][y-d1+i]=5;
    }
}

void calculateScore(){
    int sumArea[5];
    fill(sumArea,sumArea+5,0);
    int othersCnt =0;
    for(int i=1;i<=boardSize;i++){
        for(int j=1;j<=boardSize;j++){
            if(board[i][j]>0 && board[i][j]<5){
                int idx = board[i][j]-1;
                sumArea[idx]+=population[i][j];
                othersCnt+=population[i][j];
            }
        }
    }
    sumArea[4] = totalSum-othersCnt;
    int maxSum = 0;
    int minSum = 0x7fffffff;
    
    for(int i=0;i<5;i++){
        maxSum= max(maxSum,sumArea[i]);
        minSum = min(minSum,sumArea[i]);
    }
    ans=min(ans,(maxSum-minSum));
}

void calculate(int x,int y, int d1,int d2){
    for(int i=1;i<=boardSize;i++){
        for(int j=1;j<=boardSize;j++){
            board[i][j] = 0;
        }
    }
    fillArea5(x,y,d1,d2);
    fillArea1(x,y,d1,d2);
    fillArea2(x,y,d1,d2);
    fillArea3(x,y,d1,d2);
    fillArea4(x,y,d1,d2);
    calculateScore();
}

//(d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N)
void startGame(){
    for(int x=1;x<=boardSize;x++){
        for(int y=1;y<=boardSize;y++){
            for(int d1=1;d1<=boardSize;d1++){
                for(int d2=1;d2<=boardSize;d2++){
                    if(x+d1+d2>boardSize){
                        continue;
                    }
                    if(y-d1<1){
                        continue;
                    }
                    if(y-d1>boardSize){
                        continue;
                    }
                    if(y+d2>boardSize){
                        continue;
                    }
                    calculate(x,y,d1,d2);
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize;
    for(int i=1;i<=boardSize;i++){
        for(int j=1;j<=boardSize;j++){
            cin>>population[i][j];
            totalSum+=population[i][j];
        }
    }

    startGame();
    cout<<ans; 
}