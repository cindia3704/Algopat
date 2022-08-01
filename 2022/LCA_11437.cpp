/*
    작성자: 김지수
    작성일: 2022/08/01
    백준 -- LCA (11437s번)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 50001
using namespace std;
int nodeCnt;

vector<int> tree[MAX]; 
int parent[MAX];
bool visited[MAX];
int depth[MAX];

//부모노드 찾으면서 해당 노드의 깊이도 같이 저장 
void makeParent(){
    queue<int> q;
    memset(visited,false,sizeof(visited));
    visited[1] = true;
    depth[1]=0;
    q.push(1);
    while(!q.empty()){
        int nowNode = q.front();
        q.pop();
        for(int i=0;i<tree[nowNode].size();i++){
            int nextNode = tree[nowNode][i];

            if(!visited[nextNode]){
                depth[nextNode] = depth[nowNode]+1;
                parent[nextNode]=nowNode;
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }

    }
}

// 가장 가까운 조상 노드 찾기 
int findParent2(int target1,int target2){
    // 두 노드가 같으면 그대로 반환
    if(target1 == target2) return target1;
    // 두 노드의 깊이가 같으면 둘의 부모 비교 
    else if(depth[target1] == depth[target2]){
        return findParent2(parent[target1],parent[target2]);
    }else if(depth[target1]>depth[target2]){
        return findParent2(parent[target1],target2);
    }else if(depth[target1]<depth[target2]){
        return findParent2(target1,parent[target2]);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>nodeCnt; 
    // 어떤게 부모인지 모르니 양방향 그래프 형식으로 저장 
    for(int i=0;i<nodeCnt-1;i++){
        int node1,node2;
        cin>>node1>>node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    memset(parent,-1,sizeof(parent));
    // 그래프모향을 트리로 바꾸기 
    makeParent();
    int findCnt;
    cin>>findCnt;
    for(int i=0;i<findCnt;i++){
        int target1,target2; 
        cin>>target1>>target2;
        cout<<findParent2(target1,target2);
        cout<<'\n';
    }
}