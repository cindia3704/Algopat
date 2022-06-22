/*
    작성자: 김지수
    작성일: 2022/06/23
    백준 -- 세 수의 합 (2295번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<long long> original;
    vector<long long> sums;
    int numCount;
    cin>>numCount;
    for(int i=0;i<numCount;i++){
        long long num;
        cin>>num;
        original.push_back(num);
    } 
    sort(original.begin(),original.end());

    for(int i=0;i<numCount;i++){
        for(int j=0;j<numCount;j++){
            long long a = original[i];
            long long b = original[j];
            long long sum = a+b; 
            sums.push_back(sum);
        }
    }
    sort(sums.begin(),sums.end());

    long long ans =0;
    for(int i=0;i<numCount-1;i++){
        for(int j=i+1;j<numCount;j++){
            long long minus = original[i];
            long long result = original[j];
            long long target = result-minus;
            if(binary_search(sums.begin(),sums.end(),target)){
                if(ans<result){
                    ans = result;
                }
            }
        }
    }
    cout<<ans;

}