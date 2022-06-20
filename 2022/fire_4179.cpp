/*
    작성자: 김지수
    작성일: 2022/06/20
    백준 -- 불! (4179번)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4] = {-1,0,1,0};

char board[MAX][MAX];
int fireVisited[MAX][MAX];
int jihoonVisited[MAX][MAX];
queue<pair<pair<int,int> ,int> > fireQ;

int height,width; 

pair<bool,long long> bfsJihoon(int y,int x){
    queue<pair<pair<int,int> ,long long> > q; 
    jihoonVisited[y][x] =0;
    q.push(make_pair(make_pair(y,x),0));
    bool canExit = false;
    long long turnCount =987654321;
    while(!q.empty()){
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        long long nowCount = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX+ dx[i];
            if(nextY <0 || nextY>=height || nextX <0 || nextX>=width){
                canExit = true;
                if(turnCount>nowCount+1){
                    turnCount = nowCount+1;
                }
            }
            // ** 주의!! 지훈이가 가려는 곳에 불이 가지 않았을 수 있음 
            if(jihoonVisited[nextY][nextX]==-1 && board[nextY][nextX]=='.' && (fireVisited[nextY][nextX]>nowCount+1 || fireVisited[nextY][nextX]==-1)){
                jihoonVisited[nextY][nextX] = nowCount+1; 
                q.push(make_pair(make_pair(nextY,nextX),nowCount+1));
            }
        }
    }
    return make_pair(canExit,turnCount);
}

void bfsFire(int y,int x){

    while(!fireQ.empty()){
        int nowY = fireQ.front().first.first;
        int nowX = fireQ.front().first.second;
        int nowCount = fireQ.front().second;
        fireQ.pop();

        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX+ dx[i];
            if(nextY <0 || nextY>=height || nextX <0 || nextX>=width){
                continue;
            }
            if(fireVisited[nextY][nextX]==-1 && (board[nextY][nextX]=='.' || board[nextY][nextX]=='J')){
                fireVisited[nextY][nextX] = nowCount+1; 
                fireQ.push(make_pair(make_pair(nextY,nextX),nowCount+1));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>height>>width;
    int jy,jx,fy,fx;
    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            board[i][j] = l[j];
            if(board[i][j] == 'J'){
                jy=i;
                jx=j;
            }
            if(board[i][j] == 'F'){
                // 불이 여러개 있을 수 있어, 큐에 넣고, 방문 처리 
                fireQ.push(make_pair(make_pair(i,j),0));
                fireVisited[i][j] =0;
            }
        }
    }

    for(int i=0;i<MAX;i++){
        fill(fireVisited[i],fireVisited[i]+MAX,-1);
        fill(jihoonVisited[i],jihoonVisited[i]+MAX,-1);
    }

    // 불 먼저 번짐 
    bfsFire(fy,fx);
    pair<bool, long long > ans = bfsJihoon(jy,jx);

    if(ans.first == false){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<ans.second;
    }

}