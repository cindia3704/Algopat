/*
    작성자: 김지수
    작성일: 2022/03/13
    백준 -- 달탱이 (1913번)
*/

#include <cmath>
#include <iostream>
using namespace std;
const int MAX = 1000;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int board[MAX][MAX];
struct Info {
   int y, x, num;
};

int findY, findX;
int target;
Info fillBoard(int y, int x, int dir, int times, int num) {
   for (int i = 0; i < times; i++) {
      if (num == target) {
         findY = y;
         findX = x;
      }
      board[y][x] = num;
      num++;
      y = y + dy[dir];
      x = x + dx[dir];
   }
   Info i;
   i.num = num;
   i.y = y;
   i.x = x;
   return i;
}

int changeDir(int dir) {
   if (dir == 3) {
      dir = 0;
   } else {
      dir++;
   }
   return dir;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n >> target;
   int y, x;
   y = n / 2;
   x = n / 2;
   int dir = 0;
   int times = 1;
   int num = 1;
   int count = 0;
   while (true) {
      if (num >= pow(n, 2)) {
         break;
      } else {
         Info next = fillBoard(y, x, dir, times, num);
         y = next.y;
         x = next.x;
         num = next.num;
         dir = changeDir(dir);
      }
      count++;
      if (count % 2 == 0) {
         times++;
      }
   }

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout << board[i][j] << " ";
      }
      cout << '\n';
   }
   cout << findY + 1 << " " << findX + 1;
}