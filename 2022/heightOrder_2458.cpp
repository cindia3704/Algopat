/*
    작성자: 김지수
    작성일: 2022/09/20
    백준 -- 키 순서 (2458 번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 501
#define INF 10000
using namespace std; 

int nodeCnt,edgeCnt;
int dist[MAX][MAX];
int ret[MAX][MAX];

bool check(int col){
    int num = 0;
    for(int i=1;i<=nodeCnt;i++){
        if(dist[col][i]!=INF || dist[i][col]!=INF){
            num++;
        }
    }
    if(num==nodeCnt-1){
        return true;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>nodeCnt>>edgeCnt;
    for(int i=0;i<MAX;i++){
        fill(dist[i],dist[i]+MAX,INF);
    }
    

    for(int i=0;i<edgeCnt;i++){
        int a,b;
        cin>>a>>b;
        dist[a][b] =1;
    }

    
    for(int k=1;k<=nodeCnt;k++){
        for(int start=1;start<=nodeCnt;start++){
            for(int end=1;end<=nodeCnt;end++){
                if(dist[start][end] > (dist[start][k]+dist[k][end])){
                    dist[start][end] = dist[start][k]+dist[k][end];
                }
            }
        }
    }


    int cnt = 0;
    for(int i=1;i<=nodeCnt;i++){
        bool ret= check(i);
        if(ret){
            cnt++;
        }
    }
    cout<<cnt;
}