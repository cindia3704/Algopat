/*
    작성자: 김지수
    작성일: 2022/08/01
    백준 -- 배열 돌리기 4 (17406번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#define MAX 51
using namespace std; 

struct Rotate{
    int y,x,s; 
};

int board[MAX][MAX];
int temp[MAX][MAX];
int height,width,rotateCnt; 
vector<Rotate> rotateList; 
int pickIdx[7];
bool usedRotate[7];
int ans = 0x7fffffff;

void rotate(int sy,int sx,int ey,int ex){
    int sY = sy;
    int sX = sx;
    int eY = ey;
    int eX=ex;
    int temp2[MAX][MAX];
    
   while(sy!=ey){
    // 윗줄 오른쪽으로 시프트 
    for(int i=sx;i<ex;i++){
        temp2[sy][i+1] = temp[sy][i];
    }
    // 오른쪽 줄 아래로 시프트 
    for(int i=sy;i<ey;i++){
        temp2[i+1][ex] = temp[i][ex];
    }
    // 바닥줄 왼쪽으로 시프트 
    for(int i=ex;i>sx;i--){
        temp2[ey][i-1] = temp[ey][i];
    }
    // 왼쪽줄 위로 시프트 
    for(int i=ey;i>sy;i--){
        temp2[i-1][sx] = temp[i][sx];
    }
    sy+=1;
    ey-=1;
    sx+=1;
    ex-=1; 
    // 범위 한칸씩 좁히기 
   }
   // 가운데 정보는 while문에서 안해주니 복사해줌 
   temp2[sy][sx] = temp[sy][sx];
   // 회전 연산한 정보를 temp에 복사 
   for(int i=sY;i<=eY;i++){
    for(int j=sX;j<=eX;j++){
        temp[i][j] = temp2[i][j];
    }
   }
}

int calcScore(){
    // 원본 유지 위해 연산 수행할 temp 배열에 원본정보 복사 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            temp[i][j] = board[i][j];
        }
    }

    // 회전 범위 구해서 rotate 함수 부르기 
    for(int i=0;i<rotateCnt;i++){
        Rotate now = rotateList[pickIdx[i]];
        int sy = now.y - now.s;
        int sx = now.x - now.s;
        int ey = now.y + now.s;
        int ex = now.x + now.s;
        rotate(sy,sx,ey,ex);
    }

    //배열 A의 값은 각 행에 있는 모든 수의 합 중 최솟값 구하기 
    int minSum = 0x7fffffff;
    for(int i=0;i<height;i++){
        int tempSum = 0;
        for(int j=0;j<width;j++){
            tempSum+=temp[i][j];
        }
        if(tempSum<minSum){
            minSum = tempSum;
        }
    }
    return minSum;
}

void makeComb(int pickCount){
    //회전 연산의 개수 만큼 뽑으면 뽑은 순서에 따라 회전 연산후 배열 점수 계산하기 
    if(pickCount == rotateCnt){
        int tempScore = calcScore();
        if(tempScore<ans){
            ans = tempScore;
        }
        return;
    }
    for(int i=0;i<rotateCnt;i++){
        if(!usedRotate[i]){
            usedRotate[i] = true;
            pickIdx[pickCount] = i;
            makeComb(pickCount+1);
            usedRotate[i] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>height>>width>>rotateCnt;
    // 보드 입력 받음 
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }
    // 회전 연산의 정보 받음 
    for(int i=0;i<rotateCnt;i++){
        Rotate r; 
        cin>>r.y>>r.x>>r.s;
        r.y--;
        r.x--;
        rotateList.push_back(r);
    }
    memset(usedRotate,false,sizeof(usedRotate));
    makeComb(0);
    cout<<ans;
}