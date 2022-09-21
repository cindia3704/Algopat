/*
    작성자: 김지수
    작성일: 2022/09/20
    백준 -- 플로이드 (11404번)
*/

#include <iostream>
#include <cstring>
#define MAX 101
#define INF 100000001   // 비용 최대 = 100,000 & 노드 최대수 = 100 => 최대 비용 = 곱한거
using namespace std; 

int nodeCnt,edgeCnt;
int dist[MAX][MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>nodeCnt>>edgeCnt;
    for(int i=0;i<=nodeCnt;i++){
        fill(dist[i],dist[i]+MAX,INF);
        dist[i][i] = 0;
    }

    for(int i=0;i<edgeCnt;i++){
        int a,b,w;
        cin>>a>>b>>w;
        if(dist[a][b]>w){
            dist[a][b]=w;
        }
    }
    

    for(int k=1;k<=nodeCnt;k++){
        for(int i=1;i<=nodeCnt;i++){
            for(int j=1;j<=nodeCnt;j++){
                if(i==j){
                    continue;
                }
                if(dist[i][j] > (dist[i][k]+dist[k][j])){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i=1;i<=nodeCnt;i++){
        for(int j=1;j<=nodeCnt;j++){
            if(dist[i][j]==INF){
                cout<<0<<" ";
            }else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
}