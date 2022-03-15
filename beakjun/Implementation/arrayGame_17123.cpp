/*
    작성자: 김지수
    작성일: 2022/03/15
    백준 -- 배열 놀이 (17123번)
    문제:
*/

#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1001;
long long prefixSumRow[MAX];
long long prefixSumCol[MAX];
int graph[MAX][MAX];

void printGraph(int boardSize) {
   for (int i = 0; i < boardSize; i++) {
      cout << prefixSumRow[i] << " ";
   }
   cout << endl;
   for (int i = 0; i < boardSize; i++) {
      cout << prefixSumCol[i] << " ";
   }
}

void playGame(int boardSize, int sy, int sx, int ey, int ex, int weight) {
   int diffY = ey - sy + 1;
   int diffX = ex - sx + 1;

   for (int i = sy - 1; i <= ey - 1; i++) {
      prefixSumRow[i] += diffX * weight;
   }
   for (int i = sx - 1; i <= ex - 1; i++) {
      prefixSumCol[i] += diffY * weight;
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tc;
   cin >> tc;
   while (tc--) {
      int boardSize, gameRound;
      cin >> boardSize >> gameRound;
      memset(prefixSumCol, 0, sizeof(prefixSumCol));
      memset(prefixSumRow, 0, sizeof(prefixSumRow));

      for (int i = 0; i < boardSize; i++) {
         long long rowSum = 0;
         for (int j = 0; j < boardSize; j++) {
            cin >> graph[i][j];
            prefixSumCol[j] += graph[i][j];
            rowSum += graph[i][j];
         }
         prefixSumRow[i] += rowSum;
      }
      for (int i = 0; i < gameRound; i++) {
         int sy, sx, ey, ex, w;
         cin >> sy >> sx >> ey >> ex >> w;
         playGame(boardSize, sy, sx, ey, ex, w);
      }
      printGraph(boardSize);
   }
}