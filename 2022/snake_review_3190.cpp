/*
    작성자: 김지수
    작성일: 2022/10/12
    백준 -- 뱀 (3190번)
*/

#include <iostream>
#include <deque>
#define SNAKE 1
#define MAX 101
#define APPLE 2
#define EMPTY 0
#define MAX_X 10001
using namespace std; 

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int boardSize, appleCnt; 
int board[MAX][MAX];
deque<pair<int,int> > snake; 
char turns[MAX_X];

bool moveSnake(int dir){
    bool ret = false; 
    pair<int,int> nowHead = snake.front();
    pair<int,int> nowTail = snake.back();
    int nextY = nowHead.first+dy[dir];
    int nextX = nowHead.second +dx[dir];
    if(nextY<0 || nextY>=boardSize || nextX<0 || nextX>=boardSize){
        ret = true;
    }
    if(board[nextY][nextX]==SNAKE){
        ret = true;
    }
    if(board[nextY][nextX] == APPLE){
        board[nextY][nextX] = EMPTY;
        board[nextY][nextX] = SNAKE;
        snake.push_front(make_pair(nextY,nextX));
    }else{
        board[nextY][nextX] = SNAKE;
        snake.push_front(make_pair(nextY,nextX));
        board[nowTail.first][nowTail.second] = EMPTY;
        snake.pop_back();
    }
    return ret; 
}

int changeDir(int dir,char toDir){
    if(toDir=='L'){
        return (dir-1 <0 )? dir-1+4:dir-1;
    }else{
        return (dir+1)%4;
    }
}

void startGame(){
    int time = 1;
    bool bump =false;
    int nowDir = 0;
    while(true){
       bump = moveSnake(nowDir);
       if(bump){
            break;
       }
       if(turns[time]=='L' || turns[time]=='D'){
         nowDir = changeDir(nowDir,turns[time]);
       }
       time++;
    }
    cout<<time;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>appleCnt;
    
    for(int i=0;i<appleCnt;i++){
        int y,x;
        cin>>y>>x;
        board[y-1][x-1] = APPLE;
    }
    board[0][0] = SNAKE;
    snake.push_back(make_pair(0,0));
    int turnCnt; 
    cin>>turnCnt;
    for(int i=0;i<turnCnt;i++){
        int t;
        char d;
        cin>>t>>d;
        turns[t] = d;
    }

    startGame();

}