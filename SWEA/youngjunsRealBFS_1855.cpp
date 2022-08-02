/*
    작성자: 김지수
    작성일: 2022/08/02
    SWEA -- 영준이의 진짜 BFS (1855번)
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std; 

vector<int> graph[MAX];
int parent[MAX][20];
int depth[MAX];
bool visited[MAX];
vector<int> turns;
int maxHeight; 

void getParent(int totalNodes){
    memset(parent,0,sizeof(parent));
    memset(depth,0,sizeof(depth));
    memset(visited,false,sizeof(visited));
    queue<int> q; 
    visited[1] = true;
    q.push(1);
    depth[1] = 0;
    parent[1][0] = 0;
    while(!q.empty()){
        int nowNode = q.front();
        turns.push_back(nowNode);
        q.pop();
        sort(graph[nowNode].begin(),graph[nowNode].end());
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

long long LCA(int node1, int node2){
    if(depth[node1]!= depth[node2]){
        if(depth[node1]<depth[node2]){
            int temp = node2; 
            node2 = node1;
            node1 = temp;
        }
        int diff = depth[node1]-depth[node2];
        for(int i=0;diff>0;++i){
            if(diff%2==1){
                node1 = parent[node1][i];
            }
            diff = diff>>1;
        }
    }

    if(node1!=node2){
        for(int i=maxHeight;i>=0;i--){
            if(parent[node1][i]!=0 && parent[node1][i]!=parent[node2][i]){
                node1 = parent[node1][i];
                node2 = parent[node2][i];
            }
        }
        node1 = parent[node1][0];
    }
    return node1;
}

int main(void){
    int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        int nodeCnt;
        long long sumEdge = 0;
        maxHeight = 0;
        cin>>nodeCnt;
        turns.clear();
        for(int i=0;i<MAX;i++){
            graph[i].clear();
        }

        for(int i=2;i<=nodeCnt;i++){
            int node;
            cin>>node;
            graph[i].push_back(node);
            graph[node].push_back(i);
        }

        getParent(nodeCnt);
        int temp = nodeCnt;
        while(temp>1){
            temp = temp>>1;
            maxHeight++;
        }

        for(int par =1;par<=maxHeight;par++){
            for(int node = 2; node<=nodeCnt;node++){
                if(parent[node][par-1]!=0){
                    parent[node][par] = parent[parent[node][par-1]][par-1];
                }
            }
        }


        for(int i=0;i<turns.size()-1;i++){
            int target1 = turns[i];
            int target2 = turns[i+1];
            int lca = LCA(target1,target2);
            if(target1 == lca){
                sumEdge += depth[target2] - depth[lca];
            }else if(target2 == lca){
                sumEdge += depth[target1] - depth[lca];
            }else{
                sumEdge += depth[target1] - depth[lca];
                sumEdge += depth[target2] - depth[lca];
            }
        }
        cout<<"#"<<test_case<<" "<<sumEdge<<'\n';
	}
	return 0;
}