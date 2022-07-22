/*
    작성자: 김지수
    작성일: 2022/07/22
    백준 -- 연구소 2 (17141번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 51
#define EMPTY 0 
#define WALL 1
#define VIRUS 2
using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int boardSize, totalVirus; 
int board[MAX][MAX];
bool visited[MAX][MAX]; 
bool found = false;
queue<pair<pair<int,int>,int> > virusQ; 
vector<pair<int,int> > possiblePos; 
int pickIdx[11];
bool usedVirus[11];
int ans = 0x7fffffff; 
int temp[MAX][MAX];

int bfs(){
    int tempAns = 0; 
    // 상하좌우 움직이면서 벽이 아니고 아직 방문안했으면 temp에 바이러스(2)로 저장하며 퍼트림 
    while(!virusQ.empty()){
        pair<int,int> now = virusQ.front().first;
        int nowCount= virusQ.front().second;
        tempAns = max(tempAns,nowCount);
        virusQ.pop();

        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX = now.second + dx[i];

            if(nextY <0 || nextY >=boardSize || nextX <0 || nextX >=boardSize){
                continue;
            }

            if(!visited[nextY][nextX] && board[nextY][nextX]!=WALL){
                visited[nextY][nextX] = true;
                temp[nextY][nextX] = VIRUS;
                virusQ.push(make_pair(make_pair(nextY,nextX),nowCount+1));
            }
        }
    }

    // 빈공간 유무로 모든칸에 바이러스 퍼졌는지 판단 
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(temp[i][j] == EMPTY){
                return 0x7fffffff;
            }
        }
    }
    found =true;
    return tempAns;
}


void makeComb(int pickCount,int start){
    if(pickCount == totalVirus){
        memset(visited,false,sizeof(visited));
        // 이전에 퍼진 바이러스 위치들 있을수 있어서 다 빼기 
        while(!virusQ.empty()){
            virusQ.pop();
        }
        // temp에 보드 복사 
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                temp[i][j] = board[i][j]; 
            }
        }
        // 새로 뽑은 바이러스들 큐에 넣고, temp에 해당 칸들 바이러스 (2) 로 저장 
        for(int i=0;i<pickCount;i++){
            int y = possiblePos[pickIdx[i]].first;
            int x = possiblePos[pickIdx[i]].second;
            virusQ.push(make_pair(make_pair(y,x),0));
            visited[y][x] =true;
            temp[y][x] = VIRUS;
        }
        // 최솟값 저장 
        int tempAns = bfs();
        ans = min(ans,tempAns);
        return; 

    }else{
        // 바이러스 가능 위치들에서 바이러스 M개 뽑기 (중복 피하기 위해 start 사용 )
        for(int i=start;i<possiblePos.size();i++){
            if(!usedVirus[i]){
                usedVirus[i] = true;
                pickIdx[pickCount] = i; 
                makeComb(pickCount+1,i); 
                usedVirus[i] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>totalVirus;

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j]; 
            // 맨 마지막에 바이러스 퍼짐 여부를 EMPTY 인 공간 유무로 반판하기 때문에 virus 가능 위치 벡터에 저장후 해당 칸 비었다 표시 
            if(board[i][j] == VIRUS){
                possiblePos.push_back(make_pair(i,j));
                board[i][j] = 0;
            }
        }   
    }

    memset(usedVirus,false,sizeof(usedVirus));
    makeComb(0,0);
    if(!found){
        ans = -1; 
    }
    cout<<ans; 
}