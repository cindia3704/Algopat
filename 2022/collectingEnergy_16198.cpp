/*
    작성자: 김지수
    작성일: 2022/07/11
    백준 -- 에너지 모으기 (16198번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 11
using namespace std;

int ans =0;
int totalMarble;
bool used[MAX];
int marbles[MAX];

void makeComb(int pickCount,int sum){
    if(pickCount == totalMarble-2){
        ans = max(ans,sum);
        return;
    }else{
        //에너지 구슬 하나를 고른다. 고른 에너지 구슬의 번호를 x라고 한다. 단, 첫 번째와 마지막 에너지 구슬은 고를 수 없다.
        for(int i=1;i<totalMarble-1;i++){
            if(!used[i]){
                used[i] = true;
                //Wx-1 × Wx+1의 에너지 (하지만 이미 고른애들은 구슬리스트에서 제거해야함 -> 배열 제거 오래걸리니까 다음으로 살아있는 이전, 이후 구술 구함)
                int bf=i;
                int af=i; 
                while(i>=0){
                    if(!used[bf]){
                        break;
                    }else{
                        bf--;
                    }
                }
                 while(i<totalMarble){
                    if(!used[af]){
                        break;
                    }else{
                        af++;
                    }
                }
                int subSum=marbles[bf]*marbles[af];
                makeComb(pickCount+1,subSum+sum);
                used[i] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>totalMarble;
    for(int i=0;i<totalMarble;i++){
        cin>>marbles[i];
    }
    makeComb(0,0);
    cout<<ans;
}