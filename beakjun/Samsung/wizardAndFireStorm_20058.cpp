/*
    작성자: 김지수
    작성일: 2021/10/17
    백준 -- 마법사 상어와 파이어스톰 (15684번)
    문제:
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 65;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int boardSize, rounds;
int totalSize;
vector<int> stages;
int board[MAX_N][MAX_N];
int stageTemp[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int maxIce = 0;

// 얼음양 감소시킬지 결정
void checkIce(int y, int x) {
   int iceCount = 0;
   for (int i = 0; i < 4; i++) {
      int nextY = y + dy[i];
      int nextX = x + dx[i];
      if (nextY < 0 || nextX < 0 || nextX >= totalSize || nextY >= totalSize) {
         continue;
      } else {
         if (board[nextY][nextX] > 0) {
            iceCount++;
         }
      }
   }
   stageTemp[y][x] = board[y][x];

   if (iceCount < 3) {
      if (board[y][x] > 0) {
         stageTemp[y][x] = board[y][x] - 1;
      }
   }

   return;
}

// 90도 회전하기
void rotate(int y, int x, int sizes) {
   int temp[sizes][sizes];
   for (int i = 0; i < sizes; i++) {
      for (int j = 0; j < sizes; j++) {
         temp[i][j] = board[i + y][j + x];
      }
   }

   int ans[sizes][sizes];
   for (int i = 0; i < sizes; i++) {
      for (int j = 0; j < sizes; j++) {
         ans[i][j] = temp[sizes - 1 - j][i];
      }
   }

   for (int i = 0; i < sizes; i++) {
      for (int j = 0; j < sizes; j++) {
         board[i + y][j + x] = ans[i][j];
      }
   }
}

// 스테이지 수행 (2^stagenum 만큼 보드 잘라서 회전 후 3개 이상의 얼음과 인접하지
// 않으면 얼음양 감소 )
void firestorm(int roundNum) {
   int subSize = pow(2, roundNum);
   for (int i = 0; i < totalSize; i++) {
      for (int j = 0; j < totalSize; j++) {
         if (j % subSize == 0 && i % subSize == 0) {
            rotate(i, j, subSize);
         }
      }
   }

   for (int i = 0; i < totalSize; i++) {
      for (int j = 0; j < totalSize; j++) {
         checkIce(i, j);
      }
   }
   for (int i = 0; i < totalSize; i++) {
      for (int j = 0; j < totalSize; j++) {
         board[i][j] = stageTemp[i][j];
      }
   }
}

// 모든 칸의 얼음 양 합 구하기
int calcIceAmount() {
   int sum = 0;
   for (int i = 0; i < totalSize; i++) {
      for (int j = 0; j < totalSize; j++) {
         if (board[i][j] > 0) {
            sum += board[i][j];
         }
      }
   }
   return sum;
}

// 가장 큰 얼음덩어리 구하기
void bfs(int y, int x) {
   queue<pair<int, int> > q;
   visited[y][x] = 1;
   q.push(make_pair(y, x));
   int count = 0;
   while (!q.empty()) {
      int nowY = q.front().first;
      int nowX = q.front().second;
      count++;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nextY = nowY + dy[i];
         int nextX = nowX + dx[i];
         if (nextY < 0 || nextX < 0 || nextX >= totalSize ||
             nextY >= totalSize) {
            continue;
         } else {
            if (board[nextY][nextX] > 0 && visited[nextY][nextX] == 0) {
               visited[nextY][nextX] = 1;
               q.push(make_pair(nextY, nextX));
            }
         }
      }
   }
   if (count > maxIce) {
      maxIce = count;
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> boardSize >> rounds;
   // 보드 사이즈 계산 (2^N)
   totalSize = pow(2, boardSize);
   for (int i = 0; i < totalSize; i++) {
      for (int j = 0; j < totalSize; j++) {
         cin >> board[i][j];
      }
   }
   // stage 수행해야하는거 목록 받음
   for (int i = 0; i < rounds; i++) {
      int num;
      cin >> num;
      stages.push_back(num);
   }
   // 모든 스테이지 수행
   for (int i = 0; i < rounds; i++) {
      firestorm(stages[i]);
   }
   // 답 계산
   memset(visited, 0, sizeof(visited));
   for (int i = 0; i < totalSize; i++) {
      for (int j = 0; j < totalSize; j++) {
         if (board[i][j] > 0 && visited[i][j] == 0) {
            bfs(i, j);
         }
      }
   }
   cout << calcIceAmount() << '\n';
   cout << maxIce;
}