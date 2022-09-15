/*
    작성자: 김지수
    작성일: 2022/09/16
    백준 -- 뱀과 사다리 게임 (16928번)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std; 

vector<int> graph[MAX];
bool visited[MAX];
int isNotBlock[MAX];
int ans = 0x7fffffff;

void bfs(){
    memset(visited,false,sizeof(visited));
    queue<pair<int, int> > q;
    visited[1] = true;
    q.push(make_pair(1,0));
    while(!q.empty()){
        int nowBoard = q.front().first;
        int nowCnt = q.front().second;
        q.pop();
        if(nowBoard == 100){
            ans = min(ans,nowCnt);
        }
        for(int i=1;i<=6;i++){
            int next = nowBoard+i;
            if(next>100){
                break;;
            }else{
                if(isNotBlock[next]!=0 && !visited[next]){
                    visited[next] = true;
                    q.push(make_pair(isNotBlock[next],nowCnt+1));
                }
                if(!visited[next]){
                    visited[next] = true;
                    q.push(make_pair(next,nowCnt+1));
                }
                
            }
        }
        
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(isNotBlock,0,sizeof(isNotBlock));
    int ladderCnt, snakeCnt;
    cin>>ladderCnt>>snakeCnt;
    for(int i=0;i<ladderCnt+snakeCnt;i++){
        int from,to;
        cin>>from>>to;
        isNotBlock[from] = to;
    }

    bfs();
    cout<<ans;
}