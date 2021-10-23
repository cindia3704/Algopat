/*
    작성자: 김지수
    작성일: 2021/10/23
    백준 -- 연구소 (14502번)
    문제:
*/

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int VIRUS = 2;
const int WALL = 1;
const int EMPTY = 0;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const int MAX_N = 9;
int height, width;
int board[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool wallUsed[MAX_N][MAX_N];
int maxCount = -1;

int countSafeArea() {
   int count = 0;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (temp[i][j] == EMPTY) {
            count++;
         }
      }
   }
   return count;
}

void bfs(int y, int x) {
   queue<pair<int, int> > q;
   q.push(make_pair(y, x));
   visited[y][x] = true;
   while (!q.empty()) {
      int nY = q.front().first;
      int nX = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nextY = nY + dy[i];
         int nextX = nX + dx[i];
         if (nextY < 0 || nextX < 0 || nextY >= height || nextX >= width) {
            continue;
         } else {
            if (!visited[nextY][nextX] && temp[nextY][nextX] == EMPTY) {
               temp[nextY][nextX] = VIRUS;
               visited[nextY][nextX] = true;
               q.push(make_pair(nextY, nextX));
            }
         }
      }
   }
}

void moveVirus() {
   memset(visited, false, sizeof(visited));
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (!visited[i][j] && temp[i][j] == VIRUS) {
            bfs(i, j);
         }
      }
   }
   int tempCount = countSafeArea();
   if (tempCount > maxCount) {
      maxCount = tempCount;
   }
   return;
}

void makeCombination(int depth) {
   if (depth == 3) {
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            temp[i][j] = board[i][j];
         }
      }

      moveVirus();
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            temp[i][j] = board[i][j];
         }
      }
      return;
   } else {
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            if (board[i][j] == EMPTY && !wallUsed[i][j]) {
               board[i][j] = WALL;
               wallUsed[i][j] = true;
               makeCombination(depth + 1);
               wallUsed[i][j] = false;
               board[i][j] = EMPTY;
            }
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> board[i][j];
      }
   }
   memset(wallUsed, false, sizeof(wallUsed));
   makeCombination(0);
   cout << maxCount;
}
