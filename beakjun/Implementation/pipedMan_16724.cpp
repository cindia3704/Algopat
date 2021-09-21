/*
    작성자: 김지수
    작성일: 2021/09/22
    백준 -- 피리 부는 사나이(16724번)
    문제:
*/
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// URDL
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const int MAX_N = 1001;
int board[MAX_N][MAX_N];
// visited bool로 하면 에러..
//시작점에 따라 같은 싸이클이라 간주해야할 때 있어서
int visited[MAX_N][MAX_N];
int ans = 0;
int height, width;

void move(int y, int x, int num) {
   if (visited[y][x] > 0 && visited[y][x] != num) {
      // 이전에 방문했고, 현재 num이랑 다르다
      // -> 같은 사이클 but 시작점이 다른것!
      return;
   } else if (visited[y][x] > 0 && visited[y][x] == num) {
      // 이전에 방문 했고, 현재 num이랑 같다
      // -> 싸이클 찾음!
      ans++;
      return;
   }
   visited[y][x] = num;
   int nextY = y + dy[board[y][x]];
   int nextX = x + dx[board[y][x]];
   move(nextY, nextX, num);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         char dir;
         cin >> dir;
         if (dir == 'U') {
            board[i][j] = 0;
         } else if (dir == 'R') {
            board[i][j] = 1;
         } else if (dir == 'D') {
            board[i][j] = 2;
         } else {
            board[i][j] = 3;
         }
      }
   }
   memset(visited, 0, sizeof(visited));
   int num = 1;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         move(i, j, num);
         num++;
      }
   }
   cout << ans;
}