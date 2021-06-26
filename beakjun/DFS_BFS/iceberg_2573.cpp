/*
    작성자: 김지수
    작성일: 2021/06/26
    백준 -- 빙산 (2573)
    문제:
    - 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다
    - 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다.
    - 빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어든다.
    - 일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로
   모두 퍼져나갈 수 있다.
   - 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에
   동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다
   - 한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의
   시간(년)을 구하는 프로그램을 작성하시오
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 300;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int iceberg[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int row, col;

void dfs(int y, int x) {
   visited[y][x] = true;
   for (int dir = 0; dir < 4; dir++) {
      int nextX = x + dx[dir];
      int nextY = y + dy[dir];
      if (nextY >= 1 && nextY < row - 1 && nextX >= 1 && nextX < col - 1 &&
          visited[nextY][nextX] == false && iceberg[nextY][nextX] != 0) {
         dfs(nextY, nextX);
      }
   }
}

void melt() {
   int copy[MAX_N][MAX_N];
   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         copy[i][j] = iceberg[i][j];
      }
   }

   for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < col - 1; j++) {
         if (copy[i][j]) {
            int countWater = 0;
            for (int dir = 0; dir < 4; dir++) {
               int nextX = j + dx[dir];
               int nextY = i + dy[dir];
               if (copy[nextY][nextX] == 0) {
                  countWater++;
               }
            }
            iceberg[i][j] = max(copy[i][j] - countWater, 0);
         }
      }
   }
}

int main(void) {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin >> row >> col;
   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         cin >> iceberg[i][j];
      }
   }

   int year = 0;
   while (1) {
      int count = 0;
      bool found = false;
      memset(visited, false, sizeof(visited));

      for (int i = 1; i < row - 1; i++) {
         for (int j = 1; j < col - 1; j++) {
            if (visited[i][j] == false && iceberg[i][j]) {
               count++;
               if (count == 2) {
                  found = true;
                  break;
               }
               dfs(i, j);
            }
         }
      }

      if (found) {
         break;
      }
      // 카운트 == 0 인부분 추가 안하면 시간초과 남
      if (count == 0) {
         year = 0;
         break;
      }
      melt();
      year++;
   }
   cout << year << "\n";
}