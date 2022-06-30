/*
    작성자: 김지수
    작성일: 2022/06/30
    백준 -- 2xn 타일링 (11726번)
*/

#include <iostream>
#include <cstring>
#define MAX 1001
#define MOD 10007
using namespace std;

int cache[MAX];

int tiling(int n){
    int &ret = cache[n];
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }

    if(ret!=-1){
        return ret; 
    }else{
        return ret = (tiling(n-1)%MOD+tiling(n-2)%MOD)%MOD;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(cache,-1,sizeof(cache));
    int n; 
    cin>>n;

    cout<<tiling(n);

}