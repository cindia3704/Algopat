/*
    작성자: 김지수
    작성일: 2022/08/05
    백준 -- 청소년 상어 (19236번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 4
using namespace std; 
int ans = 0; 
//0부터 순서대로 ↑, ↖, ←, ↙, ↓, ↘, →, ↗
const int dy[8]={-1,-1,0,1,1,1,0,-1};
const int dx[8] = {0,-1,-1,-1,0,1,1,1};

struct Fish{
    int y,x;
    int idx; 
    int direction; 
    bool alive;
}; 

struct Turn{
    Fish fishList[17];
    int board[MAX][MAX];
};

void print(Turn t){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<t.board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

Turn moveFish(Turn nowTurn){
    // 현재 차례에서 물고리 움직이기 
    int temp[MAX][MAX];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            temp[i][j] = nowTurn.board[i][j]; 
        }
    }

    // 현재 물고기가 살아있으면 
    for(int i=1;i<17;i++){
        if(nowTurn.fishList[i].alive){
            Fish now = nowTurn.fishList[i];
            // 다음 위치 보고 
            int nextY = now.y + dy[now.direction];
            int nextX = now.x + dx[now.direction];
            // 다음위치가 보드 밖이거나 상어자리면 45도 회전 
            while(nextY<0 || nextX <0 || nextX>=4 || nextY >=4 || temp[nextY][nextX] == 40){
                now.direction = (now.direction+1)%8;
                nextY = now.y + dy[now.direction];
                nextX = now.x + dx[now.direction];
            }
            // 다음위치에 있는 물고기와 자리 바꾸기 
            int nextIdx = temp[nextY][nextX];
            temp[now.y][now.x] = nextIdx;
            temp[nextY][nextX] = i; 

            nowTurn.fishList[i].y = nextY;
            nowTurn.fishList[i].x = nextX;
            nowTurn.fishList[i].direction = now.direction;
            // 다음자리가 비어있으면 물고기 정보 업데이트 안함 
            if(nextIdx>0){
                nowTurn.fishList[nextIdx].y = now.y;
                nowTurn.fishList[nextIdx].x = now.x;
            }
        }
    }

    // 보드 복사후 반환 
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            nowTurn.board[i][j] = temp[i][j]; 
        }
    }
    return nowTurn;
}

void makeComb(Fish shark,int sumIdx,Turn now){
    // 현재 차례에서 물고기 움직인 결과 가져오기 
    Turn afFishMove = moveFish(now); 
    // 상어 움직일거니까 현재 상어있는 칸을 비었다고 업데이트 
    afFishMove.board[shark.y][shark.x] = 0;
    int nextY = shark.y + dy[shark.direction];
    int nextX = shark.x+dx[shark.direction];
    // 상어가 갈수 있는 위치 개수 
    int cnt = 0;

    while(true){
        if(nextY<0 || nextX <0 || nextY>=MAX || nextX>=MAX){
            break;
        }else{
            // 상어가 움직일 자리가 비어있지 않으면 
            if(afFishMove.board[nextY][nextX]!=40 && afFishMove.board[nextY][nextX]!=0){
                //상어가 갈수 있는 위치 개수  ++ 
                cnt++;
                // 상어가 물고기가 있는 칸으로 이동했다면, 그 칸에 있는 물고기를 먹고, 그 물고기의 방향을 가지게 된다. 
                Fish nextShark;
                nextShark.y = nextY;
                nextShark.x = nextX;
                int nextIdx = afFishMove.board[nextY][nextX];
                nextShark.direction = afFishMove.fishList[nextIdx].direction;
                // 먹은 물고기 죽었다고 표시 
                afFishMove.fishList[nextIdx].alive = false;
                // 보드에 상어위치 업데이트 
                afFishMove.board[nextY][nextX] = 40;

                makeComb(nextShark,sumIdx+nextIdx,afFishMove);
                // 돌아왔을때 먹었던 물고기 살리기 
                afFishMove.board[nextY][nextX] = nextIdx;
                afFishMove.fishList[nextIdx].alive = true;
            }
            // 상어가 갈수 있는 모든 위치 보기 
            nextY+=dy[shark.direction];
            nextX +=dx[shark.direction];
        }
    }
    // 상어가 갈수 있는 위치 개수가 0이면 (갈 위치 없으면), 답 업데이트 후 백트래킹 
    if(cnt==0){
        ans = max(ans,sumIdx);
        return;
    }
    
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    Turn start;
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            Fish now;
            now.y=i;
            now.x = j;
            cin>>now.idx>>now.direction;
            now.direction--;
            now.alive = true; 
            start.board[i][j] = now.idx;
            start.fishList[now.idx] = now; 
        }
    }

    //청소년 상어는 (0, 0)에 있는 물고기를 먹고, (0, 0)에 들어가게 된다. 상어의 방향은 (0, 0)에 있던 물고기의 방향과 같다.
    Fish shark;
    shark.y = 0;
    shark.x = 0;
    int idx = start.board[0][0];
    start.fishList[idx].alive =false;
    shark.direction = start.fishList[start.board[0][0]].direction;
    start.board[0][0] = 40; 

    makeComb(shark,idx,start);
    cout<<ans;
}   