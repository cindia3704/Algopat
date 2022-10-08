/*
    작성자: 김지수
    작성일: 2022/10/08
    백준 -- 나무 재태크 (16235번)
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 11
using namespace std; 
int boardSize, initTreeCnt,yearCnt;
struct Tree{
    int y,x;
    int age;
};

// 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1)
const int dy[8]={-1,-1,-1,0,0,1,1,1};
const int dx[8]={-1,0,1,-1,1,-1,0,1};
int board[MAX][MAX];
int nutriAdd[MAX][MAX];
queue<Tree> dead;
deque<Tree> alive; 
deque<Tree> toGrow;

void print(){
    cout<<"\n-----ALIVE TREE------"<<endl;
    for(int i=0;i<alive.size();i++){
        cout<<alive[i].y<<"  ,  "<<alive[i].x<<"   age:"<<alive[i].age<<endl;
    }
    cout<<endl;
    cout<<"\n===board: "<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool cmp(Tree &a, Tree &b){
    if(a.age == b.age){
        if(a.y == b.y){
            return a.x<b.x;
        }
        return a.y<b.y;
    }
    return a.age<b.age;
}
void spring(){
    while(!alive.empty()){
        Tree now = alive.front();
        alive.pop_front();
        if(board[now.y][now.x] >=now.age){
            board[now.y][now.x]-=now.age;
            now.age++;
            toGrow.push_back(now);
        }else{
            dead.push(now);
        }
    }
}

void summer(){
    while(!dead.empty()){
        Tree now = dead.front();
        dead.pop();
        int toBeAdded = floor(now.age/2);
        board[now.y][now.x]+=toBeAdded;
    }
}

void fall(){
    while(!toGrow.empty()){
        Tree now = toGrow.front();
        toGrow.pop_front();
        if(now.age%5 ==0){
            for(int i=0;i<8;i++){
                int nextY = now.y+dy[i];
                int nextX = now.x+dx[i];
                if(nextY <0 || nextX <0 || nextX>=boardSize || nextY>=boardSize){
                    continue;
                }else{
                    Tree n;
                    n.y = nextY;
                    n.x = nextX;
                    n.age = 1;
                    alive.push_front(n);
                }
            }
            alive.push_back(now);
        }
        else{
            alive.push_back(now);
        }
    }
}

void winter(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            board[i][j] += nutriAdd[i][j];
        }
    }
}

void startGame(){
    for(int i=0;i<yearCnt;i++){
        spring();
        summer();
        fall();
        winter();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>initTreeCnt>>yearCnt;
    
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>nutriAdd[i][j];
            board[i][j] = 5;
        }
    }
    for(int i=0;i<initTreeCnt;i++){
        Tree now;
        cin>>now.y>>now.x>>now.age; 
        now.y--;
        now.x--;
        alive.push_back(now);
    }
    sort(alive.begin(),alive.end(),cmp);

    startGame();
    cout<<alive.size();
}