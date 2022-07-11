/*
    작성자: 김지수
    작성일: 2022/07/11
    백준 -- 아기 상어 (16236번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 21
using namespace std; 

//상좌우하 
const int dx[4]={0,-1,1,0};
const int dy[4] = {-1,0,0,1};

int board[MAX][MAX];
bool visited[MAX][MAX];
int boardSize;
int timeExit = 0;

struct SHARK{
    int y, x;
    int sharkSize; 
    int eatCount; 
};
vector<pair<int,int> > fishPos; 

pair<bool,SHARK> bfs(SHARK s){
    fishPos.clear();
    visited[s.y][s.x] = true;
    queue<pair<pair<int,int>,int> > q; 
    q.push(make_pair(make_pair(s.y,s.x),0));
    bool found = false;
    int foundDist = 0x7fffffff;
    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int nowDist = q.front().second;
        q.pop();
        if(board[now.first][now.second] < s.sharkSize && board[now.first][now.second]>0){
            // 더 짧은 거리의 물고기 있으면 물고기 다 지워주고, 거리 업데이트후 현재물고기 넣어주기
            if(foundDist>nowDist){
                foundDist = nowDist;
                fishPos.clear();
                fishPos.push_back(make_pair(now.first,now.second));
            }
            // 지금까지 찾은 물고기거리랑 같은 물고기 있으면 넣어주기 
            if(foundDist==nowDist){
                fishPos.push_back(make_pair(now.first,now.second));
            }
        }
            // 인접 칸 보면서 
            for(int i=0;i<4;i++){
                int nextY = now.first + dy[i];
                int nextX = now.second + dx[i];
                if(nextY<0 || nextY >=boardSize || nextX <0 || nextX >=boardSize){
                    continue;
                }
                // 아직 방문 전 && 상어의 크기와 같거나 작은경우 방문 가능 
                if(!visited[nextY][nextX] && board[nextY][nextX]<=s.sharkSize){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(make_pair(nextY,nextX),nowDist+1));
                }
            }
        
    }
    // 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다
    if(fishPos.size()>0){
        sort(fishPos.begin(),fishPos.end()); 
        s.eatCount++;
        found = true;
        s.y = fishPos[0].first;
        s.x = fishPos[0].second;
        timeExit +=foundDist;
        if(s.eatCount == s.sharkSize){
            s.sharkSize++;
            s.eatCount=0;
        }
        board[fishPos[0].first][fishPos[0].second] = 0;
    }
    return make_pair(found,s);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    SHARK shark;
    shark.sharkSize = 2;
    shark.eatCount=0;
    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
            // 상어찾으면 0으로 바꾸고 상어위치 저장 
            if(board[i][j] == 9){
                shark.y = i;
                shark.x = j;
                board[i][j] = 0;
            }
        }
    }
    
    // 더이상 먹을 물고기 없을때까지 반복 
    while(true){
        bool foundFish = false;
        memset(visited,false,sizeof(visited));
        pair<bool, SHARK> ret = bfs(shark);
        shark = ret.second;
        foundFish = ret.first;
        if(!foundFish){
            break;
        }
    }
    cout<<timeExit;
}