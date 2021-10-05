/*
    작성자: 김지수
    작성일: 2021/10/05
    백준 -- 마법사 상어와 토네이도 (20057번)
    문제:
*/
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const double dustRatio[] = {0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05};

const int dustDxOdd[] = {0, 0, -1, -1, -1, -1, -2, -2, -3, -2};
const int dustDyOdd[] = {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0};
const int dustDyEven[] = {0, 0, 1, 1, 1, 1, 2, 2, 3, 2};

const int MAX_N = 499;
int graph[MAX_N][MAX_N];
int boardSize;
int totalDustOut = 0;
struct POS {
   int y, x;
   int level, dir;
};

void moveDust(int sy, int sx, int dir, int level) {
   int ddx[10];
   int ddy[10];
   if (dir == 0) {
      memcpy(ddx, dustDxOdd, sizeof(ddx));
      memcpy(ddy, dustDyOdd, sizeof(ddy));
   } else if (dir == 1) {
      memcpy(ddx, dustDyOdd, sizeof(ddx));
      memcpy(ddy, dustDyEven, sizeof(ddy));
   } else if (dir == 2) {
      memcpy(ddx, dustDyEven, sizeof(ddx));
      memcpy(ddy, dustDyOdd, sizeof(ddy));
   } else {
      memcpy(ddx, dustDyOdd, sizeof(ddx));
      memcpy(ddy, dustDxOdd, sizeof(ddy));
   }
   int nowY = sy;
   int nowX = sx;
   while (level--) {
      int nextY = nowY + dy[dir];
      int nextX = nowX + dx[dir];
      int totDust = graph[nextY][nextX];
      int dustUsed = 0;

      for (int i = 0; i < 10; i++) {
         int dustY = nowY + ddy[i];
         int dustX = nowX + ddx[i];
         int dustAmount = 0;
         if (i == 9) {
            dustAmount = totDust - dustUsed;
            if (dustAmount < 0) {
               dustAmount = 0;
            }
         } else {
            dustAmount = floor(totDust * dustRatio[i]);
         }
         if (dustY < 0 || dustX < 0 || dustY >= boardSize ||
             dustX >= boardSize) {
            totalDustOut += dustAmount;
         } else {
            graph[dustY][dustX] += dustAmount;
         }
         dustUsed += dustAmount;
      }
      graph[nextY][nextX] = 0;
      nowX = nextX;
      nowY = nextY;
      if (nowX < 0 || nowY < 0) {
         break;
      }
   }
}

void move(int y, int x) {
   queue<POS> q;
   POS start;
   start.y = y;
   start.x = x;
   start.level = 1;
   start.dir = 0;
   q.push(start);
   while (!q.empty()) {
      int nowY = q.front().y;
      int nowX = q.front().x;
      int nowLevel = q.front().level;
      int nowDir = q.front().dir;
      q.pop();
      int dirStart = 0;
      if (nowY <= 0 && nowX <= 0) {
         break;
      }
      int nextY = nowY + dy[nowDir] * nowLevel;
      int nextX = nowX + dx[nowDir] * nowLevel;
      moveDust(nowY, nowX, nowDir, nowLevel);
      POS next;
      next.y = nextY;
      next.x = nextX;
      next.level = nowLevel + 1;
      if (nowDir == 1 || nowDir == 3) {
         next.level = nowLevel + 1;
      } else {
         next.level = nowLevel;
      }
      next.dir = (nowDir + 1) % 4;
      q.push(next);
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> boardSize;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         cin >> graph[i][j];
      }
   }
   int startY = boardSize / 2;
   int startX = boardSize / 2;
   move(startY, startX);
   cout << totalDustOut;
}