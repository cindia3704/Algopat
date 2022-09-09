/*
    작성자: 김지수
    작성일: 2022/09/09
    프로그래머스 -- 올바른 괄호 (12909번)
*/

#include<string>
#include <iostream>
#include <stack>

using namespace std;
stack<int> st;
bool solution(string s)
{
    bool answer = true;
    int idx = 0;
    while(idx <s.length()){
        if(s[idx]=='('){
            st.push(1);
        }else{
            if(st.empty()){
                answer = false;
                break;
            }else{
                st.pop();
            }
        }
        idx++;
    }
    if(!st.empty()){
        answer=false;
    }

    return answer;
}