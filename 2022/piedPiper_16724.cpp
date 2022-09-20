/*
    작성자: 김지수
    작성일: 2022/09/20
    백준 -- 피리 부는 사나이 (16724 번)
*/
#include <iostream> 
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std; 

// L D R U
const int dy[4]={0,1,0,-1};
const int dx[4]={-1,0,1,0};
int height,width;
char board[MAX][MAX];
int visited[MAX][MAX];
bool isCycle[MAX][MAX];
int cnt = 0;

struct Block{
    int y,x;
    char alpha;
};

int convert(char alphabet){
    if(alphabet=='U'){
        return 3;
    }else if(alphabet == 'D'){
        return 1;
    }else if(alphabet == 'L'){
        return 0;
    }else if(alphabet=='R') {
        return 2;
    }
}

void dfs(Block now, int times){
    if(visited[now.y][now.x]!=0){
        if(visited[now.y][now.x] == times){
            cnt++;
            return;
        }else{
            return;
        }
    }
    visited[now.y][now.x] = times; 
    int nowDir = convert(now.alpha);
    Block next;
    next.y = now.y + dy[nowDir];
    next.x= now.x + dx[nowDir];
    next.alpha = board[next.y][next.x];
    dfs(next,times);
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width;
    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            board[i][j] = l[j];
        }
    }
    memset(visited,0,sizeof(visited));
    int times = 1;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(visited[i][j]==0){
                Block b;
                b.y = i;
                b.x = j;
                b.alpha = board[i][j];
                dfs(b,times);
                times++;
            }
        }
    }
    cout<<cnt;
}