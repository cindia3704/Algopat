/*
    작성자: 김지수
    작성일: 2022/06/23
    백준 -- 차집합 (1822번)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    vector<long long> setA;
    vector<long long> setB;
    vector<long long> diff; 
    cin>>a>>b;
    for(int i=0;i<a;i++){
        long long num;
        cin>>num;
        setA.push_back(num);
    }
    for(int i=0;i<b;i++){
        long long num;
        cin>>num;
        setB.push_back(num);
    }
    sort(setB.begin(),setB.end());
    sort(setA.begin(),setA.end());

    for(int i=0;i<a;i++){
        if(!binary_search(setB.begin(),setB.end(),setA[i])){
            diff.push_back(setA[i]);
        }
    }

    cout<<diff.size()<<'\n';
    for(int i=0;i<diff.size();i++){
        cout<<diff[i]<<" ";
    }
}