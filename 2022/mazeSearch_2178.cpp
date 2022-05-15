/*
    작성자: 김지수
    작성일: 2022/05/15
    백준 -- DFS와 BFS (1260번)
*/

#include <cstring>
#include <iostream>
#include <queue>
#define MAX 101
#define ROAD 1
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int height, width;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int ans = 987654321;

struct BLOCK {
   int y, x, count;
};

void bfs() {
   queue<BLOCK> q;
   BLOCK start;
   start.count = 1;
   start.x = 0;
   start.y = 0;
   q.push(start);
   while (!q.empty()) {
      BLOCK now = q.front();
      q.pop();
      // 최단 경로 찾으면 업데이트
      if (now.x == width - 1 && now.y == height - 1) {
         if (now.count < ans) {
            ans = now.count;
         }
      } else {
         // 동서남북으로 갈수 있는지 확인
         for (int i = 0; i < 4; i++) {
            BLOCK next;
            next.y = now.y + dy[i];
            next.x = now.x + dx[i];
            next.count = now.count + 1;
            //보드 크기 넘어가면
            if (next.y < 0 || next.y >= height || next.x < 0 ||
                next.x >= width) {
               continue;
            } else {
               // 아직 방문 안했고, 길이면
               if (visited[next.y][next.x] == false &&
                   graph[next.y][next.x] == ROAD) {
                  // 방문처리
                  visited[next.y][next.x] = true;
                  q.push(next);
               }
            }
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> height >> width;
   // 공백 없이 입력받아서 string으로 받고 잘라서 넣기
   for (int i = 0; i < height; i++) {
      string line;
      cin >> line;
      for (int j = 0; j < width; j++) {
         graph[i][j] = line[j] - '0';  // int형으로 넣기 위해
      }
   }

   memset(visited, false, sizeof(visited));
   bfs();
   cout << ans;
}