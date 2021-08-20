/*
    작성자: 김지수
    작성일: 2021/08/21
    백준 -- 점화식(13699번)
    문제:
    - 다음의 점화식에 의해 정의된 수열 t(n)을 생각하자:
        - t(0)=1
        - t(n)=t(0)*t(n-1)+t(1)*t(n-2)+...+t(n-1)*t(0)
*/

#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 36;
long long cache[MAX_N];
long long calculate(int n) {
   long long &ret = cache[n];
   if (n == 0) {
      return 1;
   }
   if (ret != -1) {
      return ret;
   } else {
      long long ans = 0;
      int temp = n;
      for (int i = 0; i < n; i++) {
         ans += calculate(i) * calculate(temp - 1);
         temp--;
      }
      ret = ans;
   }
   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(cache, -1, sizeof(cache));

   int n;
   cin >> n;
   cout << calculate(n);
}