/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 소수 찾기 (1978번)
*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){
    if(num<=1){
        return false;
    }else{
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                return false;
            }else{
                continue;
            }
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; 
    cin>>tc; 
    int cnt = 0;
    for(int i=0;i<tc;i++){
        int num; 
        cin>>num;
        if(isPrime(num)){
            cnt++;
        }
    }
    cout<<cnt; 
}