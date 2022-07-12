/*
    작성자: 김지수
    작성일: 2022/07/12
    백준 -- 감시 (15683번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 9
using namespace std;

vector<pair<int,int> > cctv; 
const int dirs[5]={4,2,4,4,1};
int height,width;
int ans =64;
int board[MAX][MAX];

int findSafeArea(){
    int areaCount=0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==0){
                areaCount++;
            }
        }
    }
    return areaCount;
}

void fillUp(int dir,int y,int x){
    dir = dir%4;
    if(dir == 0){ // 오른쪽
        while(true){
            x++;
            if(x>=width){
                break;
            }
            if(board[y][x] == 6){
                break;
            }
            if(board[y][x] == 0){
                board[y][x] = 7;
            }
        }
    }
    else if(dir == 2){ // 왼쪽
        while(true){
            x--;
            if(x<0){
                break;
            }
            if(board[y][x] == 6){
                break;
            }
            if(board[y][x] == 0){
                board[y][x] = 7;
            }
        }
    }
    else if(dir == 3){ // 위
        while(true){
            y--;
            if(y<0){
                break;
            }
            if(board[y][x] == 6){
                break;
            }
            if(board[y][x] == 0){
                board[y][x] = 7;
            }
        }
    }
    else if(dir == 1){ // 아래
        while(true){
            y++;
            if(y>=height){
                break;
            }
            if(board[y][x] == 6){
                break;
            }
            if(board[y][x] == 0){
                board[y][x] = 7;
            }
        }
    }
}


void makeComb(int pickCount){
    if(pickCount == cctv.size()){
        int temp = findSafeArea();
        ans = min(ans,temp);
        return;
    }
    int temp[MAX][MAX];
    for(int r=0;r<MAX;r++){
        for(int k=0;k<MAX;k++){
            temp[r][k] = board[r][k];
        }
    }

    pair<int,int> pos = cctv[pickCount];
    int cctvNum = board[pos.first][pos.second];
    for(int j=0;j<dirs[cctvNum-1];j++){
        if(cctvNum == 1){
            fillUp(j,pos.first,pos.second);
        }else if(cctvNum==2){
            fillUp(j,pos.first,pos.second);
            fillUp(j+2,pos.first,pos.second);
        }
        else if(cctvNum==3){
            fillUp(j,pos.first,pos.second);
            fillUp(j+3,pos.first,pos.second);
        }
        else if(cctvNum==4){
            fillUp(j,pos.first,pos.second);
            fillUp(j+3,pos.first,pos.second);
            fillUp(j+2,pos.first,pos.second);
        }
        else if(cctvNum==5){
            fillUp(j,pos.first,pos.second);
            fillUp(j+1,pos.first,pos.second);
            fillUp(j+3,pos.first,pos.second);
            fillUp(j+2,pos.first,pos.second);
        }

        makeComb(pickCount+1);

        for(int k=0;k<MAX;k++){
            for(int r=0;r<MAX;r++){
                board[k][r] = temp[k][r];
            }
        }
            
    }
    

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
            if(board[i][j]!=0 && board[i][j]!=6){
                cctv.push_back(make_pair(i,j));
            }
        }
    }

    makeComb(0);
    cout<<ans;
}