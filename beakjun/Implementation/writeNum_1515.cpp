/*
    작성자: 김지수
    작성일: 2021/10/06
    백준 -- 수 이어쓰기 (1515번)
    문제:
*/

#include <iostream>
#include <string>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   cin >> s;
   int idx = 0;
   int num = 1;
   while (idx < s.length()) {
      string temp = to_string(num);
      bool found = false;
      for (int i = 0; i < temp.size(); i++) {
         if (s[idx] == temp[i]) {
            found = true;
         }
         if (found) {
            idx++;
            found = false;
         }
      }
      if (found) {
         idx++;
      }

      num++;
   }
   cout << num - 1;
}