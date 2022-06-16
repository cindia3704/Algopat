/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 나이트의 이동 (7562번)
*/

#include <iostream> 
#include <cstring> 
#include <queue>
#define MAX 301
using namespace std; 

bool visited[MAX][MAX];
const int dx[8] = {1,2,1,2,-1,-2,-1,-2};
const int dy[8] = {-2,-1,2,1,2,1,-2,-1};

int bfs(int sy,int sx, int ey,int ex,int boardSize){
    queue<pair<pair<int,int> ,long long > > q; 
    visited[sy][sx] = true;
    q.push(make_pair(make_pair(sy,sx),0));
    long long ans = 987654321;

    while(!q.empty()){
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        long long nowCount = q.front().second;
        if(nowY == ey && nowX == ex){
            if(ans>nowCount){
                ans = nowCount;
            }
        }
        q.pop();
        for(int i=0;i<8;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY <0 || nextY>=boardSize || nextX<0 || nextX >=boardSize){
                continue;
            }
            if(!visited[nextY][nextX]){
                visited[nextY][nextX]=true;
                q.push(make_pair(make_pair(nextY,nextX),nowCount+1));
            }
        }
    }
    return ans; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; 
    cin>>tc; 
    while(tc--){
        memset(visited,false,sizeof(visited));
        int boardSize;
        cin>>boardSize;
        int nowY,nowX,targetY,targetX;
        cin>>nowY>>nowX;
        cin>>targetY>>targetX; 
        cout<< bfs(nowY,nowX,targetY,targetX,boardSize)<<'\n';

    }

}