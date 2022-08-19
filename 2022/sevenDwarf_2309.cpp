/*
    작성자: 김지수
    작성일: 2022/08/19
    백준 -- 일곱 난쟁이 (2309번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 
int numList[9];
int pick[7];
bool used[9];
bool found = false; 


void makeComb(int pickCount, int sum,int start){
    if(!found){
        if(pickCount == 7){
            if(sum==100){
                for(int i=0;i<7;i++){
                    cout<<pick[i]<<'\n';
                }
                found = true;
            }
            return;
        }
        for(int i=start;i<9;i++){
            if(!used[i]){
                used[i] = true;
                pick[pickCount] = numList[i];
                makeComb(pickCount+1,sum+numList[i],i);
                used[i] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    memset(used,false,sizeof(used));

    for(int i=0;i<9;i++){
        cin>>numList[i];
    }
    sort(numList,numList+9);
    makeComb(0,0,0);
    // for(int i=0;i<7;i++){
    //     cout<<pick[i]<<'\n';
    // }
}