/*
    작성자: 김지수
    작성일: 2021/10/09
    백준 -- 쉬운 최단거리(14940번)
    문제:
*/

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 1000;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
bool visited[MAX_N][MAX_N];
int graph[MAX_N][MAX_N];
int height, width;
struct Block {
   int y, x, count;
};

void bfs(int y, int x) {
   queue<Block> q;
   Block start;
   start.y = y;
   start.x = x;
   start.count = 0;
   q.push(start);
   visited[y][x] = true;
   while (!q.empty()) {
      int nowY = q.front().y;
      int nowX = q.front().x;
      int nowCount = q.front().count;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nextY = nowY + dy[i];
         int nextX = nowX + dx[i];
         if (nextY < 0 || nextX < 0 || nextY >= height || nextX >= width) {
            continue;
         } else {
            if (!visited[nextY][nextX] && graph[nextY][nextX] != -2) {
               graph[nextY][nextX] = nowCount + 1;
               visited[nextY][nextX] = true;
               Block next;
               next.y = nextY;
               next.x = nextX;
               next.count = nowCount + 1;
               q.push(next);
            }
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(visited, false, sizeof(visited));
   cin >> height >> width;
   int targetY, targetX;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         int num;
         cin >> num;
         if (num == 2) {
            targetY = i;
            targetX = j;
            graph[i][j] = 0;
         } else if (num == 1) {
            graph[i][j] = -1;
         } else {
            graph[i][j] = -2;
         }
      }
   }
   bfs(targetY, targetX);

   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (graph[i][j] == -2) {
            cout << 0 << " ";
         } else {
            cout << graph[i][j] << " ";
         }
      }
      cout << '\n';
   }
}