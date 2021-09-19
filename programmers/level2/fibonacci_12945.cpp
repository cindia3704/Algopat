/*
    작성자: 김지수
    작성일: 2021/09/19
    programmers -- 피보나치 수 (12945번)
*/

#include <string>
#include <vector>

using namespace std;
const int MOD = 1234567;
const int MAX_N = 100001;
long long cache[MAX_N];
long long dp(int n) {
   long long &ret = cache[n];
   if (n == 0 || n == 1) {
      return n;
   }
   if (ret != -1) {
      return ret;
   } else {
      ret = dp(n - 1) % MOD + dp(n - 2) % MOD;
   }
   return ret % MOD;
}

int solution(int n) {
   int answer = 0;
   fill(cache, cache + MAX_N, -1);
   answer = dp(n);
   return answer;
}