/*
    작성자: 김지수
    작성일: 2022/07/13
    백준 -- 탈출 (3055번)
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 51
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};

int height,width;
char board[MAX][MAX];
int visitedWater[MAX][MAX];
int visitedAnimal[MAX][MAX];
bool foundWay = false; 
int houseY,houseX; 
int ans = 0x7fffffff;
queue<pair<pair<int,int>, int> > waterQ; 


void bfsAnimal(int y,int x){
    visitedAnimal[y][x] = 0;
    queue<pair<pair<int,int>, int> > q; 
    q.push(make_pair(make_pair(y,x),0));

    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int nowTime = q.front().second;
        q.pop();

        if(board[now.first][now.second] == 'D'){
            foundWay = true; 
            ans = min(ans,nowTime);
            break;
        }else{
            for(int i=0;i<4;i++){
                int nextY = now.first + dy[i];
                int nextX = now.second+ dx[i];
                if(nextY<0 || nextY>=height || nextX <0 || nextX >=width){
                    continue;
                }
                if(visitedWater[nextY][nextX]<=nowTime+1 &&visitedWater[nextY][nextX]!=-1 ){
                    continue;
                }else{
                    if(visitedAnimal[nextY][nextX]==-1 && board[nextY][nextX]!='X'){
                        visitedAnimal[nextY][nextX] = nowTime+1; 
                        q.push(make_pair(make_pair(nextY,nextX),nowTime+1));
                    }
                }
            }
        }

    }
}

void bfsWater(){
    while(!waterQ.empty()){
        pair<int,int> now = waterQ.front().first;
        int nowTime = waterQ.front().second;
        waterQ.pop();

        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second+ dx[i];
            if(nextY<0 || nextY>=height || nextX <0 || nextX >=width){
                continue;
            }
            if(board[nextY][nextX]!='X' && board[nextY][nextX]!='D'){
                if(visitedWater[nextY][nextX] == -1){
                    visitedWater[nextY][nextX] = nowTime+1;
                    waterQ.push(make_pair(make_pair(nextY,nextX),nowTime+1));
                }
            }
        }
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(visitedAnimal,-1,sizeof(visitedAnimal));
    memset(visitedWater,-1,sizeof(visitedWater));
    int animalY,animalX; 

    cin>>height>>width;
    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            board[i][j] = l[j];
            if(board[i][j] == 'S'){
                animalY = i;
                animalX = j;
            }
            if(board[i][j] == 'D'){
                houseY=i;
                houseX =j;
            }
            if(board[i][j]=='*'){
                waterQ.push(make_pair(make_pair(i,j),0));
                visitedWater[i][j] = 0;
            }
        }
    }
    
    bfsWater();
    bfsAnimal(animalY,animalX);
    
    if(foundWay){
        cout<<ans;
    }else{
        cout<<"KAKTUS";
    }

}