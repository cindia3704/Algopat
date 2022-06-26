/*
    작성자: 김지수
    작성일: 2022/06/27
    백준 -- Puyo Puyo (11559번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4] = {-1,0,1,0};

char board[12][6];
char temp[12][6];
bool visited[12][6];
int ans =0; 

bool bfs(int y,int x,char color){
    bool ret = false;
    queue<pair<int,int> > q; 
    vector<pair<int,int> > v; 
    visited[y][x] = true;

    q.push(make_pair(y,x));
    
    while(!q.empty()){
        pair<int,int> now = q.front();
        v.push_back(now);
        q.pop();

        for(int i=0;i<4;i++){
            int nextY = now.first+ dy[i];
            int nextX = now.second+dx[i];
            if(nextY<0 || nextY >=12 || nextX <0 || nextX >=6){
                continue;
            }

            if(!visited[nextY][nextX] && board[nextY][nextX] == color){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX));
            }
        }
    }
    
    // 인접한 같은 색의 뿌요가 4개 이상일때만 '.'으로 바꿈 
    if(v.size()>=4){
        ret = true;
        for(int i=0;i<v.size();i++){
            temp[v[i].first][v[i].second] = '.';
        }
    }
    return ret;
}

// 중력 작용 밑에서부터 보며 '.' 가 아닐때 idx 하나씩 올려가며 board 채워줌 
void gravity(){
    // 뿌요가 아닌칸은 모두 '.'
    memset(board,'.',sizeof(board));
    // 뿌요인 칸들만 업데이트 
    for(int i=0;i<6;i++){
        int idx=11;
        for(int j=11;j>=0;j--){
            if(temp[j][i] == '.'){
                continue;
            }else{
                board[idx][i] = temp[j][i];
                idx--;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    for(int i=0;i<12;i++){
        string puyo;
        cin>>puyo;
        for(int j=0;j<6;j++){
            board[i][j] = puyo[j];
        }
    }

    while(1){
        memset(visited,false,sizeof(visited));
        //복사본 만들기 
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                temp[i][j] = board[i][j];
            }
        }
        
        int countFound = 0;
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(board[i][j]!='.' && !visited[i][j]){
                    bool ret = bfs(i,j,board[i][j]);
                    // 연쇄 일어나면 연쇄 횟수 ++ 
                    if(ret){
                        countFound++;
                    }
                }
            }
        }

        // 연쇄가 하나도 일어나지 않았으면 그만함 
        if(countFound==0){
            break;
        }
        
        // 중력 작용 -> 뿌요 밑에 '.'가 있으면 밑으로 내리기 
        gravity();
        
        ans++; 
    }

    cout<<ans;
    
}