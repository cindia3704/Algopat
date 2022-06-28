/*
    작성자: 김지수
    작성일: 2022/06/28
    백준 -- 뱀 (3190번)
*/

#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#define MAX 101
#define APPLE 2 
#define SNAKE 1 
using namespace std; 

const int dx[4] ={0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int boardSize, totalApple,totalturns; 
int board[MAX][MAX];
vector<pair<int,char> > turnList; 

int turnRight(int dir){
    return (dir+1)%4;
}

int turnLeft(int dir){
    return (4+(dir-1))%4;
}

int bfs(){
    int time = 1;
    int turn = 1; // 시작은 오른쪽 
    deque<pair<int,int> > dq; 
    dq.push_back(make_pair(0,0));
    board[0][0] = SNAKE;    // 보드에 뱀 위치 저장 
    int idxTurn = 0;    // 방향바꾸는 시간 위한 변수 
    
    while(!dq.empty()){
        pair<int,int> now = dq.front();
        pair<int,int> tail = dq.back();

        // 다음 뱀의 머리 위치 구하기 
        int nextY = now.first + dy[turn];   
        int nextX = now.second + dx[turn];
        // 뱀 머리위치가 보드 밖이면 그만 
        if(nextY <0 || nextY >=boardSize || nextX <0 || nextX>=boardSize){
            break;
        }
        // 뱀의 머리가 뱀몸과 부딛히면 그만 
        if(board[nextY][nextX] == SNAKE){
            break;
        }

        // 다음 뱀의 위치가 사과면 
        if(board[nextY][nextX] == APPLE){
            //해당 위치에 뱀머리 넣고, 보드에 뱀 표시 
            board[nextY][nextX] = SNAKE;
            dq.push_front(make_pair(nextY,nextX));
        }else{
            // 다음 뱀머리 위치에 아무것도 없으면 머리 추가하고
            dq.push_front(make_pair(nextY,nextX));
            board[nextY][nextX] = SNAKE;
            // 맨 마지막, 즉 뱀꼬리부분을 비었다고 표시 & 제거 
            board[tail.first][tail.second] = 0;
            dq.pop_back();
        }
        
        if(idxTurn<totalturns){
            if(turnList[idxTurn].first == time){
                if(turnList[idxTurn].second == 'D'){
                    turn = turnRight(turn);
                    idxTurn++;
                }else{
                    turn = turnLeft(turn);
                    idxTurn++;
                }
            }
        }

         time++;
    }
    return time;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>> boardSize >> totalApple; 
    for(int i=0;i<totalApple;i++){
        int y,x;
        cin>>y>>x; 
        board[y-1][x-1] = APPLE;
    }

    cin>>totalturns;
    for(int i=0;i<totalturns;i++){
        int time;
        char direction;
        cin>>time>>direction;
        turnList.push_back(make_pair(time,direction));
    }

    cout<<bfs();
}
