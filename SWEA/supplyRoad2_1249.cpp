/*
    작성자: 김지수
    작성일: 2022/08/10
    SWEA -- [S/W 문제해결 응용] 4일차 - 보급로 (1249번)
    // 우선순위 큐 이용한 구현 - 48ms
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
bool visited[MAX][MAX];

struct Road{
    int y,x;
    int cnt; 
    int val; 
}; 

struct cmp{
    bool operator()(Road a, Road b){
        if(a.cnt==b.cnt){
            if(a.y == b.y){
                return a.x>b.x;
            }
            return a.y>b.y;
        }
        return a.cnt<b.cnt;
    }
};

int bfs(int boardSize){
    priority_queue<Road,vector<Road> , cmp> q; 
    visited[0][0] = true; 
    Road start;
    start.y = 0;
    start.x = 0; 
    start.cnt = 0;
    start.val = 0;
    q.push(start); 
    int ans =0;
    while(!q.empty()){
        Road now = q.top();
        q.pop();
        if(now.y == boardSize-1 && now.x == boardSize-1){
            ans = -now.cnt;
            break;
        }
        for(int i=0;i<4;i++){
            int nextY = now.y+dy[i];
            int nextX = now.x + dx[i];
            if(nextY<0 || nextX <0 || nextY >=boardSize || nextX >=boardSize){
                continue;
            }
            if(!visited[nextY][nextX]){
                visited[nextY][nextX] = true;
                Road next; 
                next.y = nextY;
                next.x = nextX; 
                next.cnt = now.cnt - board[nextY][nextX];
                next.val = board[nextY][nextX];
                q.push(next);
            }
        }
    }
    return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        //memset(visited,false,sizeof(visited));
        memset(board,0,sizeof(board));
        int boardSize; 
        cin>>boardSize;
        for(int i=0;i<boardSize;i++){
            string s; 
            cin>>s;
            for(int j=0;j<s.length();j++){
                board[i][j] = s[j]-'0';
                visited[i][j] = false;
            }
        }
        int ans = bfs(boardSize);
        cout<<"#"<<test_case<<" "<<ans<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}