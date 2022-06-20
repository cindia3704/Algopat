/*
    작성자: 김지수
    작성일: 2022/06/21
    백준 -- 숨바꼭질 3 (13529번)
*/

#include <iostream>
#include <deque> 
#include <algorithm> 
#define MAX 200001
using namespace std;

bool visited[MAX];
long long ans = 987654321;

void bfs(int pos,int target){
    deque<pair<int,long long> > q; 
    visited[pos] = true;
    q.push_back(make_pair(pos,0));
    bool foundWay = false;

    while(!q.empty()){
        int nowPos = q.front().first;
        long long nowTime = q.front().second;
        q.pop_front();

        if(nowPos == target){
            foundWay = true;
            if(ans>nowTime){
                ans = nowTime;
            }
        }
        int moveFront = nowPos+1; 
        int moveBack = nowPos-1;
        int moveTwice = nowPos*2; 
        // 덱 안쓰면 *2는 방문하겠지만, 방문하는 시간이 달라짐 (첫번째 방문일때만 넣기 때문 )
        if(moveTwice>=0 && moveTwice<MAX){
            if(!visited[moveTwice]){
                visited[moveTwice] = true;
                q.push_front(make_pair(moveTwice,nowTime));
            }
        }
        
        if(moveFront>=0 && moveFront<MAX){
            if(!visited[moveFront]){
                visited[moveFront] = true;
                q.push_back(make_pair(moveFront,nowTime+1));
            }
        }
        if(moveBack>=0 && moveBack<MAX){
            if(!visited[moveBack]){
                visited[moveBack] = true;
                q.push_back(make_pair(moveBack,nowTime+1));
            }
        }
        
    }
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int now,target; 
    cin>>now>>target;
    fill(visited,visited+MAX,false);

    bfs(now,target);
    cout<<ans;

}