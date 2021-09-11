/*
    작성자: 김지수
    작성일: 2021/09/11
    백준 -- 회사에 있는 사람 (7785번)
    문제:
    - 출퇴근 로그 보고 회사에 지금 있는 사람 역순으로 출력
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int num;
   cin >> num;
   set<string> ans;
   for (int i = 0; i < num; i++) {
      string name, valid;
      cin >> name >> valid;
      if (valid == "enter") {
         ans.insert(name);
      } else {
         ans.erase(name);
      }
   }
   for (auto iter = ans.rbegin(); iter != ans.rend(); iter++) {
      cout << *iter << "\n";
   }
}
