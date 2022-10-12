/*
    작성자: 김지수
    작성일: 2022/10/12
    백준 -- 새로운 게임 (17780번)
*/

#include <iostream>
#include <deque>
#include <vector>
#define MAX 13
#define WHITE 0
#define RED 1 
#define BLUE 2
using namespace std; 

const int dx[4] ={1,-1,0,0};
const int dy[4] = {0,0,-1,1};

struct HORSE{
    int horseIdx;
    int y,x;
    int dir; 
};

int boardSize, horseCnt;
vector<HORSE> horseList;
deque<int> board[MAX][MAX];
int color[MAX][MAX];

void print(){
    cout<<"\n  board"<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j].size()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<horseCnt;i++){
        cout<<"HORSE #"<<i<<" "<<horseList[i].y<<" , "<<horseList[i].x<<"  dir:"<<horseList[i].dir<<endl; 
    }
}

bool OOB(int y,int x){
    return (y<0 || y>=boardSize|| x<0 || x>=boardSize);
}

int reverseDir(int dir){
    if(dir ==0){
        return 1;
    }else if(dir ==1){
        return 0;
    }else if(dir ==2){
        return 3;
    }else{
        return 2;
    }
}
bool moveHorse(){
    bool ret = false;
    for(int i=0;i<horseCnt;i++){
        HORSE now = horseList[i];
        if(board[now.y][now.x].front()!=now.horseIdx){
            continue;
        }
        int nextY = now.y+dy[now.dir];
        int nextX = now.x+dx[now.dir];
        if(OOB(nextY,nextX) || color[nextY][nextX] ==BLUE){
            now.dir = reverseDir(now.dir);
            nextY = now.y+dy[now.dir];
            nextX = now.x+dx[now.dir];
            if(OOB(nextY,nextX) || color[nextY][nextX]==BLUE){
                horseList[i].dir = now.dir;
                continue;
            }
            else{
                horseList[i].dir = now.dir;
                if(color[nextY][nextX]==RED){
                    while(!board[now.y][now.x].empty()){
                        int idxNow = board[now.y][now.x].back();
                        horseList[idxNow].y = nextY;
                        horseList[idxNow].x = nextX;
                        board[nextY][nextX].push_back(idxNow);
                        board[now.y][now.x].pop_back();
                    }
                }else{
                     while(!board[now.y][now.x].empty()){
                        int idxNow = board[now.y][now.x].front();
                        horseList[idxNow].y = nextY;
                        horseList[idxNow].x = nextX;
                        board[nextY][nextX].push_back(idxNow);
                        board[now.y][now.x].pop_front();
                    }
                }
                if(board[nextY][nextX].size()>=4){
                    ret = true;
                }
            }
        }else{
            if(color[nextY][nextX]==RED){
                while(!board[now.y][now.x].empty()){
                    int idxNow = board[now.y][now.x].back();
                    horseList[idxNow].y = nextY;
                    horseList[idxNow].x = nextX;
                    board[nextY][nextX].push_back(idxNow);
                    board[now.y][now.x].pop_back();
                }
            }else{
                while(!board[now.y][now.x].empty()){
                    int idxNow = board[now.y][now.x].front();
                    horseList[idxNow].y = nextY;
                    horseList[idxNow].x = nextX;
                    board[nextY][nextX].push_back(idxNow);
                    board[now.y][now.x].pop_front();
                }
            }
            if(board[nextY][nextX].size()>=4){
                ret = true;
            }
        } 
    }
    return ret; 
}

int startGame(){
    bool found = false;
    for(int i=1;i<=1000;i++){
        found = moveHorse();
        if(found){
            return i;
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>horseCnt;

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>color[i][j];
        }
    }

    for(int i=0;i<horseCnt;i++){
        HORSE h;
        cin>>h.y>>h.x>>h.dir;
        h.y--;
        h.x--;
        h.dir--;
        h.horseIdx = i;
        board[h.y][h.x].push_back(h.horseIdx);
        horseList.push_back(h);
    }
    cout<<startGame();
}