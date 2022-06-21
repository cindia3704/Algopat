/*
    작성자: 김지수
    작성일: 2022/06/21
    백준 -- 다리 만들기 (2146번)
*/

#include <iostream>
#include <cstring> 
#include <queue>
#include <deque>
#define MAX 101
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4] = {-1,0,1,0};
int board[MAX][MAX];
int boardSize; 
bool visited[MAX][MAX];
bool visitedIsland[MAX];
long long ans = 987654321;


// 인접한 칸은 모두 num으로 세팅하기 
void changeNum(int y,int x,int num){
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    board[y][x] = num;
    q.push(make_pair(y,x));
    
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i]; 
            if(nextY < 0 || nextY >=boardSize || nextX < 0 || nextX >=boardSize){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX] == 1){
                board[nextY][nextX] = num;
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}

// 같은 색의 섬 방문할때는 거리 그대로 , 아닐때는 +1 
void bfs(int y,int x,int num){
    deque<pair<pair<int,int> , long long > > q; 
    visited[y][x] = true;
    q.push_back(make_pair(make_pair(y,x),0));
    while(!q.empty()){
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        long long nowCount = q.front().second;
        q.pop_front();
        if(board[nowY][nowX]!=0 && board[nowY][nowX]!=num){
            if(ans>nowCount){
                ans = nowCount;
            }
        }

        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i]; 
            if(nextY<0 || nextY >=boardSize || nextX <0 || nextX >=boardSize){
                continue;
            }
            //(가장 짧은 거리 찾음=> 현재 섬의 가장 끝!)
            // 따라서 현재랑 같은 섬 -> 앞에 추가, 아닐경우 뒤에추가 
            if(!visited[nextY][nextX]){
                visited[nextY][nextX] = true;
                if(board[nextY][nextX] == num){
                    q.push_front(make_pair(make_pair(nextY,nextX),nowCount));
                }else{
                    q.push_back(make_pair(make_pair(nextY,nextX),nowCount+1));
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }

    // 같은 영역은 같으 수로 바꾸기 
    memset(visited,false,sizeof(visited)); 
    int num=-1; 
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!visited[i][j] && board[i][j] == 1){
                changeNum(i,j,num);
                num--;
            }
        }
    }

    // 모든 섬을 시작으로 해서 다 돌아보기 위해 visitedIsland 사용 
    memset(visitedIsland,false,sizeof(visitedIsland));
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!visitedIsland[abs(board[i][j])] && board[i][j] != 0){
                visitedIsland[abs(board[i][j])] = true;
                memset(visited,false,sizeof(visited)); 
                bfs(i,j,board[i][j]);
            }
        }
    }

    cout<<ans-1;
}
