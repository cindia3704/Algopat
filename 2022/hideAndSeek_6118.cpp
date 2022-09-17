/*
    작성자: 김지수
    작성일: 2022/09/17
    백준 -- 숨바꼭질 (6118번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 20001
using namespace std; 
int nodeCnt,edgeCnt;

vector<int> graph[MAX];
bool visited[MAX];
int maxDist;
int numCnt; 
int minNode; 

void bfs(){
    memset(visited,false,sizeof(visited));
    maxDist = 0;
    numCnt =0;
    minNode=0x7fffffff;
    queue<pair<int,int> > q;
    visited[1] =true;
    q.push(make_pair(1,0));

    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(maxDist == dist){
            numCnt++;
            minNode = min(minNode,node);
        }else{
            maxDist = dist; 
            numCnt=1;
            minNode = min(0x7fffffff,node);
        }
        for(int i=0;i<graph[node].size();i++){
            if(!visited[graph[node][i]]){
                visited[graph[node][i]] = true;
                q.push(make_pair(graph[node][i],dist+1));
            }
        }
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>nodeCnt>>edgeCnt;
    for(int i=0;i<edgeCnt;i++){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    bfs();
    cout<<minNode<<" "<<maxDist<<" "<<numCnt<<endl;
}
