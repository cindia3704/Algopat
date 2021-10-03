/*
    작성자: 김지수
    작성일: 2021/10/03
    백준 -- 순서쌍의 곱의 합(13900번)
    문제:
*/
#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   long long arr[100000];
   long long answer = 0;
   long long prefixSum[100000];
   for (int i = 0; i < n; ++i) {
      cin >> arr[i];
   }

   prefixSum[0] = arr[0];

   for (int i = 1; i < n; ++i) {
      prefixSum[i] = prefixSum[i - 1] + arr[i];
   }

   for (int i = 0; i < n - 1; ++i) {
      answer += arr[i] * (prefixSum[n - 1] - prefixSum[i]);
   }

   cout << answer;
}