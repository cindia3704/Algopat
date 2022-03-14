/*
    작성자: 김지수
    작성일: 2022/03/13
    백준 -- 2차원 배열의 합 (2167번)
    문제:
*/

#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 301;
int arr[MAX][MAX];
int prefixSum[MAX + 1][MAX + 1];

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int h, w;
   cin >> h >> w;
   memset(arr, 0, sizeof(arr));
   memset(prefixSum, 0, sizeof(prefixSum));
   for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
         cin >> arr[i][j];
      }
   }
   for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
         prefixSum[i][j] = arr[i][j] + prefixSum[i - 1][j] +
                           prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
      }
   }

   int resultNum;
   cin >> resultNum;
   for (int i = 0; i < resultNum; i++) {
      int sy, sx, ey, ex;
      cin >> sy >> sx >> ey >> ex;

      cout << prefixSum[ey][ex] + prefixSum[sy - 1][sx - 1] -
                  prefixSum[ey][sx - 1] - prefixSum[sy - 1][ex]
           << '\n';
   }
}