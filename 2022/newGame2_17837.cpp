/*
    작성자: 김지수
    작성일: 2022/07/20
    백준 -- 새로운 게임 2 (17837번)
*/

#include <iostream>
#include <cstring>
#include <stack>
#include <deque>
#define MAX 13
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std; 

// 오 왼 위 아래 
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1, 1};
int boardSize,horseNum; 

struct HORSE{
    int y,x;
    int dir; 
    int idx; 
};

struct BLOCK{
    int color;
    stack<HORSE> s; 
};

BLOCK board[MAX][MAX];
deque<HORSE> horseList;
bool found = false; // 한 칸에 말 4개이상인거 찾았는지 

// 방향 반대로 뒤집기 
int flipDir(int dir){
    if(dir == 0){
        return 1; 
    }else if(dir ==1){
        return 0;
    }else if(dir ==2){
        return 3;
    }else if(dir ==3){
        return 2;
    }
}

void printBoard(){
    cout<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j].s.size()<<" ";
        }
        cout<<endl;
    }
}

void oneTurn(){
    // 말 순서대로 보면서 
    for(int i=0;i<horseNum;i++){
        if(board[horseList[i].y][horseList[i].x].s.size()>=4){
            found = true;
        }
        if(found){
            return;
        }
        // 현재 말의 위치에서 다음 위치 구하기 
        HORSE now = horseList[i];
        int nextY = now.y + dy[now.dir];
        int nextX = now.x + dx[now.dir];
        //printBoard();

        // 가려는 위치가 보드 밖 / 파랑일때 방향 반대로 해서 가려는 위치 구하기 
        if(nextY <0 || nextY >=boardSize || nextX <0 || nextX >=boardSize || board[nextY][nextX].color == BLUE){
            now.dir = flipDir(now.dir);
            nextY = now.y+dy[now.dir];
            nextX = now.x + dx[now.dir];
            // 말 리스트에서 현재 말의 방향 업데이트 
            horseList[i].dir = now.dir;
        }
        // 가려는 위치가 또 보드 밖일때 : 그대로 있기 
        if(nextY <0 || nextY >=boardSize || nextX <0 || nextX >=boardSize || board[nextY][nextX].color == BLUE){
            continue;
        }else if(board[nextY][nextX].color == RED){
            // 다음위치가 빨간색일때 
            bool foundHorse = false;
            // 현재 말 위에 있는 말들 같이 움직이고, 순서 뒤집기 -> 그냥 스택 팝 순서대로 넣으면 됨 
            while(!board[now.y][now.x].s.empty()){
                // 현재 말 찾았으면 
                if(board[now.y][now.x].s.top().idx == horseList[i].idx){
                    foundHorse = true;  // 플래그 세우고 
                    // 말 리스트에서 현재 말 위치 업데이트 
                    horseList[i].y = nextY;
                    horseList[i].x = nextX;
                    // 새로운 칸에 말 넣고 기존칸에서 말 빼기 
                    board[nextY][nextX].s.push(horseList[i]);
                    board[now.y][now.x].s.pop();
                }else{
                    // 현재 말 아닐경우 -> 위랑 똑같은데 플래그만 안세움 
                    HORSE next = board[now.y][now.x].s.top();
                    horseList[next.idx].y = nextY;
                    horseList[next.idx].x = nextX;
                    board[nextY][nextX].s.push(horseList[next.idx]);
                    board[now.y][now.x].s.pop();
                }   
                // 옮기려는 위치의 말 수가 4이상이면 답 찾음 
                if(board[nextY][nextX].s.size() >=4){
                    found = true;
                    break;
                }
                // 현재 말 찾았으면 그만 pop 함 
                if(foundHorse){
                    break;
                }
            }
        }else{
            // 다음 칸이 흰색일 경우는 같은 순서로 넣음 -> pop 한순서를 뒤집어야함 
            deque<HORSE> q;
            bool foundHorse =false; 
            while(!board[now.y][now.x].s.empty()){
                if(foundHorse){
                    break;
                }
                if(board[now.y][now.x].s.top().idx == horseList[i].idx){
                    foundHorse = true;
                    horseList[i].y = nextY;
                    horseList[i].x = nextX;
                    q.push_back(horseList[i]);
                    board[now.y][now.x].s.pop();
                }else{
                    HORSE next = board[now.y][now.x].s.top();
                    horseList[next.idx].y = nextY;
                    horseList[next.idx].x = nextX;
                    q.push_back(horseList[next.idx]);
                    board[now.y][now.x].s.pop();
                }   
            }
            while(!q.empty()){
                HORSE dq = q.back();
                board[nextY][nextX].s.push(dq);
                q.pop_back();
                if(board[nextY][nextX].s.size()>=4){
                    found =true;
                    break;
                }
            }
        }        
    }
    
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>horseNum;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j].color;
        }
    }

    for(int i=0;i<horseNum;i++){
        HORSE n; 
        cin>>n.y>>n.x>>n.dir;
        n.y--;
        n.x--;
        n.dir--;
        n.idx = i;
        // 말 리스트에 넣고, 위치에 잇는 말에도 넣기 (2중으로 관리)
        horseList.push_back(n);
        board[n.y][n.x].s.push(n);
    }

    int turnNum = 0;
    while(!found){
        if(turnNum>1000){
            break;
        }
        turnNum++;
        oneTurn();
    }
    if(!found){
        turnNum = -1;
    }
    cout<<turnNum;
}