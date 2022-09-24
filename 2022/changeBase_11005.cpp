/*
    작성자: 김지수
    작성일: 2022/09/24
    백준 -- 진법 변환 (11005번)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long ori;
    long long base;
    cin>>ori>>base; 
    string ret = "";

    while(ori>0){
        long long addNum = ori%base;
        if(addNum>=10){
            ret+=(addNum-10)+'A';
        }else{
            ret+=addNum+'0';
        }
        ori/=base;
        
    }
    
    reverse(ret.begin(),ret.end());
    cout<<ret;

}