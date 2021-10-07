/*
    작성자: 김지수
    작성일: 2021/08/12
    백준 -- 로봇 청소기 (14503번)
    문제:
*/
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 50;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int height, width;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int cleanedSpace = 0;
int ddir = 0;

void clean(int y, int x, int command) {
   if (board[y][x] != 1 && !visited[y][x] && command == 1) {
      visited[y][x] = true;
      cleanedSpace++;
   }
   bool found = false;
   int nowY = y;
   int nowX = x;
   int nextY = nowY;
   int nextX = nowX;
   int nextDir = ddir;
   for (int i = 1; i <= 4; i++) {
      nextDir = (ddir + (4 - i)) % 4;
      nextY = nowY + dy[nextDir];
      nextX = nowX + dx[nextDir];
      if (nextY >= height || nextX >= width || nextX < 0 || nextY < 0 ||
          board[nextY][nextX] == 1) {
         continue;
      }
      if (!visited[nextY][nextX] && board[nextY][nextX] != 1) {
         found = true;
         break;
      }
   }
   if (found) {
      ddir = nextDir;
      clean(nextY, nextX, 1);
   } else {
      nextY = nowY - dy[ddir];
      nextX = nowX - dx[ddir];
      if (board[nextY][nextX] == 1 || nextY >= height || nextX >= width ||
          nextX < 0 || nextY < 0) {
         return;
      } else {
         //  cout << "후진" << endl;
         clean(nextY, nextX, 0);
      }
   }
   return;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width;
   memset(visited, false, sizeof(visited));
   int robotY, robotX, robotDir;
   cin >> robotY >> robotX >> robotDir;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> board[i][j];
      }
   }
   ddir = robotDir;
   clean(robotY, robotX, 1);
   cout << cleanedSpace;
}
