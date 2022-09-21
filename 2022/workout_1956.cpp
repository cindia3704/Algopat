/*
    작성자: 김지수
    작성일: 2022/09/21
    백준 -- 운동 (1956번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 801
#define INF 1000000001
using namespace std;

int nodeCnt,edgeCnt;
int board[MAX][MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>nodeCnt>>edgeCnt;
    for(int i=0;i<=nodeCnt;i++){
        fill(board[i],board[i]+MAX,INF);
    }
    for(int i=0;i<edgeCnt;i++){
        int from,to,w;
        cin>>from>>to>>w;
        if(w<board[from][to]){
            board[from][to] = w;
        }
    }

    for(int k=1;k<=nodeCnt;k++){
        for(int i=1;i<=nodeCnt;i++){
            for(int j=1;j<=nodeCnt;j++){
                if(board[i][j]>board[i][k]+board[k][j]){
                    board[i][j]=board[i][k]+board[k][j];
                }
            }
        }
    }
    int ans = INF;
    for(int i=1;i<=nodeCnt;i++){
        ans = min(ans, board[i][i]);
    }
    if(ans == INF){
        ans = -1;
    }
    cout<<ans;
    

}