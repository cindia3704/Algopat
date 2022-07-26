/*
    작성자: 김지수
    작성일: 2022/07/26
    백준 -- 연구소 3 (17142번)
*/

#include <iostream>
#include <cstring> 
#include <vector>
#include <queue>
#define MAX 51
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};

int boardSize, targetVirusNum; 
bool found =false;
int ans = 0x7fffffff; 
int board[MAX][MAX];
bool visited[MAX][MAX]; 
vector<pair<int,int> > possiblePos; 
int pick[11];
bool posPicked[11];

int bfs(){
    queue<pair<pair<int,int>,int> > q; 
    int tempArr[MAX][MAX];

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            tempArr[i][j] = board[i][j];
        }
    }

    for(int i=0;i<targetVirusNum;i++){
        int y = possiblePos[pick[i]].first;
        int x = possiblePos[pick[i]].second;
        q.push(make_pair(make_pair(y,x),0));
        visited[y][x] = true;
        tempArr[y][x] = 2;
    }

    int tempAns = 0;
    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int nowCount = q.front().second;
        // 비활성화된 바이러스도 바이러스니까 -> 해당 부분 커버 시간은 고려 x 
        if(tempAns<nowCount && board[now.first][now.second]!=2){
            tempAns = nowCount;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(nextY<0 || nextY>=boardSize || nextX<0 || nextX>=boardSize){
                continue;
            }

            if(!visited[nextY][nextX] && board[nextY][nextX]!=1){
                visited[nextY][nextX] = true; 
                tempArr[nextY][nextX] = 3;
                
                    q.push(make_pair(make_pair(nextY,nextX),nowCount+1));
                
                
            }
        }
    }
    
    bool found = false;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(tempArr[i][j] == 0){
                found= true;
            }
        }
    }
    if(found){
        tempAns=-1;
    }
    return tempAns;

}

void pickVirusSpot(int pickCount, int start){
    if(pickCount == targetVirusNum){
        memset(visited,false,sizeof(visited));
        int temp=bfs();
        if(temp!=-1){
            found=true;
            if(ans>temp){
                ans = temp;
            }
        }
        return;
    }
    for(int i=start;i<possiblePos.size();i++){
        if(!posPicked[i]){
            posPicked[i] = true;
            pick[pickCount] = i;
            pickVirusSpot(pickCount+1,i);
            posPicked[i] = false;
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin>>boardSize>>targetVirusNum;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
            if(board[i][j]==2){
                possiblePos.push_back(make_pair(i,j));
            }
        }
    }
    memset(posPicked,false,sizeof(posPicked));
    pickVirusSpot(0,0);
    if(!found){
        ans = -1;
    }
    cout<<ans; 
}