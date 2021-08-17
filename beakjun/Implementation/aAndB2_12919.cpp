/*
    작성자: 김지수
    작성일: 2021/08/18
    백준 -- A와 B 2(12919번)
    문제:
    - 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임을 만듬
    - 2가지 연산만 가능:
        1) 문자열의 뒤에 A 추가
        2) 문자열의 뒤에 B를 추가 & 문자열을 뒤집는다
    - S를 T로 바꿀 수 있으면 1을 없으면 0을 출력한다.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// note - substr쓰면 시간초과된다!!!
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string originalStr, finalStr;
   cin >> originalStr >> finalStr;

   queue<string> q;
   q.push(finalStr);
   while (!q.empty()) {
      string temp1 = q.front();
      string temp2 = q.front();
      if (temp1 == originalStr) {
         cout << 1;
         return 0;
      }
      if (temp1[temp1.length() - 1] == 'A') {
         temp1.erase(temp1.length() - 1, 1);
         q.push(temp1);
      }
      if (temp2[0] == 'B') {
         temp2.erase(0, 1);
         reverse(temp2.begin(), temp2.end());
         q.push(temp2);
      }
      q.pop();
   }
   cout << 0;
}