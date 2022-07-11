/*
    작성자: 김지수
    작성일: 2022/07/11
    백준 -- 넴모넴모(Easy) (16234번)
*/

#include <iostream>
#include <cstring>
#define MAX 26
using namespace std; 

int board[MAX][MAX];
bool visited[MAX][MAX];
int height,width;
int ans =0;

bool checks(int y,int x){
    // 보드 범위 넘어가면 false 
    if(y-1<0 || y-1 >=height || x-1 <0 || x-1>=width){
        return false;
    }else{
        // 나머지 2x2 이루는 칸에 넴모 모두 차있는 경우만 true 
        return board[y][x-1] && board[y-1][x] && board[y-1][x-1];
    }
}

void makeComb(int pickCount,int y,int x){
   // 사용한 타일 수가 전체 보드크기랑 같을때 돌아감 (백트레킹) 
    if(pickCount == height*width){
        return;
    }
    // 중복된 건 확인하는거 방지 위해 y & x 시작점 정해줌 
    for(int i=y;i<height;i++){
        for(int j=x;j<width;j++){
            // 아직 방문 안했고, 보드가 비어있으며 해당위치에 넴모를 넣었을때 2x2가 안될때 넣음 
            if(!visited[i][j] && board[i][j] == 0 && checks(i,j)==false){
                visited[i][j] = true;
                board[i][j] = 1; 
                ans++;  // 배치 가짓수 ++ 
                makeComb(pickCount+1,i,j);
                visited[i][j] = false;
                board[i][j] = 0; 
            }
        }
        x=0;
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width;
    memset(board,0,sizeof(board));
    memset(visited,false,sizeof(visited));
    makeComb(0,0,0);
    cout<<ans+1;
}