/*
    작성자: 김지수
    작성일: 2022/07/27
    백준 -- 미세먼지 안녕! (17144번)
*/

#include <iostream>
#include <cstring> 
#include <vector> 
#include <algorithm>
#include <math.h>
#define MAX 51
using namespace std; 

const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};

int height,width,targetTime; 
int board[MAX][MAX];
vector<pair<int,int> > cleanerPos;


void spreadDust(){
    int temp[MAX][MAX];
    memset(temp,0,sizeof(temp)); 

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]>0){
                // 퍼질 미세먼지 = 현위치 미세먼지 / 5 (나머지 버리기)
                int spreadAmount = floor(board[i][j]/5);
                int count = 0; // 인접한 공간 몇개로 퍼졌는지 세기 
                for(int dir=0;dir<4;dir++){
                    int nextY = i+dy[dir];
                    int nextX = j+dx[dir];

                    if(nextY<0 || nextY>=height|| nextX<0 || nextX>=width){
                        continue;
                    }else if(board[nextY][nextX]==-1){
                        continue;
                    }
                    else{
                        count++;
                        temp[nextY][nextX]+=spreadAmount;
                    }
                }
                //(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
                temp[i][j] += board[i][j]-(count*spreadAmount);
            }
        }
    }

    // 미세먼지 퍼진결과 복사 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = temp[i][j];
        }
    }
}

void moveCleaner(){
    int temp[MAX][MAX];
    memset(temp,0,sizeof(temp));

    int cleanerY1 = cleanerPos[0].first;
    int cleanerX1 = cleanerPos[0].second;
    int cleanerY2 = cleanerPos[1].first;
    int cleanerX2 = cleanerPos[1].second;

    // #1 & #2 => 
    for(int i=1;i<width-1;i++){
        temp[cleanerY1][i+1] = board[cleanerY1][i];
        temp[cleanerY2][i+1] = board[cleanerY2][i];
    } 

    // #1 위로 
    for(int i=cleanerY1;i>0;i--){
        temp[i-1][width-1] = board[i][width-1];
    }

    // #2 아래로
    for(int i=cleanerY2;i<height-1;i++){
        temp[i+1][width-1] = board[i][width-1]; 
    }

    //#1 & #2 <=
    for(int i=width-1;i>0;i--){
        temp[0][i-1] = board[0][i];
        temp[height-1][i-1] = board[height-1][i];
    }

    //#1 아래로
    for(int i=0;i<cleanerY1;i++){
        temp[i+1][0] = board[i][0]; 
    }

    //#2 위로 
    for(int i=height-1;i>cleanerY2;i--){
        temp[i-1][0] = board[i][0];
    }

    // 공기청정기 #1 & #2 사이에 있는 값들은 board랑 같게 세팅 
    for(int i=1;i<cleanerY1;i++){
        for(int j=1;j<width-1;j++){
            temp[i][j] = board[i][j];
        }
    }
    for(int i=cleanerY2+1;i<height-1;i++){
        for(int j=1;j<width-1;j++){
            temp[i][j] = board[i][j];
        }
    }

    // 공기청정기 돌린 결과 복사 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = temp[i][j];
        }
    }

    // 공기청정기 위치는 -1로 세팅 
    board[cleanerY1][cleanerX1] = -1;
    board[cleanerY2][cleanerX2] = -1;
    return;
}

int totalDust(){
    int dustSum=0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            dustSum+=board[i][j];
        }
    }
    return dustSum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    cin>>height>>width>>targetTime;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
            if(board[i][j]==-1){
                cleanerPos.push_back(make_pair(i,j));
            }
        }
    }   
    // 위에 있는게 cleanerPos[0]이 되게 정렬 
    sort(cleanerPos.begin(),cleanerPos.end());

    // 주어진 시간만큼 돌리기 
    while(targetTime--){
        // 미세먼지 퍼트리기 
        spreadDust();
        // 공기청정기 돌리기 
        moveCleaner();
    }
    // 공기청정기 자리= -1 이고, 2개 있기 때문에 +2 
    cout<<totalDust()+2;

}