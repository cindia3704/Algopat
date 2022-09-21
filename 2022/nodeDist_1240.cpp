/*
    작성자: 김지수
    작성일: 2022/09/21
    백준 -- 노드사이의 거리 (1240번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001
#define INF 10000001
using namespace std; 
int nodeCnt,qCnt;
int board[MAX][MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>nodeCnt>>qCnt;
    for(int i=1;i<=nodeCnt;i++){
        fill(board[i],board[i]+nodeCnt+1,INF);
        board[i][i] = 0;
    }
    for(int i=0;i<nodeCnt-1;i++){
        int a,b,w;
        cin>>a>>b>>w;

        board[a][b] = w;
        board[b][a] = w;
    }
    // cout<<"\n====board===="<<endl;
    // for(int i=1;i<=nodeCnt;i++){
    //     for(int j=1;j<=nodeCnt;j++){
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    for(int k=1;k<=nodeCnt;k++){
        for(int i=1;i<=nodeCnt;i++){
            for(int j=1;j<=nodeCnt;j++){
                if(board[i][j] > board[i][k]+board[k][j]){
                    board[i][j] = board[i][k]+board[k][j];
                }
            }
        }
    }
    // cout<<"\n====board===="<<endl;
    // for(int i=1;i<=nodeCnt;i++){
    //     for(int j=1;j<=nodeCnt;j++){
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    for(int i=0;i<qCnt;i++){
        int st,en;
        cin>>st>>en;
        cout<<board[st][en]<<'\n';
    }
}