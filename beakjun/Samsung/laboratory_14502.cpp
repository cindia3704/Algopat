/*
    작성자: 김지수
    작성일: 2021/04/25
    백준 -- 연구소 (14502번)
    문제:
    - 인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다.
    - 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
    - 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.
    - 일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로
   모두 퍼져나갈 수 있다.
   - 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다
   - 이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지
   않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.
*/

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 8;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int n, m;
int graph[MAX][MAX];
int numSafeArea = -1;

void bfs() {
   int temp[MAX][MAX];
   queue<pair<int, int> > q;
   bool visited[MAX][MAX] = {
       false,
   };

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         temp[i][j] = graph[i][j];
         if (temp[i][j] == 2) {
            q.push(make_pair(i, j));
         }
      }
   }
   while (!q.empty()) {
      int nowY = q.front().first;
      int nowX = q.front().second;
      temp[nowY][nowX] = 2;
      for (int dir = 0; dir < 4; dir++) {
         int nextY = nowY + dy[dir];
         int nextX = nowX + dx[dir];
         if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
            if (!visited[nextY][nextX] && temp[nextY][nextX] == 0) {
               q.push(make_pair(nextY, nextX));
               visited[nextY][nextX] = true;
            }
         }
      }
      q.pop();
   }
   int ans = 0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (temp[i][j] == 0) {
            ans++;
         }
      }
   }
   numSafeArea = max(numSafeArea, ans);
}

void countSafeArea(int numWall, int startY, int startX) {
   if (numWall == 3) {
      bfs();
      return;
   }
   for (int i = startY; i < n; i++) {
      for (int j = startX; j < m; j++) {
         if (graph[i][j] == 0) {
            graph[i][j] = 1;
            countSafeArea(numWall + 1, i, j);
            graph[i][j] = 0;
         }
      }
      startX = 0;
   }
}
int main(void) {
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> graph[i][j];
      }
   }
   countSafeArea(0, 0, 0);
   cout << numSafeArea << endl;
}