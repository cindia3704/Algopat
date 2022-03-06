/*
    작성자: 김지수
    작성일: 2022/03/07
    백준 -- 영역 구하기 (2583번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int board[MAX][MAX];
bool visited[MAX][MAX];

void fill(int sy, int sx, int ey, int ex) {
   for (int i = sy; i <= ey; i++) {
      for (int j = sx; j <= ex; j++) {
         board[i][j] = 1;
      }
   }
}

int bfs(int y, int x, int height, int width) {
   int count = 0;
   queue<pair<int, int> > q;
   visited[y][x] = true;
   q.push(make_pair(y, x));
   while (!q.empty()) {
      int nowY = q.front().first;
      int nowX = q.front().second;
      q.pop();
      count++;
      for (int i = 0; i < 4; i++) {
         int nextY = nowY + dy[i];
         int nextX = nowX + dx[i];
         if (nextY < 0 || nextY >= height || nextX < 0 || nextX >= width) {
            continue;
         }
         if (!visited[nextY][nextX] && board[nextY][nextX] == 0) {
            visited[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
         }
      }
   }
   return count;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int height, width, squareNum;
   cin >> height >> width >> squareNum;
   memset(board, 0, sizeof(board));
   memset(visited, false, sizeof(visited));

   for (int i = 0; i < squareNum; i++) {
      int sx, sy, ex, ey;
      cin >> sx >> sy >> ex >> ey;
      fill(sy, sx, ey - 1, ex - 1);
   }

   vector<int> ans;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (!visited[i][j] && board[i][j] == 0) {
            ans.push_back(bfs(i, j, height, width));
         }
      }
   }
   sort(ans.begin(), ans.end());
   cout << ans.size() << '\n';
   for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
   }
}