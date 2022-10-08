/*
    작성자: 김지수
    작성일: 2022/10/08
    백준 -- 주사위 굴리기 2 (23288번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 21
using namespace std; 

// E S W N
const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};

int height, width, turnCnt;
int board[MAX][MAX];
int urf[3];
int sum =0;

int turnReverse(int dir){
    if(dir ==0){
        return 3;
    }else{
        return dir-1;
    }
}

int turn(int dir){
    return (dir+1)%4;
}

int getScore(int ny,int nx){
    bool visited[MAX][MAX];
    memset(visited,false,sizeof(visited));
    queue<pair<int,int> > q; 
    int target = board[ny][nx];
    q.push(make_pair(ny,nx));
    visited[ny][nx] = true;
    int cnt = 0;

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        cnt++;
        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX = now.second +dx[i];
            if(nextY <0 || nextY >=height || nextX <0 || nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]==target){
                visited[nextY][nextX] =  true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    return cnt*target;

}

int reverseDir(int dir){
    if(dir ==0){
        return 2;
    }else if(dir ==1){
        return 3;
    }else if(dir ==2){
        return 0;
    }else if(dir ==3){
        return 1;
    }
}
void turnDice(int dir){
    int u = urf[0];
    int r = urf[1];
    int f = urf[2];
    if(dir ==0){
        urf[0] = 7-r;
        urf[1] = u;
    }else if(dir ==1){
        urf[0] = 7-f;
        urf[2] = u;
    }else if(dir ==2){
        urf[0] = r;
        urf[1] = 7-u;
    }else if(dir ==3){
        urf[0] = f;
        urf[2] = 7-u;
    }
}

pair<pair<int,int>,int> rollDice(int y,int x,int dir){
    pair<pair<int,int> , int> ret; 
    while(true){
        int nextY = y+dy[dir];
        int nextX = x+dx[dir];
        if(nextY < 0 ||nextY>=height||nextX<0 || nextX>=width){
            dir = reverseDir(dir);
        }else{
            turnDice(dir);
            ret = make_pair(make_pair(nextY,nextX),dir);
            break;
        }
    }
    return ret; 
}

void startGame(){
    int nowDir = 0;
    int ny = 0;
    int nx = 0;
    for(int i=0;i<turnCnt;i++){
        pair<pair<int,int>,int> now = rollDice(ny,nx,nowDir);
        ny = now.first.first;
        nx = now.first.second;
        nowDir = now.second;

        sum+=getScore(ny,nx);
        int diceBottom = 7-urf[0];
        if(diceBottom <board[ny][nx]){
            nowDir = turnReverse(nowDir);
        }else if(diceBottom >board[ny][nx]){
            nowDir = turn(nowDir);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>height>>width>>turnCnt;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }

    urf[0] = 1;
    urf[1] = 3;
    urf[2] = 5;

    startGame();
    cout<<sum;
}