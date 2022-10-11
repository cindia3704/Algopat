/*
    작성자: 김지수
    작성일: 2022/10/12
    백준 -- 지구 온난화 (5212번)
*/

#include <iostream>
#include <algorithm>
#define MAX 11 
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int height,width;
char board[MAX][MAX];
char temp[MAX][MAX];


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>height>>width;
    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            board[i][j] = l[j];
            temp[i][j] = l[j];
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j] == 'X'){
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int nextY = i+dy[k];
                    int nextX = j+dx[k];
                    if(nextY<0 || nextY>=height || nextX <0 || nextX >=width){
                        cnt++;
                        continue;
                    }
                    if(board[nextY][nextX]=='.'){
                        cnt++;
                    }
                }
                if(cnt>=3){
                    temp[i][j] = '.';
                }
            }
        }
    }
    int minH = 0x7fffffff;
    int maxH = 0;
    int minW = 0x7fffffff;
    int maxW = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(temp[i][j]=='X'){
                minH = min(minH,i);
                maxH = max(maxH,i);
                minW = min(minW,j);
                maxW = max(maxW,j);
            }
        }
    }
    for(int i=minH;i<=maxH;i++){
        for(int j=minW;j<=maxW;j++){
            cout<<temp[i][j];
        }
        cout<<'\n';
    }
}