/*
    작성자: 김지수
    작성일: 2021/09/19
    백준 -- 구슬 탈출 2 (13460번)
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 10;
// NESW
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int height, width;
char graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N][MAX_N];
struct marbles {
   int redY, redX, blueY, blueX;
   int count;
};

int bfs(marbles start) {
   int ans = -1;
   queue<marbles> q;
   q.push(start);
   // 방문 처리
   visited[start.redY][start.redX][start.blueY][start.blueX] = true;

   while (!q.empty()) {
      marbles now = q.front();
      q.pop();

      // 10번 안에 정답 안나옴
      if (now.count > 10) {
         break;
      }
      // 성공 케이스
      if (graph[now.redY][now.redX] == 'O' &&
          graph[now.blueY][now.blueX] != 'O') {
         ans = now.count;
         break;
      }
      // NESW 다 돌면서 다음 red & blue 위치 넣기
      for (int i = 0; i < 4; i++) {
         int nextRedY = now.redY;
         int nextRedX = now.redX;
         int nextBlueY = now.blueY;
         int nextBlueX = now.blueX;

         // 방향 정해지면 벽 / 구멍 보일때 까지 돌림
         while (true) {
            if (graph[nextRedY][nextRedX] != '#' &&
                graph[nextRedY][nextRedX] != 'O') {
               nextRedY += dy[i];
               nextRedX += dx[i];
            } else {
               if (graph[nextRedY][nextRedX] == '#') {
                  // 위에서 ++ 해줘서 벽 위치 전으로 돌아가야함
                  nextRedY -= dy[i];
                  nextRedX -= dx[i];
               }
               // 벽 보거나 구멍 보면 stop
               break;
            }
         }
         while (true) {
            if (graph[nextBlueY][nextBlueX] != '#' &&
                graph[nextBlueY][nextBlueX] != 'O') {
               nextBlueY += dy[i];
               nextBlueX += dx[i];
            } else {
               if (graph[nextBlueY][nextBlueX] == '#') {
                  nextBlueY -= dy[i];
                  nextBlueX -= dx[i];
               }
               break;
            }
         }
         // 벽 / 구멍 기준으로 돌렸으니까 Red & blue 같은 위치에 있을 수 있음
         if (nextRedY == nextBlueY && nextRedX == nextBlueX) {
            if (graph[nextRedY][nextRedX] != 'O') {
               // 같은 위치에 있다는건 결국 같은 row or 같은 col에 있었다는거
               // 더 많이 움직인게 더 뒤에 있었다는 거니까
               // 더 많이 움직인거 찾아서 이전 칸으로 이동!
               int redDistance =
                   abs(nextRedX - now.redX) + abs(nextRedY - now.redY);
               int blueDistance =
                   abs(nextBlueX - now.blueX) + abs(nextBlueY - now.blueY);
               if (redDistance > blueDistance) {
                  nextRedX -= dx[i];
                  nextRedY -= dy[i];
               } else {
                  nextBlueX -= dx[i];
                  nextBlueY -= dy[i];
               }
            }
         }
         // 아직 현재 빨 & 파 공 위치 조합 안나왔으면 큐에 넣고 방문 처리
         if (!visited[nextRedY][nextRedX][nextBlueY][nextBlueX]) {
            visited[nextRedY][nextRedX][nextBlueY][nextBlueX] = true;
            marbles next;
            next.blueX = nextBlueX;
            next.blueY = nextBlueY;
            next.redX = nextRedX;
            next.redY = nextRedY;
            next.count = now.count + 1;
            q.push(next);
         }
      }
   }
   return ans;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(visited, false, sizeof(visited));
   cin >> height >> width;

   marbles start;
   start.count = 0;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> graph[i][j];
         if (graph[i][j] == 'R') {
            start.redY = i;
            start.redX = j;
         }
         if (graph[i][j] == 'B') {
            start.blueY = i;
            start.blueX = j;
         }
      }
   }

   cout << bfs(start);
}