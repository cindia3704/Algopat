/*
    작성자: 김지수
    작성일: 2021/09/04
    백준 -- 균형잡힌 세상(4949번)
    문제:
    - 여러줄에 걸쳐서 문자열이 주어질때 괄호의 짝이 맞는지 확인하자
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
vector<string> ans;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   while (true) {
      string line;
      getline(cin, line);
      if (line == ".") {
         break;
      }
      stack<char> s;
      bool found = false;
      for (int i = 0; i < line.length(); i++) {
         if (line[i] == '(' || line[i] == '[') {
            s.push(line[i]);
         } else if (line[i] == ')') {
            if (s.empty()) {
               found = true;
               break;
            } else {
               if (s.top() != '(') {
                  found = true;
                  break;
               } else {
                  s.pop();
               }
            }

         } else if (line[i] == ']') {
            if (s.empty()) {
               found = true;
               break;
            } else {
               if (s.top() != '[') {
                  found = true;
                  break;
               } else {
                  s.pop();
               }
            }
         } else
            continue;
      }
      if (s.empty() && found == false) {
         ans.push_back("yes");
      } else {
         ans.push_back("no");
      }
   }
   for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << endl;
   }
}