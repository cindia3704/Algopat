/*
    작성자: 김지수
    작성일: 2022/07/26
    백준 -- 트리 (1068번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 51
using namespace std; 

bool alive[MAX];
vector<int> graph[MAX];
int nodeCnt;
// 노드의 자식노드들 타고가서 다 지우기 
void eraseNode(int node){
    alive[node] = false;
    for(int i=0;i<graph[node].size();i++){
        eraseNode(graph[node][i]);
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 아직 다 살아있음
    memset(alive,true,sizeof(alive));

    cin>>nodeCnt;
    // 자식노드 기록하기 
    for(int i=0;i<nodeCnt;i++){
        int parent;
        cin>>parent;
        if(parent == -1){
            continue;
        }
        graph[parent].push_back(i);
    }

    int eraseNum;
    cin>>eraseNum;
    eraseNode(eraseNum);

    int ans =0;
    // 모든 노드 돌면서 
    for(int i=0;i<nodeCnt;i++){
        // 해당 노드가 아직 살아있고
        if(alive[i]){
            // 자식이 없거나, 다 죽은 경우
            bool foundAlive = false;
            for(int j=0;j<graph[i].size();j++){
                if(alive[graph[i][j]]){
                    foundAlive = true;
                }
            }
            // 리프노드 개수 ++ 
            if(!foundAlive){
                ans++;
            }
        }
    }
    cout<<ans;
}