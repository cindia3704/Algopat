/*
    작성자: 김지수
    작성일: 2022/03/14
    백준 -- 귀찮아 (SIB) (14929번)
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;
   vector<int> arr;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      arr.push_back(num);
   }
   sort(arr.begin(), arr.end());

   long long prefixSum[n + 1];
   memset(prefixSum, 0, sizeof(prefixSum));

   for (int i = 1; i <= n; i++) {
      prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
   }

   long long sum = 0;
   for (int i = 1; i < n; i++) {
      int times = prefixSum[i] - prefixSum[i - 1];
      long long s = prefixSum[n] - prefixSum[i];
      sum += times * s;
   }
   cout << sum;
}