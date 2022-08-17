/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 약수 (1037번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

vector<int> divisors;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int divCnt;
    cin>>divCnt;
    for(int i=0;i<divCnt;i++){
        int num;
        cin>>num;
        divisors.push_back(num);
    }
    sort(divisors.begin(),divisors.end());
    if(divCnt == 1){
        cout<<divisors[0]*divisors[0];
    }else{
        cout<<divisors[0]*divisors[divCnt-1];
    }

}