/*
    작성자: 김지수
    작성일: 2022/09/20
    백준 -- 텀 프로젝트 (9466 번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 100001
using namespace std;

int nodeCnt; 
int graph[MAX];
bool isCycle[MAX];
int visited[MAX];

// 반환 -2: 여기서 부터는 싸이클 아님, 양수: 해당 노드 찾을때까지 계속 싸이클 처리, -1 : 싸이클 못찾음 
int dfs(int node,int times){
    visited[node] = times;
    // 다음 노드가 0이면 끝! 0보다 클때만 돌리고 
    int next = graph[node];
    if(next>0){
        // 아직 방문 전이면 방문 
        if(visited[next]==0){
            int ret= dfs(next,times);
            if(ret ==-2){
                return -2; 
            }
            if(ret>0){
                isCycle[node] = true;
                if(ret == node){
                    return -2;
                }else{
                    return ret;
                }
            }
       }else{
        //방문 한적 있고, 이번에 방문한거다 -> 싸이클 찾음! (양방향 그래프가 아니라! )
            if(visited[next]>0 && visited[next] == times){
                isCycle[node] = true;
                if(next == node){
                    return -2;
                }else{
                    return next;
                }
            }else{
                return -2;
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc; 
    while(tc--){
        memset(graph,0,sizeof(graph));
        memset(isCycle,false,sizeof(isCycle));
        memset(visited,0,sizeof(visited));
        cin>>nodeCnt;
        for(int i=1;i<=nodeCnt;i++){
            int num;
            cin>>num;
            graph[i] = num;
        }
        int times = 1;
        for(int i=1;i<=nodeCnt;i++){
            if(visited[i]==0){
                dfs(i,times);
                times++;
            }
        }
        
        int cnt = 0;
        for(int i=1;i<=nodeCnt;i++){
            if(!isCycle[i]){
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
}