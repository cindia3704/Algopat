/*
    작성자: 김지수
    작성일: 2022/06/29
    백준 -- 계단 오르기 (2579번)
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 301
using namespace std; 

vector<int> stairs; 
int cache[MAX];

int climbStairs(int n){
    int& ret = cache[n]; 
    if(n==0){
        return stairs[0];
    }
    if(n<0){
        return 0;
    }
    if(ret!=-1){
        return ret; 
    }else{
        // 1칸전꺼 밟으면 그다음껀 밟으면 안됨 
        int temp1 = stairs[n]+stairs[n-1]+climbStairs(n-3);
        // 2칸 전꺼 밟으면 다음부터는 1칸전 / 2칸전 밟을 수 있음 
        int temp2 = stairs[n]+climbStairs(n-2);
        ret = max(temp1,temp2);
    }
    return ret; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num; 
        cin>>num;
        stairs.push_back(num);
    }
    memset(cache,-1,sizeof(cache));
    cout<<climbStairs(n-1);
}