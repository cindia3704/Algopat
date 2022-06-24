/*
    작성자: 김지수
    작성일: 2022/06/24
    백준 -- 로봇 청소기 (14503번)
*/

#include <iostream>
#include <stack>
#include <cstring>
#define MAX 51
using namespace std; 

//북,동,남,서
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int board[MAX][MAX];
bool visited[MAX][MAX];
int height,width; 

// 현 방향에서 왼쪽으로 회전하여 갔을때 다음 위치 구함 
pair<int,int> getLeft(pair<int,int> now, int dir){
    int leftDir = (4+(dir-1))%4; 
    pair<int,int> next; 
    next.first = now.first+dy[leftDir];
    next.second = now.second+dx[leftDir];
    return next; 
}

int dfs(int y,int x, int dir){
    int countCleanedBlock = 1;
    stack<pair<pair<int ,int>,int> > s; 
    visited[y][x] = true; //현재 위치를 청소한다.
    s.push(make_pair(make_pair(y,x),dir));
    
    while(!s.empty()){
        pair<int,int> nowPos = s.top().first;
        int nowDir = s.top().second;
        // 현재칸 다시 돌아올거 아니니 pop 
        s.pop();
        bool turned = false;
        int countTurn = 0;
        int nextDir = nowDir;

        while(!turned && countTurn<4){
            pair<int,int> leftPos = getLeft(nowPos,nextDir);
            nextDir = (4+(nextDir-1))%4; 

            if(leftPos.first < 0 || leftPos.first>=height || leftPos.second < 0 || leftPos.second >=width){
                continue;
            }
            
            // 왼쪽에 아직 청소하지 않은 빈 공간이 존재한다면, 왼쪽 방향으로 회전한 다음 한 칸을 전진
            if(!visited[leftPos.first][leftPos.second] && board[leftPos.first][leftPos.second]==0){
                turned=true;
                countCleanedBlock++;
                visited[leftPos.first][leftPos.second] = true;
                s.push(make_pair(leftPos,nextDir));
            }
            countTurn++; 
        }

        //2a번 단계가 연속으로 네 번 실행되었을 경우, 바로 뒤쪽이 벽이라면 작동을 멈춘다. 그렇지 않다면 한 칸 후진한다.
        if(turned == false && countTurn == 4){
            int oppositeDir = dir;
            if(nowDir==0){
                oppositeDir = 2;
            }else if(nowDir ==2){
                oppositeDir = 0;
            }else if(nowDir ==1){
                oppositeDir = 3;
            }else if(nowDir == 3){
                oppositeDir = 1;
            }

            int Opy = nowPos.first + dy[oppositeDir];
            int Opx = nowPos.second + dx[oppositeDir];

            if(Opy >=0 && Opy<height && Opx>=0 && Opx <width && board[Opy][Opx]==0){
                if(!visited[Opy][Opx]){
                    visited[Opy][Opx] = true;
                    countCleanedBlock++;
                }
                s.push(make_pair(make_pair(Opy,Opx),nowDir));
            }else{
                return countCleanedBlock;
            }

        }
    }
    return countCleanedBlock;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sy,sx,dir; 
    cin>>height>>width;
    cin>>sy>>sx>>dir; 

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }

    memset(visited,false,sizeof(visited));
    cout<< dfs(sy,sx,dir);

}