/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 약수의 합 2 (17427번)
*/

#include <iostream>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    long long ans =0;
    for(int i=1;i<=n;i++){
        long long temp = (n/i)*i;
        ans+=temp;
    }
    cout<<ans;
}