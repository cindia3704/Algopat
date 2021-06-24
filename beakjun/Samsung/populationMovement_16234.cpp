/*
    작성자: 김지수
    작성일: 2021/06/25
    백준 -- 인구 이동 (16234번)
    문제:
    - N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다.
    - 인접한 나라 사이에는 국경선이 존재한다.
    - 인구 이동은 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이
    없을 때까지 지속된다:
        - 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두
        나라가 공유하는 국경선을 오늘 하루동안 연다.
        - 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을
        시작한다
        - 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를
         오늘 하루 동안은 연합이라고 한다
        - 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고
        있는 칸의 개수)가 된다. 편의상 소수점은 버린다
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 50;
const int MAX_LIMIT = 100;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int flag = 0;
int answer = 0;

void movement(int n, int l, int r, int y, int x) {
   int ans = 0;
   queue<pair<int, int> > q;      // bfs에 필요
   vector<pair<int, int> > temp;  // 인구이동 있을 시 계산위해 필요
   q.push(make_pair(y, x));
   temp.push_back(make_pair(y, x));
   ans += graph[y][x];
   visited[y][x] = true;

   while (!q.empty()) {
      int nowX = q.front().second;
      int nowY = q.front().first;
      int nowVal = graph[nowY][nowX];

      q.pop();

      for (int dir = 0; dir < 4; dir++) {
         int nextX = nowX + dx[dir];
         int nextY = nowY + dy[dir];

         if (nextX > -1 && nextX < n && nextY > -1 && nextY < n &&
             visited[nextY][nextX] == false) {
            int nextVal = graph[nextY][nextX];
            int diff = abs(nowVal - nextVal);

            if (diff >= l && diff <= r) {
               temp.push_back(make_pair(nextY, nextX));
               ans += nextVal;
               q.push(make_pair(nextY, nextX));
               flag = 1;  // 인구이동 찾음
               visited[nextY][nextX] = true;
            }
         }
      }
   }

   if (temp.size() > 1) {
      int newVal = ans / temp.size();
      for (int i = 0; i < temp.size(); i++) {
         graph[temp[i].first][temp[i].second] = newVal;
      }
   }
}

int main(void) {
   int n, l, r;
   cin >> n >> l >> r;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> graph[i][j];
      }
   }

   while (1) {
      // 초기상태 = 인구이동 아직 못찾음 + 아무 곳도 방문 안함
      flag = 0;
      memset(visited, false, sizeof(visited));

      // bfs로 방문 안한 곳 다 방문하며 인구이동 확인
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (visited[i][j] == false) {
               movement(n, l, r, i, j);
            }
         }
      }

      if (flag == 1) {  // 인구 이동을 찾음
         answer++;
      } else {  // 인구 이동 못찾음 --> 종료!
         cout << answer << endl;
         return 0;
      }
   }
}