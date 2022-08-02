/*
    작성자: 김지수
    작성일: 2022/08/03
    백준 -- 알고스팟 (1261번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
#define MAX 101
using namespace std;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
int height,width;
int board[MAX][MAX];
bool visited[MAX][MAX];
int ans =0x7fffffff;

void bfs(){
    deque<pair<pair<int,int>, int> > s;
    s.push_back(make_pair(make_pair(0,0),0));

    while(!s.empty()){
        pair<int,int> now = s.front().first;
        int brkCnt = s.front().second;
        s.pop_front();
        // 답 찾으면 바로 끝냄 
        if(now.first==height-1 && now.second == width-1){
            ans = min(ans,brkCnt);
            break;
        }else{
            // 운영진이 갈수 있는 곳 보면서 
            for(int i=0;i<4;i++){
                int nextY = now.first+dy[i];
                int nextX = now.second+dx[i];
                // 미로 밖이면 무시 
                if(nextY<0 || nextY>=height || nextX<0 || nextX >=width){
                    continue;
                }
                // 아직 방문하지 않은 곳이면 
                if(!visited[nextY][nextX]){
                    // 방문 처리 
                    visited[nextY][nextX]= true;
                    // 비어있으면 -> 우선순위가 더 높음 (여기를 방문하는게 좋음) 따라서 앞에 넣어주기 
                    if(board[nextY][nextX]==0){
                        s.push_front(make_pair(make_pair(nextY,nextX),brkCnt));
                    }else{
                        // 벽뿌셔야 하면 우선순위가 뒤로 밀림 -> 뒤에 넣기 
                        s.push_back(make_pair(make_pair(nextY,nextX),brkCnt+1));
                    }
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>width>>height;

    // 미로 입력받기 
    for(int i=0;i<height;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            board[i][j] = s[j]-'0';
        }
    }

    memset(visited,false,sizeof(visited));
    bfs();
    cout<<ans;
}