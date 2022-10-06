/*
    작성자: 김지수
    작성일: 2022/10/06
    백준 -- 원판 돌리기 (17822번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#define MAX 51
using namespace std;

int wheelCnt,numberCnt,totalTurn;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

deque<int> wheels[MAX];
bool visited[MAX][MAX];



void turn(int wheelNum,int dir,int turnCnt){
    if(dir==0){
        for(int i=0;i<turnCnt;i++){
            int temp = wheels[wheelNum].back();
            wheels[wheelNum].pop_back();
            wheels[wheelNum].push_front(temp);
        }
    }else{
        for(int i=0;i<turnCnt;i++){
            int temp = wheels[wheelNum].front();
            wheels[wheelNum].pop_front();
            wheels[wheelNum].push_back(temp);
        }
    }
}

void turnWheel(int wheelIdx,int dir,int turnCnt){
    for(int i=1;i<=wheelCnt;i++){
        if(i%wheelIdx==0){
            turn(i,dir,turnCnt);
        }
    }
}

void print(){
    cout<<endl;
    for(int i=1;i<=wheelCnt;i++){
        for(int j=0;j<numberCnt;j++){
            cout<<wheels[i][j]<<" ";
        }
        cout<<endl;
    }
}



bool bfs(int y,int x){
    bool found = false;
    int target = wheels[y][x];
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));

    vector<pair<int,int> > v;

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        v.push_back(now);

        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];

            nextX = (nextX<0)? numberCnt-1:(nextX%numberCnt);
            if(nextY<1 || nextY>wheelCnt){
                continue;
            }
            if(!visited[nextY][nextX] && wheels[nextY][nextX]==target){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }

    if(v.size()>1){
        found = true;
        for(int i=0;i<v.size();i++){
            pair<int,int> now = v[i];
            wheels[now.first][now.second] = 0;
        }
    }
    return found;
}


void eraseNum(){
    bool foundAdj = false;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=wheelCnt;i++){
        for(int j=0;j<numberCnt;j++){
            if(!visited[i][j] && wheels[i][j]>0){
                bool tempFound = bfs(i,j);
                if(tempFound){
                    foundAdj = true;
                }
            }
        }
    }
    if(!foundAdj){
        double sum =0;
        double nodeCnt = 0;
        for(int i=1;i<=wheelCnt;i++){
            for(int j=0;j<numberCnt;j++){
                if(wheels[i][j] > 0){
                    sum+=wheels[i][j];
                    nodeCnt++;
                }
            }
        }
        double avgNum = sum/nodeCnt;

        for(int i=1;i<=wheelCnt;i++){
            for(int j=0;j<numberCnt;j++){
                double now = (double) wheels[i][j];
                if(now > avgNum){
                    wheels[i][j]-=1;
                }
                if(now < avgNum && wheels[i][j]!=0){
                    wheels[i][j]+=1;
                }
            }
        }
    }
}

int countScore(){
    int sum = 0;
    for(int i=1;i<=wheelCnt;i++){
        for(int j=0;j<numberCnt;j++){
            sum+=wheels[i][j];
        }
    }
    return sum;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>wheelCnt>>numberCnt>>totalTurn;
    for(int i=1;i<=wheelCnt;i++){
        for(int j=0;j<numberCnt;j++){
            int num;
            cin>>num;
            wheels[i].push_back(num);
        }
    }

    for(int i=0;i<totalTurn;i++){
        int wheelIdx,dir,turnCnt;
        cin>>wheelIdx>>dir>>turnCnt;
        turnWheel(wheelIdx,dir,turnCnt);
        eraseNum();
    }
    cout<<countScore();

}
