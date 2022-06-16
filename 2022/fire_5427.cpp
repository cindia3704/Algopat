/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 불 (5427번)
*/

#include <iostream>
#include <cstring> 
#include <queue>
#define MAX 1001
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

char board[MAX][MAX];
int fire[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<pair<int,int> ,int> > fires;

void bfsFire(int height, int width){
    while(!fires.empty()){
        int nowY = fires.front().first.first;
        int nowX = fires.front().first.second;
        long long nowCount = fires.front().second;
        fires.pop();
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY <0 || nextY >=height || nextX <0 || nextX >=width){
                continue;
            }
            if(board[nextY][nextX] != '#' && fire[nextY][nextX]==-1){
                fire[nextY][nextX] = nowCount+1;
                fires.push(make_pair(make_pair(nextY,nextX),nowCount +1));
            }
        }
    }
}

pair<bool,int> bfs(int y,int x,int height,int width){
    queue<pair<pair<int,int> ,long long> > q; 
    visited[y][x] = true;
    q.push(make_pair(make_pair(y,x),0));
    bool foundExit = false;
    long long countRoute = 987654321;

    while(!q.empty() && !foundExit){
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        long long nowCount = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY <0 || nextY >=height || nextX <0 || nextX >=width){
                // 범위 벗어나면 출구 도달한것 
                foundExit = true;
                countRoute = nowCount;
            }
            // 일단 상근이 움직이려면 이전에 방문 안한곳 & 벽/불이 아니여야함 
            if(!visited[nextY][nextX] && board[nextY][nextX] == '.'){
                // 불이 접근하려는 위치에 퍼지지 않았을 수 있음! 즉, -1일 때는 방문, 아니면 현재 방문하려는 시간보다 불이 방문한 시간이 커야함 
                if(fire[nextY][nextX]!=-1){
                    if(fire[nextY][nextX]>nowCount+1){
                        visited[nextY][nextX] = true;
                        q.push(make_pair(make_pair(nextY,nextX),nowCount +1));  
                    }
                }else{
                    visited[nextY][nextX] = true;
                    q.push(make_pair(make_pair(nextY,nextX),nowCount +1));
                }
                
            }
        }
    }
    return make_pair(foundExit,countRoute);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin>>tc; 

    while(tc--){
        int height,width;
        cin>>width>>height;
        int startY,startX; 

        memset(fire,-1,sizeof(fire));
        memset(visited,false,sizeof(visited));
        memset(board, 0, sizeof(board));

        while(!fires.empty()){
            fires.pop();
        }
        
        for(int i=0;i<height;i++){
            string l;
            cin>>l;
            for(int j=0;j<l.size();j++){
                board[i][j] = l[j];
                if(board[i][j] == '@'){
                    startY = i;
                    startX = j;
                }else if(board[i][j] == '*'){
                    fires.push(make_pair(make_pair(i,j),0));
                    fire[i][j] = 0;
                }
            }
        }

        bfsFire(height,width);

        pair<bool,int> result = bfs(startY,startX,height,width);
        if(result.first == false){
            cout<<"IMPOSSIBLE"<<'\n';
        }else{
            cout<<result.second+1<<'\n';
        }
    }
}