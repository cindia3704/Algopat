/*
    작성자: 김지수
    작성일: 2022/09/17
    백준 -- 열쇠 (9328번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 105
using namespace std; 

const int dy[4] = {0,1,0,-1};
const int dx[4] = {-1,0,1,0};
int height,width;
char board[MAX][MAX];
bool haveKey[26];
bool visited[MAX][MAX];
int ans;

void printKey(){
    cout<<"\n====KEYS===="<<endl;
    for(int i=0;i<26;i++){
        cout<<(char)(i+'a')<<": "<<haveKey[i]<<"    ";
    }
    cout <<endl;
}

bool bfs(){
    queue<pair<int,int> > q;
    visited[0][0] = true;
    q.push(make_pair(0,0));
    bool foundSomthing = false;
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
      
        if(board[now.first][now.second]>='a' && board[now.first][now.second]<='z'){
            foundSomthing = true;
            haveKey[board[now.first][now.second]-'a'] = true;
            board[now.first][now.second] = '.';
           // printKey();
        }
        if(board[now.first][now.second]=='$'){
            foundSomthing = true;
            ans++;
            board[now.first][now.second] = '.';
        }
        for(int i=0;i<4;i++){
            int nextY = now.first+dy[i];
            int nextX = now.second+dx[i];
            if(nextY<0 || nextY>=height || nextX<0 || nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX]){
                visited[nextY][nextX]=true;
                if(board[nextY][nextX]=='*'){
                    continue;
                }
                if(board[nextY][nextX]>='A' && board[nextY][nextX]<='Z'){
                    if(haveKey[board[nextY][nextX]-'A']){
                        q.push(make_pair(nextY,nextX));
                    }
                }
                else{
                    q.push(make_pair(nextY,nextX));
                }
            }
        }
    }
    return foundSomthing;
}

void findKeys(){
    bool canContinue = true; 
    while(canContinue){
        memset(visited,false,sizeof(visited));
        canContinue = bfs();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; 
    cin>>tc; 
    while(tc--){
        ans = 0;
        memset(board,'.',sizeof(board));
        memset(haveKey,false,sizeof(haveKey));
        cin>>height>>width;
        for(int i=1;i<=height;i++){
            string l;
            cin>>l;
            for(int j=0;j<l.length();j++){
                board[i][j+1] = l[j];
            }
        }
        height+=2;
        width+=2;
        string keys;
        cin>>keys;
        for(int i=0;i<keys.length();i++){
            if(keys[0]=='0'){
                break;
            }
            haveKey[keys[i]-'a'] = true;
        }
        memset(visited,false,sizeof(visited));
        findKeys();
        cout<<ans<<'\n';
    }
}