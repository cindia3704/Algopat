/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 약수의 합 (17425번)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000
using namespace std; 
long long cache[MAX+1];
long long sum[MAX+1];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(cache,cache+MAX+1,1);

    // 배수면 약수 더해줌 
    for(int i=2;i<=MAX;i++){
        for(int j=1;i*j<=MAX;j++){
            cache[i*j]+=i;
        }
    }

    // 누적합 
    sum[1] = cache[1];
    for(int i=2;i<=MAX;i++){
        sum[i]=cache[i]+sum[i-1];
    }

    int TC;
    cin>>TC;
    for(int i=0;i<TC;i++){
        int num;
        cin>>num;

        cout<<sum[num]<<'\n';
    }

}