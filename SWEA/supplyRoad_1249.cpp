/*
    작성자: 김지수
    작성일: 2022/08/10
    SWEA -- [S/W 문제해결 응용] 4일차 - 보급로 (1249번)
    // 완탐 (DP) - 54ms
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 101
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int board[MAX][MAX];
int dist[MAX][MAX];


void bfs(int boardSize){
    queue<pair<int,int> >  q; 
    dist[0][0] = 0; 
    q.push(make_pair(0,0)); 
    while(!q.empty()){
        pair<int,int>  now = q.front();  
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX = now.second + dx[i];
            if(nextY<0 || nextX <0 || nextY >=boardSize || nextX >=boardSize){
                continue;
            }
            int nextDist = dist[now.first][now.second] + board[nextY][nextX];
            if(dist[nextY][nextX] >nextDist){
                dist[nextY][nextX]= nextDist;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        memset(board,0,sizeof(board));
        int boardSize; 
        cin>>boardSize;
        for(int i=0;i<boardSize;i++){
            string s; 
            cin>>s;
            for(int j=0;j<s.length();j++){
                board[i][j] = s[j]-'0';
                dist[i][j] = 9999999;
            }
        }
        bfs(boardSize);
        int ans = dist[boardSize-1][boardSize-1];
        cout<<"#"<<test_case<<" "<<ans<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}