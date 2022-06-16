/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 적록색약 (10026번)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 101
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4]={-1,0,1,0};
char board[MAX][MAX];
bool visited[MAX][MAX];
int boardSize; 

void bfsBlind(int y,int x, char a){
    queue<pair<int,int> > q; 
    visited[y][x] = true; 

    q.push(make_pair(y,x));

    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX+ dx[i];
            if(nextY<0 || nextY >=boardSize || nextX <0 || nextX >=boardSize){
                continue;
            }
            if(a == 'G' || a =='R'){
                if(!visited[nextY][nextX] && (board[nextY][nextX] == 'G' || board[nextY][nextX] == 'R')){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextY,nextX));
                }
            }
            else{
                if(!visited[nextY][nextX] && board[nextY][nextX] == a){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextY,nextX));
                }
            }
        }

    }
}

void bfs(int y,int x, char a){
    queue<pair<int,int> > q; 
    visited[y][x] = true; 

    q.push(make_pair(y,x));

    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX+ dx[i];
            if(nextY<0 || nextY >=boardSize || nextX <0 || nextX >=boardSize){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX] == a){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }

    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        string lines;
        cin>>lines;
        for(int j=0;j<lines.size();j++){
            board[i][j] = lines[j];
        }
        fill(visited[i],visited[i]+boardSize,false);
    }

    int countNotBlind = 0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!visited[i][j]){
                bfs(i,j,board[i][j]);
                countNotBlind++;
            }
        }
    }
    for(int i=0;i<boardSize;i++){
        fill(visited[i],visited[i]+boardSize,false);
    }
    int countBlind = 0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(!visited[i][j]){
                bfsBlind(i,j,board[i][j]);
                countBlind++;
            }
        }
    }
    cout<<countNotBlind<<" "<<countBlind;

}