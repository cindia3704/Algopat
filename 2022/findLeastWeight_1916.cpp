/*
    작성자: 김지수
    작성일: 2022/09/21
    백준 -- 최소비용 구하기 (1916번)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 1001
#define INF 1000000001
using namespace std; 

int nodeCnt,edgeCnt;
vector<pair<int,int> > graph[MAX];
int board[MAX][MAX];
long long dist[MAX];

void dijkstra(int node,int endNode){
    priority_queue<pair<int,int> > q;
    dist[node] = 0;
    q.push(make_pair(0,node));

    while(!q.empty()){
        int now = q.top().second;
        long long nowDist = q.top().first;
        q.pop();
        //cout<<" nowDist:"<<nowDist<<"  now:"<<now<<endl;
        if(dist[now]<nowDist){
            continue;
        }

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            long long nextDist = graph[now][i].second + nowDist;
            //cout<<"  next:"<<next<<"  nextDist:"<<nextDist<<"  dis[next]: "<<dist[next]<<endl;
            if(nextDist<dist[next]){
                dist[next] = nextDist;
                q.push(make_pair(nextDist,next));
            }
        }
        
    }
    cout<<dist[endNode];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin>>nodeCnt>>edgeCnt;

    memset(board,INF,sizeof(board));
        fill(dist,dist+MAX,INF);
    for(int i=0;i<edgeCnt;i++){
        int from,to,w;
        cin>>from>>to>>w;
       graph[from].push_back(make_pair(to,w));
    }
   
    int start,end; 
    cin>>start>>end;
    dijkstra(start,end);
}