/*
    작성자: 김지수
    작성일: 2021/06/25
    백준 -- 적록색약 (10026번)
    문제:
    - 적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다
    -크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한
   그림이 있다.
   - 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다
    - 그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을
   때 구역의 수를 구하는 프로그램을 작성하시오.
*/

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
char picture[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void bfs(int n, int y, int x, int flag) {
   queue<pair<int, int> > q;
   q.push(make_pair(y, x));
   visited[y][x] = true;
   char nowColor = picture[y][x];

   while (!q.empty()) {
      int nowX = q.front().second;
      int nowY = q.front().first;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nextX = nowX + dx[i];
         int nextY = nowY + dy[i];
         switch (flag) {
            case 0:
               if (nextX > -1 && nextY > -1 && nextX < n && nextY < n &&
                   visited[nextY][nextX] == false &&
                   picture[nextY][nextX] == nowColor) {
                  q.push(make_pair(nextY, nextX));
                  visited[nextY][nextX] = true;
               }
               break;

            default:
               if (nextX > -1 && nextY > -1 && nextX < n && nextY < n &&
                   visited[nextY][nextX] == false) {
                  if (nowColor == 'R' || nowColor == 'G') {
                     if (picture[nextY][nextX] == 'R' ||
                         picture[nextY][nextX] == 'G') {
                        q.push(make_pair(nextY, nextX));
                        visited[nextY][nextX] = true;
                     }
                  } else {
                     if (picture[nextY][nextX] == nowColor) {
                        q.push(make_pair(nextY, nextX));
                        visited[nextY][nextX] = true;
                     }
                  }
               }
               break;
         }
      }
   }
}

int main(void) {
   int n;
   int nonBlind = 0;
   int blind = 0;
   cin >> n;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> picture[i][j];
      }
   }
   memset(visited, false, sizeof(visited));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (visited[i][j] == false) {
            bfs(n, i, j, 0);
            nonBlind++;
         }
      }
   }
   memset(visited, false, sizeof(visited));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (visited[i][j] == false) {
            bfs(n, i, j, 1);
            blind++;
         }
      }
   }
   cout << nonBlind << " " << blind << endl;
}
