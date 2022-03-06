/*
    작성자: 김지수
    작성일: 2022/03/06
    백준 -- 유기농 배추 (1012번)
*/

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 2500;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int board[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int y, int x, int h, int w) {
   queue<pair<int, int> > q;
   visited[y][x] = true;
   q.push(make_pair(y, x));
   while (!q.empty()) {
      int nowY = q.front().first;
      int nowX = q.front().second;
      q.pop();
      for (int dir = 0; dir < 4; dir++) {
         int nextY = nowY + dy[dir];
         int nextX = nowX + dx[dir];
         if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w) {
            continue;
         }
         if (!visited[nextY][nextX] && board[nextY][nextX] == 1) {
            visited[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
         }
      }
   }
}

int countWorms(int height, int width) {
   int count = 0;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (!visited[i][j] && board[i][j] == 1) {
            bfs(i, j, height, width);
            count++;
         }
      }
   }
   return count;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int testCase;
   cin >> testCase;
   while (testCase--) {
      int height, width, vegNum;
      cin >> height >> width >> vegNum;
      memset(board, 0, sizeof(board));
      memset(visited, false, sizeof(visited));
      for (int i = 0; i < vegNum; i++) {
         int y, x;
         cin >> y >> x;
         board[y][x] = 1;
      }
      cout << countWorms(height, width) << '\n';
   }
}
