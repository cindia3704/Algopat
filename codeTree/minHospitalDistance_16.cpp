/*
    작성자: 김지수
    작성일: 2022/10/13
    코드트리 -- 병원 거리 최소화하기 (16번)
*/

#include <iostream>
#include <queue> 
#include <algorithm>
#include <vector>
#define MAX 51 
#define MAX_H 14
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int boardSize,hospitalCnt;
vector<pair<int,int> > hospitalList;
vector<pair<int,int> > peopleList; 
bool used[MAX_H];
pair<int,int> pick[MAX_H];
int ans = 0x7fffffff;


void calc2(){
    int sum = 0;
    for(int i=0;i<peopleList.size();i++){
        pair<int,int> nowPos = peopleList[i];
        int minDis = 0x7fffffff;
        for(int j=0;j<hospitalCnt;j++){
            pair<int,int> hos = pick[j];
            int tempDist = abs(nowPos.first - hos.first)+abs(nowPos.second-hos.second);
            minDis = min(minDis,tempDist);
        }
        sum+=minDis;
    }
    ans = min(ans,sum);
}

void makeComb(int pickCount, int start){
    if(pickCount == hospitalCnt){
        calc2();
        return;
    }
    for(int i=start;i<hospitalList.size();i++){
        if(!used[i]){
            used[i] = true;
            pick[pickCount]= hospitalList[i];
            makeComb(pickCount+1,i);
            used[i] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin>>boardSize>>hospitalCnt;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            int num;
            cin>>num;
            if(num == 2){
                hospitalList.push_back(make_pair(i,j));
            }else if(num == 1){
                peopleList.push_back(make_pair(i,j));
            }
        }
    } 
    fill(used,used+MAX_H,false);
    makeComb(0,0);
    cout<<ans;
}