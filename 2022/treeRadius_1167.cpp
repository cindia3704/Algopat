/*
    작성자: 김지수
    작성일: 2022/08/02
    백준 -- 트리의 지름 (1167번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;
bool visited[MAX];
int maxNode =0;
vector<pair<int,int> > graph[MAX];
    int ans = 0;


bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.second == b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

int bfs(int node){
    queue<pair<int,int> > q;
    visited[node] = true;
    q.push(make_pair(node,0));
    int ret = 0;
    while(!q.empty()){
        int nowNode = q.front().first;
        int nowDist = q.front().second;
        q.pop();
        ret = max(ret,nowDist);
        for(int i=0;i<graph[nowNode].size();i++){
            int nextNode = graph[nowNode][i].first;
            int nextDist = graph[nowNode][i].second;
            if(!visited[nextNode]){
                visited[nextNode] = true;
                q.push(make_pair(nextNode,nowDist+nextDist));
            }
        }
    }
    return ret;
}


void dfs(int node,int dist){
    visited[node] = true;
    if(ans<dist){
        ans = dist;
        maxNode = node;
    }
    sort(graph[node].begin(),graph[node].end(),cmp);
    for(int i=0;i<graph[node].size();i++){
        if(!visited[graph[node][i].first]){
            dfs(graph[node][i].first,dist+graph[node][i].second);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int nodeCnt;
    cin>>nodeCnt;
    
    for(int i=0;i<nodeCnt;i++){
        int nowNode; 
        cin>>nowNode;
        int nextNode;
        cin>>nextNode;

        while(nextNode!=-1){
            int weight;
            cin>>weight;
            graph[nowNode].push_back(make_pair(nextNode,weight));
            cin>>nextNode;        
        }
    }
   
    // 임의의 정점에서 가장 거리가 먼 정점 찾구 (maxNode)
    memset(visited,false,sizeof(visited));
    dfs(1,0);
    // 찾은 정점에서 다시 가장 거리가 먼 정점 찾으면 트리 지름 찾을 수 잇음 
    memset(visited,false,sizeof(visited));
    dfs(maxNode,0);
    cout<<ans;
}