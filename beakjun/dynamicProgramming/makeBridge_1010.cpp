/*
    작성자: 김지수
    작성일: 2022/03/16
    백준 -- 다리 놓기 (1010번)
    문제:
*/

#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 31;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   unsigned long long tc;
   cin >> tc;
   while (tc--) {
      unsigned long long r, c;
      cin >> r >> c;

      unsigned long long big, small;

      if (c - r > r) {
         big = c - r;
         small = r;
      } else {
         big = r;
         small = c - r;
      }

      unsigned long long ans = 1;

      for (unsigned long long i = big + 1; i <= c; i++) {
         ans *= i;
      }
      for (unsigned long long i = 1; i <= small; i++) {
         ans /= i;
      }
      cout << ans << '\n';
   }
}