/*
    작성자: 김지수
    작성일: 2022/07/12
    백준 -- 감시 (18428번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 7
using namespace std;

const int dx[4]={0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int boardSize;
char board[MAX][MAX];
bool visited[MAX][MAX];
bool found = false;
vector<pair<int,int> > teacher; 

bool checkDirs(int tX,int tY){
    // 선생님 위치에서 상하좌우로 뻗어가며 학생보면 false, 문체 있으면 멈춤, 빈곳이면 계속 뻗어나감 
    for(int i=0;i<4;i++){
        int nextY = tY+dy[i];
        int nextX = tX+dx[i];
        while(nextY>=0 && nextY<boardSize && nextX>=0 && nextX <boardSize){
            if(board[nextY][nextX] == 'O'){
                break;
            }
            if(board[nextY][nextX] == 'S'){
                return false;
            }
            nextY+=dy[i];
            nextX+=dx[i];
        }
    }
    return true;
}

bool check(){
    bool found = true;
    // 모든 선생님 위치에서 상하좌우로 뻗어나가며 볼때 학생 볼수 없을때만 true
    for(int i=0;i<teacher.size();i++){
        int tX = teacher[i].second;
        int tY = teacher[i].first;
        bool temp = checkDirs(tX,tY);
        if(!temp){
           found = false;
           break;
        }
    }
    return found;
}

void makeComb(int pickCount,int y,int x){
    // 3개의 장애물 넣으면 감시피할수 있는지 확인 
    if(pickCount == 3){
        bool canAvoid = check();
        if(canAvoid){
            found = true;
        }
        return;
    }
    // 빈곳에만 장애물 넣을 수 있음 
    for(int i=y;i<boardSize;i++){
        for(int j=x;j<boardSize;j++){
            if(board[i][j]=='X'&&!visited[i][j]){
                visited[i][j] = true;
                board[i][j]='O';
                makeComb(pickCount+1,i,j);
                visited[i][j] = false;
                board[i][j]='X';
            }
        }
        x=0;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
            if(board[i][j]=='T'){
                teacher.push_back(make_pair(i,j));
            }
        }
    }
    
    memset(visited,false,sizeof(visited));
    makeComb(0,0,0);
    if(found){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}