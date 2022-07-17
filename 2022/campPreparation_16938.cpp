/*
    작성자: 김지수
    작성일: 2022/07/17
    백준 -- 캠프 준비 (16938번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 15
#define ll long long
using namespace std; 
int totalProb;
ll leastDifficulty,maxDifficulty,difficultyDifference;
int difficulty[MAX];
int pick[MAX];
bool usedIdx[MAX];
int ans =0;

int calcValid(int tot){
    int maxNum=0;
    int leastNum = 0x7fffffff;
    ll sum = 0;
    // 모든 문제 합 구하면서, 가장 높은 난이도, 가장 낮은 난이도 찾음 
    for(int i=0;i<tot;i++){
        sum+=pick[i];
        if(pick[i]>maxNum){
            maxNum = pick[i];
        }
        if(pick[i]<leastNum){
            leastNum = pick[i];
        }

    }

    return sum>=leastDifficulty && sum<=maxDifficulty && (maxNum - leastNum>=difficultyDifference);
}

void makeComb(int pickCount, int targetCount,int start){
    // 문제를 현재 뽑으려는 개수만큼 뽑았으면 문제 뽑는 기준 통과했는지 확인 
    if(pickCount == targetCount){
        int temp =  calcValid(pickCount);
        ans +=temp;
        return;
    }
    if(start>=totalProb){
        return;
    }
    // 아직 안뽑은 문제면 문제 뽑음 
    for(int i=start;i<totalProb;i++){
        if(!usedIdx[i]){
            usedIdx[i] = true;
            pick[pickCount] = difficulty[i];
            
            makeComb(pickCount+1,targetCount,i+1);
            // 문제 안뽑음 처리 
            usedIdx[i] = false;
        }
    }
   
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>totalProb>>leastDifficulty>>maxDifficulty>>difficultyDifference;
    for(int i=0;i<totalProb;i++){
        cin>>difficulty[i];
    }
    // 문제는 최소 1개에서 최대 모든 문제를 뽑을 수 있음 
    for(int i=1;i<=totalProb;i++){
        memset(usedIdx,false,sizeof(usedIdx)); 
        makeComb(0,i,0);
    }
    cout<<ans;
}