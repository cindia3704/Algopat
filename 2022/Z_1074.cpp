/*
    작성자: 김지수
    작성일: 2022/07/12
    백준 -- Z (1074번)
*/

#include <iostream>
#include <cmath>
using namespace std; 

const int dx[3]={1,0,1};
const int dy[3]={0,1,1};

int func(int n,int y,int x){
    if(n==0){
        return 0;
    }
    int half = pow(2,n-1);
    if(y<half && x<half){
        return func(n-1,y,x);
    }
    if(y<half && x>=half){
        return half*half + func(n-1,y,x-half);
    }
    if(y>=half && x<half){
        return 2*half*half + func(n-1,y-half,x);
    }
    return 3*half*half + func(n-1,y-half,x-half);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int exponent,y,x;
    cin>>exponent>>y>>x;

    cout<<func(exponent,y,x);
}