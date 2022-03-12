/*
    작성자: 김지수
    작성일: 2022/03/13
    백준 -- 나이트의 이동 (7562번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 301;
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool visited[MAX][MAX];
struct Block {
   int x, y, count;
};

int dfs(int nowY, int nowX, int targetY, int targetX, int boardSize) {
   int minPath = 987654321;
   queue<Block> q;
   visited[nowY][nowX] = true;
   Block start;
   start.x = nowX;
   start.y = nowY;
   start.count = 0;
   q.push(start);
   while (!q.empty()) {
      Block now = q.front();
      q.pop();
      if (now.y == targetY && now.x == targetX) {
         minPath = min(minPath, now.count);
      } else {
         for (int i = 0; i < 8; i++) {
            int nextY = now.y + dy[i];
            int nextX = now.x + dx[i];
            if (nextY >= boardSize || nextY < 0 || nextX >= boardSize ||
                nextX < 0) {
               continue;
            }
            if (!visited[nextY][nextX]) {
               visited[nextY][nextX] = true;
               Block next;
               next.y = nextY;
               next.x = nextX;
               next.count = now.count + 1;
               q.push(next);
            }
         }
      }
   }
   return minPath;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tc;
   cin >> tc;
   while (tc--) {
      int boardSize;
      cin >> boardSize;
      memset(visited, false, sizeof(visited));
      int nowX, nowY, targetX, targetY;
      cin >> nowX >> nowY >> targetX >> targetY;
      cout << dfs(nowY, nowX, targetY, targetX, boardSize) << '\n';
   }
}