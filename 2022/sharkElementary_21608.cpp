/*
    작성자: 김지수
    작성일: 2022/07/27
    백준 -- 상어초등학교 (21608번)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 401
using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4]={1,0,-1,0};

struct BLOCK{
    int y,x;
    int bffNum;
    int blankNum;
};
vector<BLOCK> pos;
vector<int> bffList[MAX];
vector<int> turn;
int boardSize; 
int board[MAX][MAX];

void print(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkFriend(int a,int b){
    for(int i=0;i<bffList[a].size();i++){
        if(b==bffList[a][i]){
            return true;
        }
    }
    return false;
}

bool cmp(BLOCK & a, BLOCK &b){
    if(a.bffNum == b.bffNum){
        if(a.blankNum == b.blankNum){
            if(a.y==b.y){
                return a.x<b.x;
            }
            return a.y<b.y;
        }
        return a.blankNum>b.blankNum;
    }
    return a.bffNum>b.bffNum;
}

void findPossiblePos(int student){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]==0){
            BLOCK now;
            now.y=i;
            now.x=j;
            now.bffNum=0;
            now.blankNum=0;
            for(int dir = 0;dir<4;dir++){
                int nextY =i+dy[dir];
                int nextX=j+dx[dir];
                if(nextY<0||nextY>=boardSize || nextX<0 || nextX>=boardSize){
                    continue;
                }
                if(board[nextY][nextX]==0){
                    now.blankNum++;
                }else{
                    if(checkFriend(student,board[nextY][nextX])){
                        now.bffNum++;
                    }
                }
            
            }
            pos.push_back(now);
            }
        }
    }
    sort(pos.begin(),pos.end(),cmp);
}


int calcScore(){
    int sum=0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            int nowStudent = board[i][j];
            int bffCnt=0;
            for(int k=0;k<4;k++){
                int nextY=i+dy[k];
                int nextX = j+dx[k];
                if(nextY<0 || nextY>=boardSize || nextX<0 || nextX>=boardSize){
                    continue;
                }
                bool isfriend = checkFriend(nowStudent,board[nextY][nextX]);
                if(isfriend){
                    bffCnt++;
                }
            }
            if(bffCnt == 1){
                sum+=1;
            }else if(bffCnt == 2){
                sum+=10;
            }else if(bffCnt == 3){
                sum+=100;
            }else if(bffCnt == 4){
                sum+=1000;
            }
        }
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize;
    for(int i=0;i<boardSize*boardSize;i++){
        int studentNum;
        cin>>studentNum;
        for(int i=0;i<4;i++){
            int friendNum;
            cin>>friendNum;
            bffList[studentNum].push_back(friendNum);
        }
        turn.push_back(studentNum);
    }
    for(int i=0;i<turn.size();i++){
        pos.clear();
        int nowStudent = turn[i];
        findPossiblePos(nowStudent);
        board[pos[0].y][pos[0].x] = nowStudent;
    }
    cout<<calcScore();
}