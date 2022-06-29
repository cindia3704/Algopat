/*
    작성자: 김지수
    작성일: 2022/06/29
    백준 -- 스타트와 링크 (14889번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 21
using namespace std; 

int strength[MAX][MAX];
int pickTeam1[MAX];
int pickTeam2[MAX];
bool picked[MAX];
int n;

int ans = 0x7fffffff;

void makeComb(int pickCount, int teamCount,int start){
    if(pickCount == teamCount){
        int idx = 0;
        for(int i=0;i<n;i++){
            bool found = false;
            for(int j=0;j<pickCount;j++){
                if(pickTeam1[j] == i){
                    found = true;
                    break;
                }
            }
            if(!found){
                pickTeam2[idx] = i;
                idx++;
            }
        }

        int team1Sum = 0;
        int team2Sum = 0;
        for(int i=0;i<pickCount;i++){
            for(int j=0;j<pickCount;j++){
                team1Sum += strength[pickTeam1[i]][pickTeam1[j]];
                team2Sum += strength[pickTeam2[i]][pickTeam2[j]];
            }
        }
        int diff = abs(team1Sum-team2Sum);
        if(ans>diff){
            ans = diff;
        }
        return;
    }else{
        for(int i=start;i<n;i++){
            if(!picked[i]){
                picked[i] = true;
                pickTeam1[pickCount] = i;
                makeComb(pickCount+1,teamCount,i+1);
                picked[i] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>strength[i][j];
        }
    }

    memset(picked,false,sizeof(picked));
    makeComb(0,n/2,0);
    cout<<ans;
}
