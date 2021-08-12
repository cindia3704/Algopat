/*
    작성자: 김지수
    작성일: 2021/08/12
    백준 -- 아기 상어2 (17086번)
    문제:
    - N×M 크기의 공간에 아기 상어 여러 마리가 있다
    - 어떤 칸의 안전 거리는 그 칸과 가장 거리가 가까운 아기 상어와의 거리이다.
    - 이동은 인접한 8방향(대각선 포함)이 가능하다.
    - 안전 거리가 가장 큰 칸을 구해보자
*/
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 50;
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int sea[MAX_N][MAX_N];
int height, width;

void bfs(int y, int x) {
   bool visited[MAX_N][MAX_N];
   memset(visited, false, sizeof(visited));
   visited[y][x] = true;
   queue<pair<int, pair<int, int> > > q;
   q.push(make_pair(0, make_pair(y, x)));
   while (!q.empty()) {
      int nowX = q.front().second.second;
      int nowY = q.front().second.first;
      int nowDistance = q.front().first;

      q.pop();
      for (int i = 0; i < 8; i++) {
         int nextX = nowX + dx[i];
         int nextY = nowY + dy[i];
         int nextDistance = nowDistance + 1;

         if (nextY < 0 || nextY >= height || nextX < 0 || nextX >= width) {
            continue;
         }
         if (!visited[nextY][nextX] && sea[nextY][nextX] != -1) {
            if (sea[nextY][nextX] > nextDistance || sea[nextY][nextX] == 0) {
               sea[nextY][nextX] = nextDistance;
               visited[nextY][nextX] = true;
               q.push(make_pair(nextDistance, make_pair(nextY, nextX)));
            }
         }
      }
   }
}

int main(void) {
   cin >> height >> width;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> sea[i][j];
         if (sea[i][j] == 1) {
            sea[i][j] = -1;
         }
      }
   }
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (sea[i][j] == -1) {
            bfs(i, j);
         }
      }
   }
   int maxDistance = 0;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (sea[i][j] > maxDistance) {
            maxDistance = sea[i][j];
         }
      }
   }
   cout << maxDistance;
}