/*
    작성자: 김지수
    작성일: 2022/09/27
    백준 -- 미네랄 (2933번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 101
using namespace std; 

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int height,width; 
int commandCnt;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<int> throwList;  // 던지는 순서대로 높이 담음 
struct Mineral{
    int y,x;
    int clusterGroup;
    bool isAlve;
};
vector<Mineral> mineralList; // 미네랄 위치 및 상태 

// 보드 출력
void print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==-1){
                cout<<'.';
            }else{
                cout<<'x';
            }

        }
        cout<<'\n';
    }
}
// y,x와 인접한 칸들 모두 순회하면서 같은 클러스터라고 표시 
void bfs(int y,int x,int idx){
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));

    while (!q.empty()){
        pair<int,int> now = q.front();
        q.pop();

        if(mineralList[board[now.first][now.second]].clusterGroup != idx){
            mineralList[board[now.first][now.second]].clusterGroup = idx;
        }
        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX = now.second + dx[i];

            if(nextY<0 || nextY>=height || nextX<0 || nextX>=width){
                continue;
            }
            // 방문전 & 미네랄인 곳만(빈곳 = -1, 미네랄 = 0~미네랄 개수)
            if(!visited[nextY][nextX] && board[nextY][nextX]>=0){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}

void getCluster(){
    memset(visited,false,sizeof(visited));
    int idx=0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(!visited[i][j] && board[i][j]>0){
                bfs(i,j,idx);
                idx++;
            }
        }
    }
}

// dir 0:왼쪽에서 던짐, 1 = 오른쪽에서 던짐 
int throwRock(int dir,int throwH){
    int ret =-1;
    if(dir==0){
        int ny=throwH;
        int nx=0;
        while(true){
            if(ny<0 || nx<0 || ny>=height || nx>=width){
                break;
            }
            if(board[ny][nx]==-1){
                nx++;
            }else{
                ret = mineralList[board[ny][nx]].clusterGroup;
                mineralList[board[ny][nx]].isAlve = false;
                board[ny][nx]=-1;
                break;
            }

        }
    }else{
        int ny=throwH;
        int nx=width-1;
        while(true){
            if(ny<0 || nx<0 || ny>=height || nx>=width){
                break;
            }
            if(board[ny][nx]==-1){
                nx--;
            }else{
                //cout<<"mineral "<<board[ny][nx]<<" alive = fallse"<<endl;
                ret = mineralList[board[ny][nx]].clusterGroup;
                mineralList[board[ny][nx]].isAlve = false;
                board[ny][nx]=-1;
                break;
            }

        }
    }
    return ret;
}

void gravity(int clustIdx){
    //모든 클러스터 돌면서 최대로 움직일수 있는 칸 구하기 
    for(int c=clustIdx+1;c>=0;c--){
        int minH = height;
        // 해당 칸이 현재 찾는 클러스터 값이고, 미네랄이 파괴되지 않았을때 
        for(int i=mineralList.size()-1;i>=0;i--){
            if(mineralList[i].clusterGroup == c && mineralList[i].isAlve==true){
                int ny = mineralList[i].y;
                int nx = mineralList[i].x; 
                
                // 다음위치가 빈칸 / 해당 클러스터랑 같은 칸이면 이동 가능! (같은 칸이면 클러스터끼리 같이 내려가기 때문!)
                while(ny<height){
                    int nextY = ny+1;
                    if(nextY<height && nextY>=0){
                        if(board[nextY][nx]==-1 || mineralList[board[nextY][nx]].clusterGroup == c){
                            ny=nextY;
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                }                
                minH = min(minH,abs(ny-mineralList[i].y));
            }
        }
        // 최대로 내려갈수 있는 만큼 해당 클러스터에 포함된 미네랄 다 내리기 
        if(minH>0){
            for(int i=mineralList.size()-1;i>=0;i--){
                if(mineralList[i].clusterGroup == c && mineralList[i].isAlve==true){
                    int ny = mineralList[i].y + minH;
                    int nx = mineralList[i].x;
                    board[ny][nx] = i;
                    board[mineralList[i].y][mineralList[i].x] = -1;
                    mineralList[i].y = ny;
                }
            }
        }
    }
}


void startGame(){
    for(int i=0;i<commandCnt;i++){
        // 클러스터 구하기 
        getCluster();
        // 돌 던지기 (왼,오 반복)
        int brokenCluster = throwRock(i%2,height-throwList[i]);
        // 클러스터 구하기 (같은 클러스터끼리 같이 움직이기 때문!)
        getCluster();
        // 중력 작용
        gravity(brokenCluster);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width;
    int idx=0;

    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            if(l[j]=='.'){
                board[i][j]=-1;
            }else{
                Mineral now;
                now.y=i;
                now.x=j;
                now.isAlve = true;
                now.clusterGroup = -1;
                mineralList.push_back(now);
                board[i][j]=idx;
                idx++;
            }
        }
    }

    cin>>commandCnt;
    for(int i=0;i<commandCnt;i++){
        int num;
        cin>>num;
        throwList.push_back(num);
    }

    startGame();
    print();
}