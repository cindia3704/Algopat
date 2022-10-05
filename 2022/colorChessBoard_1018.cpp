/*
    작성자: 김지수
    작성일: 2022/10/05
    백준 -- 체스판 다시 칠하기 (1018번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 51
using namespace std; 

int ans=0x7ffffff;
int height,width;
char board[MAX][MAX];

void countBlockB(int sy,int sx){
    int cntBFirst=0;
    int cntWFirst=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int y = i+sy;
            int x = j+sx;
            if((y%2==0 && x%2==0)||(y%2==1 && x%2==1)){
                if(board[y][x] != 'B'){
                    cntBFirst++;
                }else{
                    cntWFirst++;
                }
            }else{
                if(board[y][x] != 'W'){
                    cntBFirst++;
                }else{
                    cntWFirst++;
                }
            }
        }
    }

    ans=min(ans,min(cntBFirst,cntWFirst));
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width;
    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            board[i][j] = l[j];
        }
    }
    for(int i=0;i<=height-8;i++){
        for(int j=0;j<=width-8;j++){
            countBlockB(i,j);
        }
    }
    cout<<ans;
}