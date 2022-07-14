/*
    작성자: 김지수
    작성일: 2022/07/14
    백준 -- Maaaaaaaaaze (16985번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 5 
using namespace std; 

// 한칸은 직육면체 -> 6개의 방향 
const int dx[6]={0,1,0,-1,0,0};
const int dy[6]={-1,0,1,0,0,0};
const int dz[6]={0,0,0,0,-1,1};

int ans = 0x7fffffff;
bool found = false;

int board[MAX][MAX][MAX];
int temp[MAX][MAX][MAX];

// 긱 판을 몇번 돌릴지 
int dirs[MAX];
bool pickedDirs[MAX][4];
// 각 판의 배치 순서 
int orders[MAX];
bool pickedOrders[MAX];
// 탈출시도시 방문 처리위해 
bool visited[MAX][MAX][MAX];


struct BLOCK{
    int x,y,z;
    int dist; 
};

void checkExit(){
    if(temp[0][0][0] == 0){
        return;
    }
    queue<BLOCK> q;
    visited[0][0][0] = true;
    BLOCK s;
    s.z = 0;
    s.y=0;
    s.x=0;
    s.dist = 0;
    q.push(s);

    while(!q.empty()){
        BLOCK now = q.front();
        q.pop();
        if(now.z == MAX-1 && now.y == MAX-1 && now.x == MAX-1){
            ans = min(ans,now.dist);
            found = true;
        }
        else{
            for(int i=0;i<6;i++){
                BLOCK next; 
                next.z = now.z+dz[i];
                next.y = now.y+dy[i];
                next.x = now.x+dx[i];
                next.dist = now.dist+1;
                if(next.z<0 || next.z >=MAX || next.y<0 || next.y>=MAX || next.x<0 ||next.x>=MAX){
                    continue;
                }
                if(!visited[next.z][next.y][next.x] && temp[next.z][next.y][next.x] == 1){
                    visited[next.z][next.y][next.x] = true;
                    q.push(next);
                }
            }
        }
    }
    return;
}

void turn(int idx){
    int temp2[MAX][MAX];
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            temp2[i][j] = temp[idx][MAX-j-1][i];
        }
    }

    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            temp[idx][i][j] = temp2[i][j];
        }
    }
}

void makeBoard(){
    for(int i=0;i<5;i++){
        int idx = orders[i];
        int dir = dirs[i];

        for(int j=0;j<MAX;j++){
            for(int k=0;k<MAX;k++){
                temp[i][j][k] = board[idx][j][k];
            }
        }

        while(dir--){
            turn(i);
        }
    }
    return;
}

void pickDir(int pickCount,int start){
    if(pickCount == MAX){
        // 회전 정했으면 이를 바탕으로 미로 만들고, 탈출시도 
        memset(visited,false,sizeof(visited));
        makeBoard();
        checkExit();
        return;
    }
    for(int i=0;i<4;i++){
        int nowBoard = orders[pickCount];
        if(!pickedDirs[nowBoard][i]){
            pickedDirs[nowBoard][i] = true;
            dirs[pickCount]=i;
            pickDir(pickCount+1,i);
            pickedDirs[nowBoard][i] = false;
        }
    }

}

void pickOrder(int pickCount){
    // 배치 순서 정했으면 각 판을 몇번 회전할지 정함 
    if(pickCount == MAX){
        pickDir(0,0);
        return;
    }
    for(int i=0;i<5;i++){
        if(!pickedOrders[i]){
            pickedOrders[i] = true;
            orders[pickCount]=i;
            pickOrder(pickCount+1);
            pickedOrders[i] = false;
        }   
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 5x5x5 입력 받고 
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin>>board[k][i][j];
            }
        }
    }

    memset(pickedOrders,false,sizeof(pickedOrders));
    memset(pickedDirs,false,sizeof(pickedDirs));
    
    // 먼저 각판을 어떤 순서로 배치시킬지 정함 
    pickOrder(0);
    if(found){
        cout<<ans;
    }else{
        cout<<-1;
    }
}