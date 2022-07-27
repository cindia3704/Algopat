/*
    작성자: 김지수
    작성일: 2022/07/27
    SWEA -- 파핑파핑 지뢰찾기 (1868번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <queue>
#define MAX 301
using namespace std;

const int dx[8] = {0,1,1,1,0,-1,-1,-1};
const int dy[8]= {-1,-1,0,1,1,1,0,-1};
int boardSize;
char board[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;

void print(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void fillBoardCountBomb(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]!='*'){
            int cnt=0;
            for(int dir=0;dir<8;dir++){
                int nextY = i+dy[dir];
                int nextX = j+dx[dir];
                if(nextY<0 || nextY>=boardSize || nextX <0 ||nextX>=boardSize){
                    continue;
                }
                if(board[nextY][nextX]=='*'){
                    cnt++;
                }
            }
            board[i][j] = (char)(cnt+48);
            }
        }
    }
}

void bfs(int y,int x){
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        if(board[now.first][now.second]=='0'){
            for(int i=0;i<8;i++){
                int nextY = now.first+dy[i];
                int nextX = now.second+dx[i];
                if(nextY<0 || nextY>=boardSize || nextX <0 ||nextX>=boardSize){
                    continue;
                }
                if(!visited[nextY][nextX] && board[nextY][nextX]!='*'){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextY,nextX));
                }
            }
        }
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        cin>>boardSize;
        memset(board,'.',sizeof(board));
        memset(visited,false,sizeof(visited));
        ans = 0;

        int countEmptySpot = 0;
        for(int i=0;i<boardSize;i++){
            string l;
            cin>>l;
            for(int j=0;j<l.length();j++){
                board[i][j]=l[j];
            }
        }
        fillBoardCountBomb();
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                if(!visited[i][j] && board[i][j] == '0'){
                    ans++;
                    bfs(i,j);
                }
            }
        }
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                if(!visited[i][j] && board[i][j] !='*'){
                    ans++;
                    visited[i][j] = true;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<'\n';
        

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}