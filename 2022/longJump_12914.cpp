/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- 멀리 뛰기 (12914번)
*/
#include <string>
#include <vector>
#include <cstring>
#define MAX 2001
#define MOD 1234567

using namespace std;
long long cache[MAX];
long long dp(int n){
    long long &ret = cache[n];
    if(n==0){
        return 1;
    }else if(n<0){
        return 0;
    }
    if(ret!=-1){
        return ret;
    }else{
        int temp = 0;
        temp=(dp(n-1)%MOD)+(dp(n-2)%MOD);
        ret = temp%MOD;
    }
    return ret; 
}

long long solution(int n) {
    long long answer = 0;
    memset(cache,-1,sizeof(cache));
    answer = dp(n)%MOD;
    return answer;
}