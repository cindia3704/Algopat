/*
    작성자: 김지수
    작성일: 2022/08/02
    백준 -- 이항 계수 2 (11438번)
*/
#include <iostream>
#include <cstring>
#define MAX 1000
#define MOD 10007
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n,k;
    cin>>n>>k;
    long long cache[n+1][k+1];
    for(int i=0;i<=n;i++){
        cache[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i==j){
                cache[i][j] = 1;
            }else{
                cache[i][j] = ((cache[i-1][j-1]%MOD)+(cache[i-1][j]%MOD))%MOD;   
            }
        }
    }
    cout<<cache[n][k];
}