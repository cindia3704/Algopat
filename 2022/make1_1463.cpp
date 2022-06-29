/*
    작성자: 김지수
    작성일: 2022/06/29
    백준 -- 1로 만들기 (1463번)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000001
using namespace std;

int cache[MAX];

int makeOne(int n){
    int &ret = cache[n];
    if(n==1){
        return 0; 
    }
    if(ret!=-1){
        return ret; 
    }else{
        int temp1 = 0x7fffffff;
        if(n%3 == 0){
            temp1 = min(makeOne(n/3)+1,temp1);
        }
        if(n%2 ==0){
            temp1 = min(makeOne(n/2)+1,temp1); 
        }
        ret = min(makeOne(n-1)+1,temp1);
        return ret;
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(cache,-1,sizeof(cache));
    int n;
    cin>>n;
    cout<<makeOne(n);
}