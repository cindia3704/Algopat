/*
    작성자: 김지수
    작성일: 2022/08/19
    백준 -- 소수 구하기 (1929번)
*/

#include <iostream>
#include <cstring>
#define MAX 1000001
using namespace std; 

bool cache[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(cache,false,sizeof(cache)); 

    // 아직 지워지지 않은 수중 가장 작은 수의 배수들 모두 지우기 
    cache[1] =true; 
    for(int i=2;i<MAX;i++){
        if(!cache[i]){
            for(int j=2;j*i<MAX;j++){
                cache[i*j] = true;
            }
        }
    }

    int low,high; 
    cin>>low>>high;
    for(int i=low;i<=high;i++){
        if(!cache[i]){
            cout<<i<<"\n";
        }
    }
}