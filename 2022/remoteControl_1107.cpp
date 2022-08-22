/*
    작성자: 김지수
    작성일: 2022/08/22
    백준 -- 리모컨 (1107번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 7
using namespace std; 

int ans = 0x7fffffff;
bool aliveNum[10];
int numLength;
int realNum;
int pick[MAX];

void makeComb(int pickCount,int target){
    if(pickCount == target){
        int madeNum = 0;
        for(int i=0;i<pickCount;i++){
            madeNum+=pow(10,i)*pick[pickCount-i-1];
        }
        
        int numDiff = abs(realNum-madeNum);
        ans = min(ans,numDiff+pickCount);
        return;
    }
    for(int i=0;i<=9;i++){
        if(aliveNum[i]){
            pick[pickCount] = i;
            makeComb(pickCount+1,target);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    memset(aliveNum,true,sizeof(aliveNum));

    // 시작은 100번에서 
    int now = 100;
    cin>>realNum;

    string temp = to_string(realNum);
    // 시작에서 + / - 로 움직일때 누르는 횟수 
    ans = min(ans,abs(now-realNum));
    numLength = temp.length();


    int eraseCnt;
    cin>>eraseCnt;

    for(int i=0;i<eraseCnt;i++){
        int eraseNum;
        cin>>eraseNum;
        aliveNum[eraseNum] = false;
    }

    // 모든 번호 지우면 볼  필요 없음 
    if(eraseCnt!=10){
        // 이전 자리수로 만들기 
        if(numLength-1 >0){
            makeComb(0,numLength-1);
        }
        // 현재 자리수로 만들기 
        makeComb(0,numLength);

        // 다음자리수중 가장 작은거 만들면 됨 
        int idx=numLength;
        int nextLargest = 0;
        bool foundNext = true;
        
        while(idx>=0){
            bool found = false;
            for(int i=0;i<=9;i++){
                if(aliveNum[i]){
                    if(idx==numLength && i==0){
                        continue;
                    }else{
                        nextLargest+=pow(10,idx)*i;
                        found = true;
                        break;
                    
                    }
                }
            }

            if(!found){
                foundNext = false; 
                break;
            }
            idx--;
        }

        if(foundNext){
            ans = min(ans,abs(nextLargest-realNum+numLength+1));
        }
    }
    
    cout<<ans;
}