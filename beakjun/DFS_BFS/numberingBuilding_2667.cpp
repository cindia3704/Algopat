/*
    작성자: 김지수
    작성일: 2022/03/06
    백준 -- 단지번호붙이기 (2667번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 25;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};
char board[MAX][MAX];
bool visited[MAX][MAX];
int boardSize;
vector<int> ans;

void bfs(int y, int x) {
   int count = 0;
   queue<pair<int, int> > q;
   q.push(make_pair(y, x));
   visited[y][x] = true;
   while (!q.empty()) {
      count++;
      int nowY = q.front().first;
      int nowX = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nextY = nowY + dy[i];
         int nextX = nowX + dx[i];
         if (nextY < 0 || nextX < 0 || nextY >= boardSize ||
             nextX >= boardSize) {
            continue;
         } else {
            if (!visited[nextY][nextX] && board[nextY][nextX] == '1') {
               visited[nextY][nextX] = true;
               q.push(make_pair(nextY, nextX));
            }
         }
      }
   }
   ans.push_back(count);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> boardSize;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         cin >> board[i][j];
      }
   }

   memset(visited, false, sizeof(visited));
   int count = 0;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         if (board[i][j] == '1' && visited[i][j] == false) {
            count++;
            bfs(i, j);
         }
      }
   }
   sort(ans.begin(), ans.end());
   cout << count << '\n';
   for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << '\n';
   }
}