/*
    작성자: 김지수
    작성일: 2021/04/25
    백준 -- 미로탐색 (2178번)
    문제:
    - N×M크기의 배열로 표현되는 미로가 있다.
    - 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을
   나타낸다.
   -  이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때
   지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int MAX = 101;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int n, m;
char graph[MAX][MAX];
int visited[MAX][MAX] = {
    0,
};
int ans = 987654321;
queue<pair<int, int> > q;

void findWay(int startX, int startY, int startCount) {
   visited[startY][startX] = startCount;
   q.push(make_pair(startY, startX));

   while (!q.empty()) {
      int nowY = q.front().first;
      int nowX = q.front().second;
      q.pop();

      if (nowY == n && nowX == m) {
         ans = min(ans, visited[n][m]);
         break;
      }

      for (int dir = 0; dir < 4; dir++) {
         int nextY = nowY + dy[dir];
         int nextX = nowX + dx[dir];
         int nextCount = visited[nowY][nowX] + 1;

         if (nextX > 0 && nextX <= m && nextY > 0 && nextY <= n &&
             visited[nextY][nextX] == 0 && graph[nextY][nextX] == '1') {
            visited[nextY][nextX] = nextCount;
            q.push(make_pair(nextY, nextX));
         }
      }
   }
}

int main(void) {
   cin >> n >> m;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         cin >> graph[i][j];
      }
   }

   findWay(1, 1, 1);
   cout << ans << endl;
}