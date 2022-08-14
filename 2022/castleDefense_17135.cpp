/*
    작성자: 김지수
    작성일: 2022/08/15
    백준 -- 캐슬 디펜스 (17135번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set> 
#include <queue>
#define ARMY 2
#define MAX 16
using namespace std; 

// 밑에서 위로 올라가는 느낌 => 아래 봐줄 필요 x 
const int dx[3]={-1,0,1}; 
const int dy[3] = {0,-1,0};

int height,width,distLimit;
int board[MAX][MAX];    // 원본 
bool used[MAX];         // 마지막줄+1 행에서 3명의 궁수 뽑을때 해당 위치의 열 선택 되었는지 
pair<int,int> pick[3];  // 선택된 궁수 위치 
int tempArr[MAX][MAX];  // 매 turn 마다 적 죽이는데 사용하는 배열 

struct Enemy{
    int y,x;
    bool alive; 
};
bool visited[3][MAX][MAX];  // 궁수가 3명이므로 3명이 각 위치 방문 여부 표시 
int foundEnemy[3];          // 3명의 궁수가 죽인 적 
int foundEnemyDist[3];      // 궁수가 죽인 적의 거리 
vector<Enemy> enemy;        // 적 위치 및 상태 저장 

struct Block{               // bfs 돌릴때 사용 
    int x,y;
    int enemyIdx;
    int dist;
};

int ans = 0;

void print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<tempArr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int killEnemy(){
    int answer = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<height;j++){
            for(int k=0;k<width;k++){
                visited[i][j][k] = false;
            }
        }
       foundEnemy[i]=-1;
       foundEnemyDist[i]=-1;
    }

    queue <Block> q; 
    // 궁수 위치 백트래킹으로 얻은거 모두 큐에 넣기 (궁수 위치는 보드 밖 => dist 를 1부터 시작하고 y -- 해줌 )
    for(int i=0;i<3;i++){
        Block now;
        now.y = pick[i].first-1;
        now.x = pick[i].second;
        now.dist = 1;
        now.enemyIdx = i;
        q.push(now);
    }

    while(!q.empty()){
        Block now = q.front();
        q.pop();
        // 현재 위치가 보드 밖이 아니고, temp가 -1(비어있음)이 아니고, 현재 거리가 궁수가 적을 죽일수 있는 거리 안에 있을때 
        if(!(now.y<0 || now.y>=height || now.x<0 || now.x>=width) &&tempArr[now.y][now.x] != -1 && now.dist <=distLimit){
            // 적의 idx 구하고 
            int idx = tempArr[now.y][now.x];
            // 아직 현재 궁수가 죽인 적없을때 
            if(foundEnemy[now.enemyIdx] == -1){
                // 죽인 적의 idx & 적과 궁수의 거리 저장 
                foundEnemy[now.enemyIdx] = tempArr[now.y][now.x];
                foundEnemyDist[now.enemyIdx] = now.dist;
            }else{
                // 궁수가 죽인 적이 있을때 가장 가까운 적을, 그런 적이 많을때는 가장 왼쪽에 있는 적을 죽여야함 
                Enemy original  = enemy[foundEnemy[now.enemyIdx]];
                if(foundEnemyDist[now.enemyIdx] == now.dist){
                    if(now.x < original.x){
                        foundEnemy[now.enemyIdx] = tempArr[now.y][now.x];
                    }
                }else if(foundEnemyDist[now.enemyIdx] >now.dist){
                    foundEnemy[now.enemyIdx] = tempArr[now.y][now.x];
                    foundEnemyDist[now.enemyIdx] = now.dist;
                }
            }
        }else{
            // 적 못찾음 => 왼, 위, 오 보면서 
                for(int i=0;i<3;i++){
                    int nextY = now.y+dy[i];
                    int nextX = now.x+dx[i];

                    if(nextY <0 || nextY>=height || nextX <0 || nextX >=width){
                        continue;
                    }
                    // 궁수가 적을 죽일수 있는 거리 내에 있고, 아직 해당 궁수가 다음 위치 방문전이면 큐에 넣기 
                    if(now.dist+1 <=distLimit && !visited[now.enemyIdx][nextY][nextX]){
                        visited[now.enemyIdx][nextY][nextX] = true;
                        Block next; 
                        next.y = nextY;
                        next.x = nextX;
                        next.enemyIdx = now.enemyIdx;
                        next.dist = now.dist+1;
                        q.push(next);
                    }
                }
            }
        }
    
    // 3명의 궁수가 죽인 적 보드에서 죽었다고 업데이트 & 적 리스트에서도 죽었다 업데이트 
    for(int t=0;t<3;t++){
        if(foundEnemy[t]!=-1){
            Enemy now = enemy[foundEnemy[t]];
            if(now.alive){
                tempArr[now.y][now.x] = -1;
                enemy[foundEnemy[t]].alive = false; 
                answer++;
            }
        }
    }

    // 현재 죽인 적의 수 반환 
    return answer;
}


// 모든 적 보면서 아직 살아있으면 false, 아니면 true 
bool noMoreEnemy(){
    for(int i=0;i<enemy.size();i++){
        if(enemy[i].alive){
            return false;
        }
    }
    return true; 
}

// 모든 적은 한칸씩 아래로 내리기 (살아있는 적만)
void moveEnemy(){
    for(int i=0;i<enemy.size();i++){
        if(enemy[i].alive){
            tempArr[enemy[i].y][enemy[i].x] = -1;
            enemy[i].y++;
            if(enemy[i].y<0 || enemy[i].y>=height ){
                enemy[i].alive = false;
                continue;
            }
            tempArr[enemy[i].y][enemy[i].x] = i;
        }
    }
}

void startGame(){
    enemy.clear();
    int idx = 0;
    // 궁수가 없으면 -1로, 있으면 해당 궁수의 idx 를 tempArr에 저장 
     for(int i=height-1;i>=0;i--){
        for(int j=width-1;j>=0;j--){
            tempArr[i][j] = board[i][j];
            if(tempArr[i][j]==1){
                Enemy e;
                e.y = i;
                e.x = j;
                e.alive = true;
                tempArr[i][j]=idx;
                enemy.push_back(e);
                idx++;
            }else{
                tempArr[i][j]=-1;
            }
        }
    }

    // 죽은 적의 총합 
    int enemyKilled = 0;
    while(true){
        // 적 죽이기 
        int temp=killEnemy();
        enemyKilled+=temp;
        // 적 한칸씩 아래로 보내기
        moveEnemy();
        //print();
        // 모든 적이 죽었는지 확인 
        if(noMoreEnemy()){
            break;
        }
    }
    ans = max(ans,enemyKilled);
}

// width 중 위치 3개를 뽑음 
void makeComb(int pickCount,int sx){
    if(pickCount == 3){
        startGame();
        return; 
    }
    
    for(int j=sx;j<width;j++){
        if(!used[j]){
                used[j]= true;
                pick[pickCount] = make_pair(height,j);
                makeComb(pickCount+1,j);
                used[j]= false;
            }
    }
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>height>>width>>distLimit;
    int enemyCnt = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j]; 
            if(board[i][j]==1){
                enemyCnt++;
            }
        }
    }
    if(enemyCnt == 0){
        cout<<0;
    }else{
        memset(used,false,sizeof(used));
        makeComb(0,0);
        cout<<ans;
    }
}