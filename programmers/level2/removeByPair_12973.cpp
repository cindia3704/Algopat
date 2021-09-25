/*
    작성자: 김지수
    작성일: 2021/09/26
    programmers -- 짝지어 제거하기 (12973번)
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solution(string s) {
   int answer = -1;
   stack<char> temp;
   for (int i = 0; i < s.length(); i++) {
      if (temp.empty()) {
         temp.push(s[i]);
      } else {
         if (temp.top() == s[i]) {
            temp.pop();
         } else {
            temp.push(s[i]);
         }
      }
   }
   if (temp.size() > 0) {
      answer = 0;
   } else {
      answer = 1;
   }

   return answer;
}