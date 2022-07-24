/*
    작성자: 김지수
    작성일: 2022/07/25
    백준 -- 색종이 붙이기 (17136번)
*/

#include <iostream>
#include <cstring>
using namespace std;

int board[10][10];
int temp[10][10];
bool visited[10][10];
int numPaperUsed[5]; 
bool found = false;
int ans = 0x7ffffff;

void print(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

// 색종이로 커버 못하면 -1, 할수 있으면 커버한 너비 반환 
int putPaper(int y,int x,int k){
    for(int i=y;i<y+k;i++){
        for(int j=x;j<x+k;j++){
            if(i<0 || j<0 || i>=10 || j>=10){
                return -1; 
            }
            if(board[i][j] != 1){
                return -1; 
            }
        }
    }
    int countCover = 0;
    for(int i=y;i<y+k;i++){
        for(int j=x;j<x+k;j++){
           visited[i][j] = true;
           board[i][j] = 2; 
           countCover++;
        }
    }
    return countCover;
}

void takeOffPaper(int y,int x,int k){
    for(int i=y;i<y+k;i++){
        for(int j=x;j<x+k;j++){
           board[i][j] = 1; 
           visited[i][j] = false;
        }
    }
}

void makeComb(int pickCount, int sy,int sx, int totalCount,int usedSticker){
    // 색종이로 채워야하는 공간 다 채웠을 경우 
    if(pickCount == totalCount){
        // 답 업데이트 
        found = true;
        if(usedSticker<ans){
            ans = usedSticker;
        }
        return;
    }
    // 보드 복사본 만들기 
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            temp[i][j] = board[i][j]; 
        }
    }

    // 보드 보면서 아직 방문 안했고, 스티커 붙여야하는 공간이면 (1 인경우) 
    for(int i=sy;i<10;i++){
        for(int j=sx;j<10;j++){
            if(!visited[i][j] && board[i][j] == 1){
                // 만약 해당 공간에 색종이 붙일 수 없으면 백트레킹 해주기 위해 붙였는지 여부 관리 
                bool foundSticker = false;
                // 크기 1~ 5 색종이중 5개 미만으로 사용한 색종이 고름 
                for(int stickerNum = 1;stickerNum<=5;stickerNum++){
                    if(numPaperUsed[stickerNum-1]<5){ 
                        // 해당 색종이 붙일수 있는지 판단 
                        int covered = putPaper(i,j,stickerNum); 
                        // 붙일 수 없으면 다음 색종이 보기 
                        if(covered == -1){
                            continue;
                        }else{
                            // 붙일수 있으면, 색종이 사용개수 올려주고 
                            numPaperUsed[stickerNum-1]++;
                            foundSticker = true; 
                            // 다음 위치 보기 
                            makeComb(pickCount+covered,i,j,totalCount,usedSticker+1);
                            // 다시 돌아왔으면 해당 색종이로 커버한 부분 언커버 & 색종이 사용 개수 -1 
                            takeOffPaper(i,j,stickerNum);
                            numPaperUsed[stickerNum-1]-- ;
                            foundSticker = false;
                        }
                    }
                }
                // 색종이로 해당 부분 못채우면 백트레킹 
                if(!foundSticker){
                    return;
                }
            }
        }
        sx=0; 
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int target = 0;
    // 색종이로 채워야하는 공간 세기 
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>board[i][j]; 
            if(board[i][j] == 1){
                target++;
            }
        }
    }

    memset(visited,false,sizeof(visited));
    makeComb(0,0,0,target,0);
    if(!found){
        ans = -1;
    }
    cout<<ans;
}