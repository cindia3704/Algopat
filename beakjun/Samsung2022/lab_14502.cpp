/*
    작성자: 김지수
    작성일: 2022/03/28
    백준 -- 연구소
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
// NESW 방향
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
const int MAX = 9;
// 보드 크기
int boardH, boardW;
int board[MAX][MAX];
bool visited[MAX][MAX];
// 정답 저장할 변수
int maxSafeArea = -1;

void dfs() {
   memset(visited, false, sizeof(visited));
   queue<pair<int, int> > q;
   int temp[boardH][boardW];
   // 현재 보드 복사 후, 바이러스 구간 큐에 넣기
   for (int i = 0; i < boardH; i++) {
      for (int j = 0; j < boardW; j++) {
         temp[i][j] = board[i][j];
         if (board[i][j] == 2) {
            q.push(make_pair(i, j));
            visited[i][j] = true;
         }
      }
   }

   // 상하좌우 돌면서 바이러스 퍼트리기! (이때 복사본 보드에 바이러스 2로 표시)
   while (!q.empty()) {
      int nowY = q.front().first;
      int nowX = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nextY = nowY + dy[i];
         int nextX = nowX + dx[i];
         if (nextY < 0 || nextY >= boardH || nextX < 0 || nextX >= boardW) {
            continue;
         }
         if (temp[nextY][nextX] == 0 && !visited[nextY][nextX]) {
            visited[nextY][nextX] = true;
            temp[nextY][nextX] = 2;
            q.push(make_pair(nextY, nextX));
         }
      }
   }

   // 복사본에서 안전구역 개수 세기
   int countSafe = 0;
   for (int i = 0; i < boardH; i++) {
      for (int j = 0; j < boardW; j++) {
         if (temp[i][j] == 0) {
            countSafe++;
         }
      }
   }
   maxSafeArea = max(maxSafeArea, countSafe);
   return;
}

void combination(int y, int x, int count) {
   if (count == 3) {
      // 벽 3개 골랐으면 바이러스 퍼트리고 안전구간 세기
      dfs();
      return;
   } else {
      // 현재 위치보다 뒤에있는 위치만 보면됨! (주의!!! x는 한번 돌면 0으로
      // 초기화!)
      for (int i = y; i < boardH; i++) {
         for (int j = x; j < boardW; j++) {
            if (board[i][j] == 0) {
               // 백트렉킹!
               board[i][j] = 1;  // 벽 세우고
               combination(i, j, count + 1);
               board[i][j] = 0;  // 벽 없애고
            }
         }
         x = 0;
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> boardH >> boardW;

   // 보드 입력 받음
   for (int i = 0; i < boardH; i++) {
      for (int j = 0; j < boardW; j++) {
         cin >> board[i][j];
      }
   }

   // 벽이 3개 -> 0인것중 3개를 고르자 (combination)
   combination(0, 0, 0);

   cout << maxSafeArea;
}