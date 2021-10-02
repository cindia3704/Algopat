/*
    작성자: 김지수
    작성일: 2021/10/03
    백준 -- 구간 합 구하기 4 (11659번)
    문제:
*/
#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int boardSize, tc;
   cin >> boardSize >> tc;

   int arr[boardSize + 1][boardSize + 1];
   long long prefixSum[boardSize + 1][boardSize + 1];
   memset(prefixSum, 0, sizeof(prefixSum));
   for (int i = 1; i <= boardSize; i++) {
      for (int j = 1; j <= boardSize; j++) {
         cin >> arr[i][j];
         prefixSum[i][j] = arr[i][j] + prefixSum[i][j - 1];
      }
   }

   for (int i = 0; i < tc; i++) {
      int sX, sY, eX, eY;
      cin >> sY >> sX >> eY >> eX;
      int sum = 0;
      for (int i = sY; i <= eY; i++) {
         sum += (prefixSum[i][eX] - prefixSum[i][sX - 1]);
      }
      cout << sum << '\n';
   }
}