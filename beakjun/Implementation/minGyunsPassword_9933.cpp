/*
    작성자: 김지수
    작성일: 2021/10/12
    백준 -- 민균이의 비밀번호 (9933번)
    문제:
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int wordSize;
   cin >> wordSize;
   set<string> s;
   int answerLength = 0;
   char middle;
   for (int i = 0; i < wordSize; i++) {
      string input;
      cin >> input;
      s.insert(input);
      string temp = input;
      reverse(temp.begin(), temp.end());
      set<string>::iterator it2 = s.find(temp);
      if (it2 != s.end()) {
         answerLength = input.length();
         middle = input[answerLength / 2];
      }
   }
   cout << answerLength << " " << middle;
}