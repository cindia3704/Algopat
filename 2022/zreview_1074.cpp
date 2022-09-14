/*
    작성자: 김지수
    작성일: 2022/09/15
    백준 -- Z (1074번)
*/

#include <iostream>
#include <queue>
#include <cmath>
using namespace std; 
struct Board{
    int sy,sx; 
    int bSize;
};

const int dx[4] = {0,1,0,1};
const int dy[4] = {0,0,1,1};
queue<Board> q;
int cnt=0;
int targetY,targetX;

int startGame(int n,int y,int x){
    if(n==1){
        for(int i=0;i<4;i++){
            if(y==dy[i] && x==dx[i]){
                return i;
            }
        }
    }
    int half = pow(2,n-1);
    if(y<half&&x<half){
        return startGame(n-1,y,x);
    }
    if(y<half && x>=half){
        return pow(2,n-1)*pow(2,n-1)+startGame(n-1,y,x-half);
    }
    else if(y>=half && x<half){
        return pow(2,n-1)*pow(2,n-1)*2+startGame(n-1,y-half,x);
    }else if(y>=half && x>=half){
        return pow(2,n-1)*pow(2,n-1)*3 + startGame(n-1,y-half,x-half);
    }

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin>>n;
    cin>>targetY>>targetX;
    cout<<startGame(n,targetY,targetX);

}