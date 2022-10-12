/*
    작성자: 김지수
    작성일: 2022/10/12
    백준 -- 감시 (15683번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std; 
vector<pair<int,int> > cctvs; 

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};

const int turns[5]={4,2,4,4,1};
int height,width;
int board[MAX][MAX];
int temp[MAX][MAX];
int pick[MAX*MAX];
int ans = 0x7fffffff;

void print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(temp[i][j]==-1){
                cout<<"7 ";
            }else{
                cout<<temp[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

bool OOB(int y,int x){
    return (y<0 || y>=height||x<0 || x>=width);
}

int countSafeZone(){
    int ret = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(temp[i][j] ==0){
                ret++;
            }
        }
    }
    return ret;
}


void copyToTemp(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            temp[i][j] = board[i][j];
        }
    }
}

void fillBoard(int y,int x,int dir){
    int ny = y;
    int nx = x;
    while(true){
        int nextY = ny+dy[dir];
        int nextX = nx+dx[dir];
        if(OOB(nextY,nextX)){
            break;
        }else{
            if(temp[nextY][nextX]==6){
                break;
            }else{
                if(temp[nextY][nextX]==0){
                    temp[nextY][nextX] = -1;
                }
                ny = nextY;
                nx = nextX;
            }
        }
    }
}

void turnCCTV1(pair<int,int > now, int turnCnt){
    fillBoard(now.first,now.second,turnCnt);
}
void turnCCTV2(pair<int,int > now, int turnCnt){
    fillBoard(now.first,now.second,turnCnt);
    fillBoard(now.first,now.second,(turnCnt+2)%4);
}
void turnCCTV3(pair<int,int > now, int turnCnt){
    fillBoard(now.first,now.second,turnCnt);
    fillBoard(now.first,now.second,(turnCnt+1)%4);
}
void turnCCTV4(pair<int,int > now, int turnCnt){
    fillBoard(now.first,now.second,turnCnt);
    fillBoard(now.first,now.second,(turnCnt+1)%4);
    fillBoard(now.first,now.second,(turnCnt+2)%4);
}
void turnCCTV5(pair<int,int > now, int turnCnt){
    fillBoard(now.first,now.second,turnCnt);
    fillBoard(now.first,now.second,(turnCnt+1)%4);
    fillBoard(now.first,now.second,(turnCnt+2)%4);
    fillBoard(now.first,now.second,(turnCnt+3)%4);
}

void calc(int pickCount){
    copyToTemp();
    for(int i=0;i<pickCount;i++){
        int turnCnt = pick[i];
        pair<int,int> now= cctvs[i];
        int cctvNum = board[now.first][now.second];
        if(cctvNum ==1){
            turnCCTV1(now,turnCnt);
        }else if(cctvNum ==2){
            turnCCTV2(now,turnCnt);
        }else if(cctvNum ==3){
            turnCCTV3(now,turnCnt);
        }else if(cctvNum ==4){
            turnCCTV4(now,turnCnt);
        }else if(cctvNum ==5){
            turnCCTV5(now,turnCnt);
        }
    }
    int tempAns = countSafeZone();
    ans = min(ans,tempAns);
}

void makeComb(int pickCount){
    if(pickCount == cctvs.size()){
        calc(pickCount);
        return;
    }
    int cctvNum = board[cctvs[pickCount].first][cctvs[pickCount].second];
    int maxTurns = turns[cctvNum-1];
    for(int i=0;i<maxTurns;i++){
        pick[pickCount] = i;
        makeComb(pickCount+1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
            if(board[i][j]>0 && board[i][j]<6){
                cctvs.push_back(make_pair(i,j));
            }
        }
    }
    makeComb(0);
    cout<<ans;
}