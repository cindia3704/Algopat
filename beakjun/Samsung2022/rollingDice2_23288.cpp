/*
    작성자: 김지수
    작성일: 2022/04/25
    백준 -- 주사위 굴리기2 (23288번)
    문제:
*/

#include <cstring>
#include <iostream>
#include <queue>
#define MAX 21
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int bnr[3] = {6, 2, 3};
int height, width, totalTurn;
int board[MAX][MAX];
int totalScore = 0;
bool visited[MAX][MAX];

void move(int dir) {
   int bottom = bnr[0];
   int north = bnr[1];
   int right = bnr[2];
   if (dir == 0) {  // east
      bnr[0] = right;
      bnr[2] = 7 - bottom;
   } else if (dir == 1) {  // west
      bnr[0] = 7 - right;
      bnr[2] = bottom;
   } else if (dir == 2) {  // south
      bnr[0] = 7 - north;
      bnr[1] = bottom;
   } else if (dir == 3) {  // north
      bnr[0] = north;
      bnr[1] = 7 - bottom;
   }
}

int flipDir(int dir) {  // 벽 닿으면 반대방향으로!
   if (dir == 0) {
      return 1;
   } else if (dir == 1) {
      return 0;
   } else if (dir == 2) {
      return 3;
   } else {
      return 2;
   }
}

void bfs(int y, int x, int num) {
   memset(visited, false, sizeof(visited));
   visited[y][x] = true;
   queue<pair<int, int> > q;
   q.push(make_pair(y, x));
   int count = 0;
   while (!q.empty()) {
      pair<int, int> now = q.front();
      q.pop();
      count++;
      for (int i = 0; i < 4; i++) {
         int nextY = now.first + dy[i];
         int nextX = now.second + dx[i];
         if (nextY < 0 || nextY >= height || nextX < 0 || nextX >= width) {
            continue;
         } else {
            if (!visited[nextY][nextX] && board[nextY][nextX] == num) {
               visited[nextY][nextX] = true;
               q.push(make_pair(nextY, nextX));
            }
         }
      }
   }
   totalScore += (num * count);
}

int turnClockwise(int dir) {
   if (dir == 0) {
      return 2;
   } else if (dir == 1) {
      return 3;
   } else if (dir == 2) {
      return 1;
   } else {
      return 0;
   }
}

int turnCounterClockwise(int dir) {
   if (dir == 0) {
      return 3;
   } else if (dir == 1) {
      return 2;
   } else if (dir == 2) {
      return 0;
   } else {
      return 1;
   }
}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width >> totalTurn;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> board[i][j];
      }
   }

   int nowDir = 0;
   int ny = 0;
   int nx = 0;
   for (int i = 0; i < totalTurn; i++) {
      // 다음 자리 구하기
      int nextY = ny + dy[nowDir];
      int nextX = nx + dx[nowDir];

      //벽이면 반대방향으로 움직임!
      if (nextY < 0 || nextY >= height || nextX < 0 || nextX >= width) {
         nowDir = flipDir(nowDir);
         nextY = ny + dy[nowDir];
         nextX = nx + dx[nowDir];
      }
      move(nowDir);                            // 주사위 굴리고
      bfs(nextY, nextX, board[nextY][nextX]);  // 점수 더함
      if (bnr[0] > board[nextY][nextX]) {
         //  90도 시계방향 회전
         nowDir = turnClockwise(nowDir);
      } else if (bnr[0] < board[nextY][nextX]) {
         // 90도 시계반대 방향 회전
         nowDir = turnCounterClockwise(nowDir);
      }
      ny = nextY;
      nx = nextX;
   }
   cout << totalScore;
}