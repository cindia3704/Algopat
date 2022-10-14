/*
    작성자: 김지수
    작성일: 2022/10/14
    코드트리 -- 토스트 계란틀 (17번)
*/

#include <iostream> 
#include <cstring> 
#include <queue>
#include <vector>
#define MAX 51
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int boardSize;
int minLimit,maxLimit; 
int board[MAX][MAX];
bool visited[MAX][MAX];
int stage = 0;

bool OOB(int y, int x){
    return (y<0 || y>=boardSize || x<0 || x>=boardSize);
}

void print(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool bfs(int y,int x){       
    bool ret = false; 
    vector<pair<int,int> > pos;
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));
    int sum = 0;
    while(!q.empty()){
        pair<int,int> now = q.front();
        pos.push_back(now);
        q.pop();
        sum+=board[now.first][now.second];
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(OOB(nextY,nextX)){
                continue;
            }
            int diff = abs(board[nextY][nextX]-board[now.first][now.second]);
            if(!visited[nextY][nextX] && diff>=minLimit && diff<=maxLimit){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    
    int cnt = pos.size();
    if(cnt>1){
        int newVal = sum/cnt;
        for(int i=0;i<cnt;i++){
            ret = true;
            pair<int,int> now = pos[i];
            board[now.first][now.second] = newVal;
        }
    }
    return ret; 
}

void startGame(){
    bool stop = false;

    while(!stop){
        memset(visited,false,sizeof(visited));
        bool add= false;
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                 if(!visited[i][j]){
                    bool cont = bfs(i,j);
                    if(cont){
                        add = true;
                    }
                }
            }
        }
        if(!add){
            stop = true;
            break;
        }
        if(add){
            stage++;
        }
    }
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>minLimit>>maxLimit;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }

    startGame();
    cout<<stage;
}   