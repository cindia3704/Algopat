/*
    작성자: 김지수
    작성일: 2022/06/26
    백준 -- 소문난 칠공주 (1941번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 6
using namespace std; 

// NESW
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

// 다솜파 학생 위치 담음 
vector<pair<int,int> > dasom;
//도연파 학생 위치 담음 
vector<pair<int,int> > doyeon;
// 다솜파 & 도연파 백트래킹시 이미 넣었는지 여부 위함 
bool visitedDasom[MAX*MAX];
bool visitedDoyeon[MAX*MAX];

// 최종적으로 칠공주 결성할때 1 = 담음, 0 = 안담음 
int picked[MAX][MAX];
bool visited[MAX][MAX];

int ans =0;

// 뽑은 학생들이 모두 인접한지 확인 위해 bfs 돌림 
void bfs(int y,int x){
    queue<pair<int,int> > q; 
    visited[y][x] = true;
    q.push(make_pair(y,x));

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nextY = now.first+ dy[i];
            int nextX = now.second + dx[i];

            if(nextY<0 || nextY >=5 || nextX <0 || nextX>=5){
                continue;
            }

            if(!visited[nextY][nextX] && picked[nextY][nextX] == 1){
                visited[nextY][nextX]=true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
}

void pickDoyeon(int pickCount, int doyeonCount,int start){
    if(pickCount==doyeonCount){        
        memset(visited,false,sizeof(visited));
        // 도연파까지 다 뽑았으면 서로 인접하게 읹았는지 확인 
        int count = 0 ;
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                if(picked[i][j] == 1 && !visited[i][j]){
                    bfs(i,j);
                    count++;
                }
            }
        }
        // 확인했고 인접하게 앉아있으면 경우의 수 +1 
        if(count == 1){
            ans++;
        }
        return;
    }
    for(int i=start;i<doyeon.size();i++){
        if(!visitedDoyeon[i]){
            visitedDoyeon[i] = true;
            picked[doyeon[i].first][doyeon[i].second] = 1;
            pickDoyeon(pickCount+1,doyeonCount,i+1);
            visitedDoyeon[i] = false;
            picked[doyeon[i].first][doyeon[i].second] = 0;
        }
    }
}

void pickDaSom(int pickCount, int dasomCount, int doyeonCount, int start){
    if(pickCount==dasomCount){
        memset(visitedDoyeon,false,sizeof(visitedDoyeon));
        // 다솜파 다 뽑았으면 도연파 같은 방법으로 뽑기 
        pickDoyeon(0,doyeonCount,0);
        return;
    }
    for(int i=start;i<dasom.size();i++){
        // 다솜파 학생들중 칠공주에 넣을 학생 뽑기 
        if(!visitedDasom[i]){
            visitedDasom[i] = true;
            picked[dasom[i].first][dasom[i].second] = 1;
            pickDaSom(pickCount+1,dasomCount,doyeonCount,i+1);
            visitedDasom[i] = false;
            picked[dasom[i].first][dasom[i].second] = 0;

        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0;i<5;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.size();j++){
            // 다솜 & 도연파 학생 위치 담기 
            if(l[j] == 'Y'){
                doyeon.push_back(make_pair(i,j));
            }
            if(l[j] == 'S'){
                dasom.push_back(make_pair(i,j));
            }
        }
    }

    // 다솜파 = 4명이상 가능! 즉, 7명 만드는데 4명 이상, 7명이하 & 다솜파 학생 수 이하 
    for(int i=4;i<=dasom.size();i++){
        int haveToPick = 7-i;
        memset(visitedDasom,false,sizeof(visitedDasom));
        pickDaSom(0,i,haveToPick,0);
    }

    cout<< ans;

}