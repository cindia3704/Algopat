/*
    작성자: 김지수
    작성일: 2022/06/23
    백준 -- 숫자 카드 (10815번)
*/

#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    vector<long long> arrN;
    cin>>n;
    for(int i=0;i<n;i++){
        long long num;
        cin>>num;
        arrN.push_back(num);
    }
    sort(arrN.begin(),arrN.end());

    cin>>m;
    while(m--){
        long long target; 
        cin>>target; 
        cout<<binary_search(arrN.begin(),arrN.end(),target)<<" ";
    }

}