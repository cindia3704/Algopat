/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 토마토 (7576번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std; 
int height,width;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};
int board[MAX][MAX];
bool visited[MAX][MAX];



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>width>>height;
    queue<pair<pair<int,int> ,long long> > q; 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
            if(board[i][j] == 1){
                q.push(make_pair(make_pair(i,j),0));
                visited[i][j] = true;
            }
        }
    }

    long long ans =-1;
    while(!q.empty()){
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int nowCount = q.front().second;
        if(ans <nowCount){
            ans = nowCount;
        }
        q.pop();

        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
        
            if(nextY <0 || nextY >=height || nextX <0 || nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX] == 0){
                visited[nextY][nextX] = true;
                q.push(make_pair(make_pair(nextY,nextX),nowCount+1));
            }
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(!visited[i][j] && board[i][j] == 0){
                cout<<-1;
                return 0;
            }
        }
    }
    cout << ans;


}