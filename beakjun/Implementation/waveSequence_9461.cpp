/*
    작성자: 김지수
    작성일: 2021/10/08
    백준 -- 파도반 수열(9461번)
    문제:
*/
#include <iostream>
using namespace std;
const int MAX_N = 101;
long long cache[MAX_N];

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cache[1] = 1;
   cache[2] = 1;
   cache[3] = 1;
   for (int i = 4; i < MAX_N; i++) {
      cache[i] = cache[i - 2] + cache[i - 3];
   }

   int tc;
   cin >> tc;
   while (tc--) {
      int n;
      cin >> n;
      cout << cache[n] << '\n';
   }
}