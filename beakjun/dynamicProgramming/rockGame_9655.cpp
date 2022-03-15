/*
    작성자: 김지수
    작성일: 2022/03/16
    백준 -- 돌 게임 (9655번)
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1001;
int cache[MAX];

int dp(int n) {
   int &ret = cache[n];
   if (n == 0 || n == 1 || n == 2) {
      return n;
   }
   if (ret != -1) {
      return ret;
   } else {
      cache[n] = min(dp(n - 1) + 1, dp(n - 3) + 1);
      return ret;
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(cache, -1, sizeof(cache));
   int n;
   cin >> n;
   int temp = dp(n);
   if (temp % 2 == 0) {
      cout << "CY";
   } else {
      cout << "SK";
   }
}