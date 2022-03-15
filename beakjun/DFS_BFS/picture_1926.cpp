/*
    작성자: 김지수
    작성일: 2022/03/16
    백준 -- 그림 (1926번)
    문제:
*/

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 501;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int height, width;
bool visited[MAX][MAX];
int board[MAX][MAX];
int maxArea = 0;
int countPic = 0;

void bfs(int y, int x) {
   queue<pair<int, int> > q;
   visited[y][x] = true;
   int counts = 0;
   q.push(make_pair(y, x));
   while (!q.empty()) {
      pair<int, int> now = q.front();
      counts++;
      q.pop();
      maxArea = max(maxArea, counts);

      for (int i = 0; i < 4; i++) {
         int nextY = now.first + dy[i];
         int nextX = now.second + dx[i];
         if (nextY < 0 || nextX < 0 || nextY >= height || nextX >= width) {
            continue;
         }

         if (!visited[nextY][nextX] && board[nextY][nextX] == 1) {
            visited[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> board[i][j];
      }
   }

   memset(visited, false, sizeof(visited));

   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (!visited[i][j] && board[i][j] == 1) {
            bfs(i, j);
            countPic++;
         }
      }
   }
   cout << countPic << '\n' << maxArea;
}