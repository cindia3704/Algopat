/*
    작성자: 김지수
    작성일: 2022/07/20
    백준 -- 숫자 재배치 (16943번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string> 
using namespace std; 

string a;
int b;
int numUsed[10];
bool used[10];
int pick[10];
int ans =-1;

int makeNum(int n){
    int base = pow(10,n-1);
    int num = 0;
    for(int i=0;i<n;i++){
        num+=base*pick[i];
        base/=10;
    }
    if(num==0){
        return -1;
    }
    return num; 
}

void makeComb(int pickCount,int target){
    if(pickCount == target){
        int number = makeNum(pickCount);
        if(number < b && to_string(number).length() == target){
            ans = max(ans,number);
        }
        return; 
    }else{
        for(int i=target-1;i>=0;i--){
            if(!used[i]){
                pick[pickCount] = numUsed[i];
                used[i] = true;
                makeComb(pickCount+1,target);
                used[i] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>a>>b; 
    int numCount = a.length();

    for(int i=0;i<numCount;i++){
        numUsed[i] = a[i]-'0';
    }

    sort(numUsed,numUsed+numCount);
    memset(used,false,sizeof(used));

    makeComb(0,numCount);
    cout<<ans;

}