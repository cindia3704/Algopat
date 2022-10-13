/*
    작성자: 김지수
    작성일: 2022/10/13
    코드트리 -- 자율주행 자동차 (8번)
*/

#include <iostream> 
#include <algorithm>
#include <stack>
#define MAX 51
#define ROAD 0
#define STREET 1
using namespace std; 

int height,width;
const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};
int board[MAX][MAX];
bool visited[MAX][MAX];
int carY,carX,carDir;

bool OOB(int y,int x){
    return (y<0 || y>=height || x<0 || x>=width);
}

int getReverseDir(int dir){
    if(dir == 0){
        return 2; 
    }else if(dir ==2){
        return 0;
    }else if(dir ==1){
        return 3;
    }else{
        return 1;
    }
}

void startGame(){
    stack<pair<pair<int,int>,int> > st; 
    visited[carY][carX] = true;
    st.push(make_pair(make_pair(carY,carX),carDir));
    bool exit = false;

    while(!st.empty()&&!exit){
        pair<int,int> now = st.top().first;
        int nowDir = st.top().second;
        st.pop();
        bool foundWay = false;
        for(int i=0;i<4;i++){
            nowDir =(nowDir-1+4)%4;
            int nextY = now.first + dy[nowDir];
            int nextX = now.second + dx[nowDir];
            if(OOB(nextY,nextX)){
                continue;
            }
            if(!visited[nextY][nextX] && board[nextY][nextX]==ROAD){
                foundWay = true;
                visited[nextY][nextX] = true;
                st.push(make_pair(make_pair(nextY,nextX),nowDir));
                break;
            }
        }
        if(!foundWay){
            int revDir = getReverseDir(nowDir);
            int nextY = now.first+ dy[revDir];
            int nextX = now.second + dx[revDir];
            if(OOB(nextY,nextX) || board[nextY][nextX]!=ROAD){
                exit = true;
                break;
            }else{
                st.push(make_pair(make_pair(nextY,nextX),nowDir));
                visited[nextY][nextX] = true;
            }
        }
    }
}

int countArea(){
    int cnt = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(visited[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>height>>width;
    cin>>carY>>carX>>carDir;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
            visited[i][j] = false;
        }
    }
    startGame();
    cout<<countArea();
}