/*
    작성자: 김지수
    작성일: 2021/09/10
    백준 -- 어두운건 무서워 (16507번)
    문제:
    - 주어진 보드에서 2 꼭지점 사이에 잇는 값 평균
*/

#include <iostream>
using namespace std;
const int MAX_N = 1001;
int board[MAX_N][MAX_N];
long long sum[MAX_N][MAX_N];
int height, width, numAvg;

void getAverage(int y1, int x1, int y2, int x2) {
   long long sumNum = 0;
   int count = (y2 - y1 + 1) * (x2 - x1 + 1);
   for (int i = y1; i <= y2; i++) {
      sumNum += (sum[i][x2] - sum[i][x1 - 1]);
   }
   cout << sumNum / count << endl;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width >> numAvg;
   for (int i = 1; i <= height; i++) {
      for (int j = 1; j <= width; j++) {
         cin >> board[i][j];
         sum[i][j] = board[i][j] + sum[i][j - 1];
      }
   }

   for (int i = 0; i < numAvg; i++) {
      int y1, x1, y2, x2;
      cin >> y1 >> x1 >> y2 >> x2;
      //   getAverage(y1 - 1, x1 - 1, y2 - 1, x2 - 1);
      getAverage(y1, x1, y2, x2);
   }
}