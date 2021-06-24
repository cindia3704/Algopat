/*
    작성자: 김지수
    작성일: 2021/06/25
    백준 -- 안전 영역 (2468번)
    문제:
    - 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가
   만들어 지는 지를 조사하려고 한다
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 100;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int area[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void findNumOfSafeArea(int y, int x, int maxHeight, int n) {
   queue<pair<int, int> > q;
   q.push(make_pair(y, x));
   visited[y][x] = true;
   while (!q.empty()) {
      int nowX = q.front().second;
      int nowY = q.front().first;
      q.pop();
      for (int dir = 0; dir < 4; dir++) {
         int nextX = nowX + dx[dir];
         int nextY = nowY + dy[dir];
         if (nextX > -1 && nextX < n && nextY > -1 && nextY < n &&
             visited[nextY][nextX] == false && area[nextY][nextX] > maxHeight) {
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = true;
         }
      }
   }
}

int main(void) {
   int n;
   int maxNum = -1;
   int answer = 0;
   cin >> n;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         int num;
         cin >> num;
         maxNum = max(maxNum, num);
         area[i][j] = num;
      }
   }

   for (int i = 0; i <= maxNum; i++) {
      memset(visited, false, sizeof(visited));
      int temp = 0;
      for (int j = 0; j < n; j++) {
         for (int k = 0; k < n; k++) {
            if (visited[j][k] == false && area[j][k] > i) {
               findNumOfSafeArea(j, k, i, n);
               temp++;
            }
         }
         answer = max(answer, temp);
      }
   }
   cout << answer << endl;
}