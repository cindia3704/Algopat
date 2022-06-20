/*
    작성자: 김지수
    작성일: 2022/06/21
    백준 -- 벽 부수고 이동하기 (2206번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};

int height,width;
char board[MAX][MAX];
int visitDist[MAX][MAX][2];
long long ans =987654321;

void print(){
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void bfs(){
    queue<pair<pair<int,int>,int> > q; 
    q.push(make_pair(make_pair(0,0),0));
    bool foundExit = false; 
    visitDist[0][0][0] = visitDist[0][0][1] = 0;

    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int broken = q.front().second;
        q.pop();
        if(now.first == height-1 && now.second == width-1){
            foundExit = true;
            if(ans>visitDist[now.first][now.second][broken]){
                ans = visitDist[now.first][now.second][broken]+1;
            }
        }
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(nextY<0 || nextY >=height || nextX <0 || nextX >=width){
                continue;
            }
            if(visitDist[nextY][nextX][broken]==-1 && board[nextY][nextX] == '0'){
                visitDist[nextY][nextX][broken] = visitDist[now.first][now.second][broken]+1;
                q.push(make_pair(make_pair(nextY,nextX),broken));
            }
            else if(broken == 0 && board[nextY][nextX] == '1'){
                visitDist[nextY][nextX][broken+1]= visitDist[now.first][now.second][broken]+1;
                q.push(make_pair(make_pair(nextY,nextX),1));
            }
        }
    }
    return;
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

    memset(visitDist,-1,sizeof(visitDist));
    bfs();

    if(ans == 987654321){
        cout<<-1;
    }else{
        cout<<ans;
    }
}