/*
    작성자: 김지수
    작성일: 2021/06/30
    백준 -- 음식물 피하기 (1743번)
    문제:
    - 코레스코 콘도미니엄 8층은 학생들이 3끼의 식사를 해결하는 공간이다.
    - 그러나 몇몇 비양심적인 학생들의 만행으로 음식물이 통로 중간 중간에 떨어져
   있다
    - 이러한 음식물들은 근처에 있는 것끼리 뭉치게 돼서 큰 음식물 쓰레기가 된다.
    - 선생님은 떨어진 음식물 중에 제일 큰 음식물만은 피해 가려고 한다.
   - 선생님을 도와 제일 큰 음식물의 크기를 구해서 “10ra"를 외치지 않게 도와주자
*/
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 100;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int row, col, prog;
int answer = -1;

void bfs(int y, int x) {
   queue<pair<int, int> > q;
   q.push(make_pair(y, x));
   visited[y][x] = true;
   int count = 0;
   while (!q.empty()) {
      count++;
      int nowX = q.front().second;
      int nowY = q.front().first;
      q.pop();
      for (int dir = 0; dir < 4; dir++) {
         int nextX = nowX + dx[dir];
         int nextY = nowY + dy[dir];

         if (nextX < 0 || nextY < 0 || nextX >= col || nextY >= row) continue;
         if (graph[nextY][nextX] == 1 && visited[nextY][nextX] == false) {
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = true;
         }
      }
   }
   answer = max(answer, count);
}

int main(void) {
   vector<pair<int, int> > progs;
   memset(graph, 0, sizeof(graph));
   memset(visited, false, sizeof(visited));

   cin >> row >> col >> prog;
   for (int i = 0; i < prog; i++) {
      int y, x;
      cin >> y >> x;
      graph[y - 1][x - 1] = 1;
      progs.push_back(make_pair(y - 1, x - 1));
   }
   for (int i = 0; i < progs.size(); i++) {
      int y = progs[i].first;
      int x = progs[i].second;
      if (visited[y][x] == false) {
         bfs(y, x);
      }
   }
   cout << answer << endl;
}