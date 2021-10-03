/*
    작성자: 김지수
    작성일: 2021/10/04
    백준 -- 거스름돈(14916번)
    문제:
*/
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 100001;
int cache[MAX_N];

int dp(int n) {
   int &ret = cache[n];
   if (n < 2) {
      ret = 987654321;
   }
   if (n == 3) {
      return 987654321;
   }
   if (n == 2) {
      return 1;
   }
   if (n == 5) {
      return 1;
   }
   if (ret != -1) {
      return ret;
   } else {
      int temp1 = dp(n - 5) + 1;
      int temp2 = dp(n - 2) + 1;
      ret = (temp1 > temp2) ? temp2 : temp1;
   }
   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(cache, -1, sizeof(cache));
   int n;
   cin >> n;
   int ans = dp(n);
   if (ans >= 987654321) {
      ans = -1;
   }
   cout << ans;
}