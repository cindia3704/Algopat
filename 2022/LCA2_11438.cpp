/*
    작성자: 김지수
    작성일: 2022/08/02
    백준 -- LCA 2 (11438번)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std; 

int nodeCnt; 
vector<int> graph[MAX];
int parent[MAX][20];
int depth[MAX];
bool visited[MAX];
int maxHeight = 0;


void calcParent(){
    queue<int> q; 
    visited[1] = true; 
    q.push(1);
    parent[1][0] = 0;
    depth[1] = 0;

    while(!q.empty()){
        int nowNode = q.front();
        q.pop();
        for(int i=0;i<graph[nowNode].size();i++){
            int nextNode = graph[nowNode][i];
            if(!visited[nextNode]){
                visited[nextNode] = true;
                parent[nextNode][0] = nowNode;
                depth[nextNode] = depth[nowNode]+1;
                q.push(nextNode);
            }
        }
    }
}

int LCA(int a,int b){
    if(depth[a]!=depth[b]){
        if(depth[a]<depth[b]){
           int temp = b; 
           b=a;
           a=temp;
        }
        int difference =depth[a] - depth[b];
        for(int i=0;difference>0;++i){
            if(difference%2 == 1){
                a = parent[a][i];
            }
            difference=difference>>1;
        } 

    }

    if(a!=b){
        for(int i=maxHeight;i>=0;i--){
            if(parent[a][i]!=0 && parent[a][i] != parent[b][i]){
                 a= parent[a][i];
                 b= parent[b][i];
            }
        }
         a = parent[a][0];
    }
    return a;
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin>>nodeCnt;
    for(int i=0;i<nodeCnt-1;i++){
        int a,b; 
        cin>>a>>b; 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    memset(parent,0,sizeof(parent));
    memset(depth,0,sizeof(depth));

    calcParent();
    
    int temp = nodeCnt;
    while(temp>1){
        temp = temp>>1;
        maxHeight++;
    }

    // DP 
    for(int par = 1; par<=maxHeight;par++){
        for(int node = 2;node<=nodeCnt;node++){
            if(parent[node][par-1]!=0){
                parent[node][par] = parent[parent[node][par-1]][par-1];
            }
        }
    }
    int findCnt;
    cin>>findCnt;
    for(int i=0;i<findCnt;i++){
        int target1,target2;
        cin>>target1>>target2;
        cout<<LCA(target1,target2);
        cout<<'\n';
    }

}