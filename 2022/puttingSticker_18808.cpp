/*
    작성자: 김지수
    작성일: 2022/06/24
    백준 -- 스티커 붙이기 (18808번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue> 
#define MAX 41
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];
int height,width,stickerNum; 
struct STICKER{
    int h,w; 
    int shape[MAX][MAX];
};

vector<STICKER> stickerList;


void bfs(int y,int x){
    queue<pair<int,int> > q; 
    q.push(make_pair(y,x));
    visited[y][x] = true;

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nextY = now.first + dy[i];
            int nextX = now.second+dx[i];
            if(nextY<0 || nextY >=height || nextX<0||nextX >=width){
                continue;
            }
            if(!visited[nextY][nextX] && temp[nextY][nextX] == 1){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY,nextX)); 
            }
        }
    }
}

STICKER turn(int degree, STICKER s){
    STICKER next;
    int h = s.h;
    int w = s.w; 
    if(degree == 0){
        next= s;
    }else if(degree ==1){   // 시계방향으로 90도 회전  
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                next.shape[i][j] = s.shape[s.h-j-1][i];
            }
        }
        next.h = w;
        next.w = h;
    }else if(degree ==2){   // 시계방향으로 180도 회전  
        int tempSticker[MAX][MAX];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                next.shape[i][j] = s.shape[s.h-i-1][s.w-j-1];
            }
        }
        next.h = h;
        next.w = w;
    }else if(degree ==3){   // 시계방향으로 270도 회전  
        int tempSticker[MAX][MAX];
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                next.shape[i][j] = s.shape[j][s.w-i-1];
            }
        }
        next.h = w;
        next.w = h;
    }
    return next;
}
void copytBoardToTemp(){
    // 보드 복사본 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            temp[i][j] = board[i][j];
        }
    }
}
void copyTempToBoard(){
    // 보드 복사본 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = temp[i][j];
        }
    }
}

bool checkConnected(){
    int isConnected = 0;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(!visited[i][j] && temp[i][j]==1){
            if(isConnected >=1){
                return false;
            }else{
                bfs(i,j);
                isConnected++;
            }
            }
        }
    }
    return true; 
}

bool check(int y,int x,STICKER s){
    for(int i=0;i<s.h;i++){
        for(int j=0;j<s.w;j++){
            if(i+y<0 || i+y>=height || j+x<0 || j+x>=width){
                return false;
            }
            if(temp[i+y][j+x] == 1 && s.shape[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

void putSticker(int y,int x,STICKER s){
    for(int i=0;i<s.h;i++){
        for(int j=0;j<s.w;j++){
            if(temp[i+y][j+x] == 0 && s.shape[i][j] == 1){
                temp[i+y][j+x] =1;
            }
        }
    }
    return;
}

void inputStiker(int idxSticker){
    STICKER now = stickerList[idxSticker];

    bool foundFit = false;
    STICKER turned;
    copytBoardToTemp();
    bool isConnected = false; 
    
    for(int i=0;i<4;i++){
        turned =  turn(i,now);

        for(int j=0;j<height;j++){
            for(int k=0;k<width;k++){
                bool canPut = check(j,k,turned);
                if(canPut){
                    putSticker(j,k,turned);
                    isConnected = checkConnected(); 
                    if(isConnected){
                        copyTempToBoard();
                        return;
                    }else{
                        copytBoardToTemp();
                    }
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width>>stickerNum;
    memset(board,0,sizeof(board));
    for(int i=0;i<stickerNum;i++){
        STICKER now; 
        cin>>now.h>>now.w;
        for(int j=0;j<now.h;j++){
            for(int k=0;k<now.w;k++){
                cin>>now.shape[j][k];
            }
        }
        stickerList.push_back(now);
    }
    
    for(int i=0;i<stickerNum;i++){
        inputStiker(i);
    }

    int stickerSize=0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==1){
                stickerSize++;
            }
        }
    }
    cout<<stickerSize;
}