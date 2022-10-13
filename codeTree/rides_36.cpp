/*
    작성자: 김지수
    작성일: 2022/10/13
    코드트리 -- 놀이기구 탑승 (36번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

struct BLOCK{
    int y,x;
    int bffCnt;
    int empCnt;
};

int boardSize;
int board[MAX][MAX];
vector<int> bff[MAX*MAX];

bool cmp(BLOCK &a, BLOCK &b){
    if(a.bffCnt == b.bffCnt){
        if(a.empCnt == b.empCnt){
            if(a.y==b.y){
                return a.x<b.x;
            }
            return a.y<b.y;
        }
        return a.empCnt>b.empCnt;
    }
    return a.bffCnt>b.bffCnt;
}

bool OOB(int y,int x){
    return (y<0 || y>=boardSize || x<0 || x>=boardSize);
}

bool isBFF(int stud,int fri){
    for(int i=0;i<4;i++){
        if(fri == bff[stud][i]){
            return true;
        }
    }
    return false;
}

pair<int,int> findPos(int studNum){
    vector <BLOCK> posList; 
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j] == 0 ){
                BLOCK b;
                b.y= i;
                b.x =j;
                b.empCnt = 0;
                b.bffCnt = 0;
                for(int k=0;k<4;k++){
                    int nextY = i+dy[k];
                    int nextX = j+dx[k];
                    if(OOB(nextY,nextX)){
                        continue;
                    }
                    if(board[nextY][nextX]==0){
                        b.empCnt++;
                    }else{
                        if(isBFF(studNum,board[nextY][nextX])){
                            b.bffCnt++;
                        }
                    }
                }
                posList.push_back(b);
            }
        }
    }
    sort(posList.begin(),posList.end(),cmp);
    return make_pair(posList[0].y,posList[0].x);
}

int calcScore(){
    int sum=0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            int now = board[i][j];
            int cntBFF = 0;
            for(int k=0;k<4;k++){
                int nextY = i+dy[k];
                int nextX = j+dx[k];
                if(OOB(nextY,nextX)){
                    continue;
                }
                if(isBFF(board[i][j],board[nextY][nextX])){
                    cntBFF++;
                }
            }
            if(cntBFF==1){
                sum+=1;
            }else if(cntBFF==2){
                sum+=10;
            }else if(cntBFF==3){
                sum+=100;
            }else if(cntBFF==4){
                sum+=1000;
            }
        }
    }
    return sum;
}

void print(){
    cout<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>boardSize;
    for(int i=1;i<=boardSize*boardSize;i++){
        int studentNum;
        cin>>studentNum;
        for(int j=0;j<4;j++){
            int num;
            cin>>num;
            bff[studentNum].push_back(num);
        }
        pair<int,int> nowPos = findPos(studentNum);
        board[nowPos.first][nowPos.second] = studentNum;
    }
    
    cout<<calcScore();
}