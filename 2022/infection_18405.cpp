/*
    작성자: 김지수
    작성일: 2022/10/05
    백준 -- 경쟁적 전염 (18405번)
*/

#include <iostream>
#include <vector>
#define MAXK 1001
#define MAX 201
using namespace std; 

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

int boardSize,virusTypeCnt;
int board[MAX][MAX];
vector<pair<int,int> > virus[MAXK];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>virusTypeCnt;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
            if(board[i][j]>0){
                virus[board[i][j]].push_back(make_pair(i,j));
            }
        }
    }
    int turnCnt,targetY,targetX;
    cin>>turnCnt>>targetY>>targetX;
    
    while(turnCnt--){
        for(int i=1;i<=virusTypeCnt;i++){
            vector<pair<int,int> > temp;
            for(int j=0;j<virus[i].size();j++){
                pair<int,int> now = virus[i][j];
                for(int dir=0;dir<4;dir++){
                    int nextY = now.first + dy[dir];
                    int nextX = now.second +dx[dir];
                    if(nextY < 0 || nextY >=boardSize || nextX < 0 || nextX>=boardSize){
                        continue;
                    }
                    if(board[nextY][nextX]==0){
                        board[nextY][nextX] = i;
                        temp.push_back(make_pair(nextY,nextX));
                    }
                }
            }
            virus[i].clear();
            virus[i].insert(virus[i].end(),temp.begin(),temp.end());
        }
    }
    
    cout<<board[targetY-1][targetX-1];

}