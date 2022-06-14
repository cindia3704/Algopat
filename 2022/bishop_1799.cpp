/*
    작성자: 김지수
    작성일: 2022/06/15
    백준 -- 비숍 (1799번)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 11
using namespace std;

int boardSize;
// 시간 복잡도 반으로 줄이기 위해서 검은색 & 흰색 칸 나눠서 탐색 
bool diagRUp[2][MAX*2];        // x+y
bool diagRDown[2][MAX*2];       // y-x+n-1
vector<pair<int,int> > pos[2];  // black & white 

int ans[2];

void makeComb(int countBishop,int idx,int color){
    if(idx >= pos[color].size()){
        ans[color] = max(countBishop,ans[color]);
        return;
    }
    int nowY = pos[color][idx].first;
    int nowX = pos[color][idx].second;
    // 대각선에 놓아도 이미 선택한 다른 애들한테 안잡아먹힐때 
    if(diagRUp[color][nowY+nowX]==false && diagRDown[color][nowY-nowX+boardSize-1] == false){        
        diagRUp[color][nowY+nowX]=diagRDown[color][nowY-nowX+boardSize-1]=true;
        makeComb(countBishop+1,idx+1,color);
        diagRUp[color][nowY+nowX]=diagRDown[color][nowY-nowX+boardSize-1]=false;
    }
    //현재 칸 선택 안하고 다음 칸 고려 
    makeComb(countBishop,idx+1,color);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>boardSize;
    for(int i=0;i<2;i++){
        fill(diagRUp[i],diagRUp[i]+2*MAX,false);
        fill(diagRDown[i],diagRDown[i]+2*MAX,false);
    }

    int num;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>num;
            if(num == 1){
                // 흰/검에 따라 추가 
                pos[(i+j+1)%2].push_back(make_pair(i,j));
            }
        }
    }

    makeComb(0,0,0);
    makeComb(0,0,1);

    cout<<ans[0]+ans[1];
}