/*
    작성자: 김지수
    작성일: 2022/06/19
    백준 -- 스타트링크 (5014번)
*/

#include <iostream>
#include <cstring> 
#include <queue> 
#define MAX 4000004
using namespace std; 

int totalLevel, nowLevel, targetLevel, up, down; 
long long ans = 987654321;
bool visited[MAX];

struct LEVEL{
    long long l,countElevator; 
}; 

void bfs(int nowL){
    queue<LEVEL> q; 
    LEVEL now;
    now.l = nowL;
    now.countElevator = 0;
    q.push(now);
    visited[nowL] = true;
    while(!q.empty()){
        long long nowLev = q.front().l;
        long long nowCount = q.front().countElevator;
        q.pop();
        if(nowLev == targetLevel){
            if(ans >nowCount){
                ans = nowCount;
            }
        }
        
        long long nextDown = nowLev - down; 
        long long nextUp = nowLev +up; 
        bool canGoDown = true;
        bool canGoUp = true;
        if(nextDown<=0 || nextDown>totalLevel+up){
            canGoDown = false;
        }
        if(nextUp<=0 || nextUp>totalLevel+up){
            canGoUp = false; 
        }
        else{
            if(canGoDown){
            if(!visited[nextDown] ){
                visited[nextDown] = true; 
                LEVEL next; 
                next.countElevator = nowCount+1;
                next.l = nextDown;
                q.push(next);
            }}
            if(canGoUp){
            if(!visited[nextUp] && canGoUp){
                visited[nextUp] = true; 
                LEVEL next; 
                next.countElevator = nowCount+1;
                next.l = nextUp;
                q.push(next);
            }
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>totalLevel>>nowLevel>>targetLevel>>up>>down;
    memset(visited,false,sizeof(visited));
    bfs(nowLevel);

    if(ans == 987654321){
        cout<<"use the stairs";
    }else{
    cout<<ans;
    }
}