/*
    작성자: 김지수
    작성일: 2021/08/11
    백준 -- 아기 상어 (16236번)
    문제:
    - 최대 20x20크기 공간에 물고기 M마리와 아기 상어 1마리가 있다
    - 가장 처음에 아기 상어의 크기 = 2
    - 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다
    - 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없다
    - 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다
    - 아기 상어가 어디로 이동할지 결정하는 방법:
        - 더 이상 먹을 수 있는 물고기가 공간에 없다-> 엄마 상어 도움 요청
        - 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다
        - 먹을 수 있는 물고기가 1마리보다 많다-> 거리가 가장 가까운 물고기 먹음
            - 가까운 물고기 많음 -> 가장 위에 있는 물고기 -> 가장 왼쪽 물고기
    - 물고기 먹으면 빈칸 됨
    - 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가
    - 몇 초 동안 엄마 상어 도움 요청하지 않고 물고기를 잡아먹을 수 있는지 구하라
*/

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 20;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct SHARK {
   int x, y, time;
};
int sea[MAX_N][MAX_N];
SHARK shark;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> sea[i][j];
         if (sea[i][j] == 9) {
            shark.y = i;
            shark.x = j;
            shark.time = 0;
            sea[i][j] = 0;  // 일반 보드로 바꿈
         }
      }
   }

   bool canEat = true;
   int sharkSize = 2;
   int eatCount = 0;
   while (canEat) {
      canEat = false;
      queue<SHARK> q;
      q.push(shark);
      bool visited[MAX_N][MAX_N];
      memset(visited, false, sizeof(visited));
      visited[shark.y][shark.x] = true;

      SHARK meat;
      meat.x = MAX_N;
      meat.y = MAX_N;
      meat.time = -1;

      while (!q.empty()) {
         SHARK now = q.front();
         q.pop();

         if (meat.time != -1 && meat.time < now.time) {
            // 현재 시간 이전에 먹을 수 있는 물고기 있었음
            break;
         }
         if (sea[now.y][now.x] < sharkSize && sea[now.y][now.x] != 0) {
            //먹을 수 있는 물고기 존재
            canEat = true;
            if (meat.y > now.y || (meat.y == now.y && meat.x > now.x)) {
               // 이전 물고기가 현 물고기 보다 아래 있거나 오른쪽에 있을때
               // 업데이트
               meat = now;
            }
         }
         for (int dir = 0; dir < 4; dir++) {
            SHARK next;
            next.y = now.y + dy[dir];
            next.x = now.x + dx[dir];
            next.time = now.time + 1;
            if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
               continue;
            }

            if (!visited[next.y][next.x] && sea[next.y][next.x] <= sharkSize) {
               // 아직 방문 X, 현재 상어 크기보다 작거나 같은때 그 칸 갈수
               visited[next.y][next.x] = true;
               q.push(next);
            }
         }
      }
      if (canEat) {
         eatCount++;
         if (eatCount == sharkSize) {
            sharkSize++;
            eatCount = 0;
         }
         sea[meat.y][meat.x] = 0;  // 상어가 먹으면 비어있게 바꿈
         shark = meat;             // 먹은 위치 부터 다시 시작
      }
   }
   cout << shark.time;
}