/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- 짝지어 제거하기 (12973번)
*/

#include <iostream>
#include<string>
#include <cstring>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }else{
            char now = s[i];
            char prev = st.top();
            if(now==prev){
                st.pop();
            }else{
                st.push(now);
            }
        }
    }
    if(st.size()==0){
        answer = 1;
    }
    return answer;
}