/*
    작성자: 김지수
    작성일: 2022/06/29
    백준 -- 1,2,3 더하기 (9095번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 

int cache[12];

int addition(int n){
    int & ret = cache[n];
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1; 
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4; 
    }
    if(ret!=-1){
        return ret; 
    }else{
        ret = addition(n-1)+addition(n-2)+addition(n-3);
    }
    return ret; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(cache,-1,sizeof(cache));
    int tc; 
    cin>>tc;

    while(tc--){
        int n;
        cin>>n; 
        cout<<addition(n)<<'\n';
    }
}