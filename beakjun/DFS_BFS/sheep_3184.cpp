/*
    작성자: 김지수
    작성일: 2021/06/23
    백준 -- 양 (3184번)
    문제:
    - 마당은 행과 열로 이루어진 직사각형 모양이다. 글자 '.' (점)은 빈 필드를
   의미하며, 글자 '#'는 울타리를, 'o'는 양, 'v'는 늑대를 의미한다.
   - 한 칸에서 수평, 수직만으로 이동하며 울타리를 지나지 않고 다른 칸으로 이동할
   수 있다면, 두 칸은 같은 영역 안에 속해 있다고 한다. 마당에서 "탈출"할 수 있는
   칸은 어떤 영역에도 속하지 않는다고 간주한다.
   - 다행히 우리의 양은 늑대에게 싸움을 걸 수 있고 영역 안의 양의 수가 늑대의
    수보다 많다면 이기고, 늑대를 우리에서 쫓아낸다. 그렇지 않다면 늑대가 그 지역
    안의 모든 양을 먹는다.
    - 맨 처음 모든 양과 늑대는 마당 안 영역에 존재한다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
// 동서남북 방향
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int MAX_N = 250;
// 처음 위치 그래프
char graph[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

// 최종 결과 (늑대 & 양 수)
int ansV = 0;
int ansO = 0;

void bfs(int x, int y) {
   queue<pair<int, int> > q;
   // 현재 영역에서 양 & 늑대 수
   int posV = 0;
   int posO = 0;

   q.push(make_pair(y, x));
   visited[y][x] = 1;
   while (!q.empty()) {
      int nowX = q.front().second;
      int nowY = q.front().first;
      char nowC = graph[nowY][nowX];
      // 양 or 늑대에 따라 현재 영역 수 증가!
      if (nowC == 'v') {
         posV++;
      }
      if (nowC == 'o') {
         posO++;
      }
      q.pop();

      // 동서남북으로 돌며 #이 아닌경우 계속 큐에 추가해서 bfs 진행
      for (int dir = 0; dir < 4; dir++) {
         int nextX = nowX + dx[dir];
         int nextY = nowY + dy[dir];
         char nextC = graph[nextY][nextX];

         if (nextC != '#' && visited[nextY][nextX] == 0) {
            visited[nextY][nextX] = 1;
            q.push(make_pair(nextY, nextX));
         }
      }
   }

   // 양의 수가 늑대보다 많은 경우 양이 늑대를 물리침 ( 최종 양수에 현재 영역
   // 양수 추가)
   if (posO > posV) {
      ansO += posO;
   } else {
      ansV += posV;
   }
}

int main(void) {
   int row, col;
   cin >> row >> col;
   memset(visited, 0, sizeof(visited));

   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         cin >> graph[i][j];
      }
   }

   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         // 늑대가 없는 경우도 생각해야하기 때문에 o일때도 bfs 보냄
         if ((graph[i][j] == 'v' || graph[i][j] == 'o') && visited[i][j] != 1) {
            bfs(j, i);
         }
      }
   }

   cout << ansO << " " << ansV << endl;
}