/*
    작성자: 김지수
    작성일: 2021/09/18
    백준 -- 진법 변환 2(11005번)
    문제:
    - 10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램
    - A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string changeBase(int number, int base) {
   string ans = "";
   while (number >= 1) {
      int next = number % base;
      if (next >= 10) {
         char nextChar = char(55 + next);
         string converted(1, nextChar);
         ans.append(converted);
      } else {
         ans.append(to_string(next));
      }
      number /= base;
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int number, base;
   cin >> number >> base;

   cout << changeBase(number, base);
}