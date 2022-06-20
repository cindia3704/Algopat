/*
    작성자: 김지수
    작성일: 2022/06/20
    백준 -- 숨바꼭질 (1697번)
*/

#include <iostream>
#include <algorithm>
#include <queue> 
#define MAX 100001
using namespace std;
bool dist[MAX];
long long ans =987654321;

void bfs(int now, int target){
    queue<pair<int,int> > q; 
    dist[now] = true;
    q.push(make_pair(now,0));
    while(!q.empty()){
        int nowPos = q.front().first;
        int nowCount = q.front().second;
        q.pop();
        if(nowPos == target){
            if(ans>nowCount){
                ans = nowCount;
            }
        }

        int OneAf = nowPos+1; 
        int OneBf = nowPos-1;
        int twice = nowPos*2; 

        if(OneAf>=0 && OneAf < MAX){
            if(!dist[OneAf]){
                dist[OneAf] = true;
                q.push(make_pair(OneAf,nowCount+1));
            }
        }
        if(OneBf>=0 && OneBf < MAX){
            if(!dist[OneBf]){
                dist[OneBf] = true;
                q.push(make_pair(OneBf,nowCount+1));
            }
        }
        if(twice>=0 && twice < MAX){
            if(!dist[twice]){
                dist[twice] = true;
                q.push(make_pair(twice,nowCount+1));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nowDist, targetDist;
    cin>>nowDist>>targetDist;
    fill(dist,dist+MAX,false);
    bfs(nowDist,targetDist); 

    cout<<ans;
}