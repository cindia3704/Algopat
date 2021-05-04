/*
    작성자: 김지수
    작성일: 2021/05/04
    백준 -- 토마토 (7576번)
    문제:
    - 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은
   토마토들은 익은 토마토의 영향을 받아 익게 된다.
    - 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를
   의미한다.
   - 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로
   익는 경우는 없다고 가정한다.
   - 철수는 창고에 보관된 토마토들이 며칠이 지나면 다
   익게 되는지, 그 최소 일수를 알고 싶어 한다.
   -정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지
   않은 칸을 나타낸다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int MAX_SIZE = 1000;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
bool visited[MAX_SIZE][MAX_SIZE];
int tomato[MAX_SIZE][MAX_SIZE];
int width, height;
struct Tomato {
   int x, y;
   int day;
};
queue<Tomato> q;
int ans = -1;

void getDaysForTomato() {
   while (!q.empty()) {
      Tomato now = q.front();
      int nowX = now.x;
      int nowY = now.y;
      int nowDay = now.day;
      ans = max(ans, nowDay);
      q.pop();

      for (int dir = 0; dir < 4; dir++) {
         Tomato next;
         next.x = nowX + dx[dir];
         next.y = nowY + dy[dir];
         next.day = nowDay + 1;

         if (next.x >= 0 && next.x < width && next.y >= 0 && next.y < height) {
            if (tomato[next.y][next.x] == 0 && !visited[next.y][next.x]) {
               q.push(next);
               visited[next.y][next.x] = true;
            }
         }
      }
   }
}

int main(void) {
   memset(visited, false, sizeof(visited));
   cin >> width >> height;

   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> tomato[i][j];

         if (tomato[i][j] == 1) {
            Tomato start;
            start.y = i;
            start.x = j;
            start.day = 0;
            visited[i][j] = true;

            q.push(start);
         }
      }
   }

   getDaysForTomato();

   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (!visited[i][j] && tomato[i][j] == 0) {
            ans = -1;
         }
      }
   }
   cout << ans << endl;
}