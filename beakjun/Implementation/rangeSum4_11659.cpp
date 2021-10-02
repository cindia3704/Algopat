/*
    작성자: 김지수
    작성일: 2021/10/03
    백준 -- 구간 합 구하기 4 (11659번)
    문제:
*/

#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int seqLength, tc;
   cin >> seqLength >> tc;

   int arr[seqLength + 1];
   long long prefixSum[seqLength + 1];
   fill(prefixSum, prefixSum + seqLength + 1, 0);
   for (int i = 1; i <= seqLength; i++) {
      cin >> arr[i];
      prefixSum[i] = prefixSum[i - 1] + arr[i];
   }
   for (int i = 0; i < tc; i++) {
      int start, end;
      cin >> start >> end;
      cout << (prefixSum[end] - prefixSum[start - 1]) << '\n';
   }
}