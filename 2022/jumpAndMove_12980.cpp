/*
    작성자: 김지수
    작성일: 2022/09/23
    백준 -- 점프와 순간 이동 (12980번)
*/

#include <iostream>
#include <cstring> 
#include <deque>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(true){
        if(n==1){
            break;
        }
        if(n%2!=0){
            n--;
            ans++;
        }else{
            n/=2;
        }
    }
    ans+=(n);


    return ans;
}