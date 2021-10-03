/*
    작성자: 김지수
    작성일: 2021/10/03
    백준 -- 오목(2615번)
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 19;
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int graph[MAX_N][MAX_N];
int ansColor = 0;
vector<pair<int, int> > answer;
vector<pair<int, int> > real;

int proceed(int y, int x, int color, int dir, int count) {
   int nextY = y + dy[dir];
   int nextX = x + dx[dir];
   while (true) {
      if (nextY >= 0 && nextX >= 0 && nextY < MAX_N && nextX < MAX_N) {
         if (graph[nextY][nextX] == color) {
            answer.push_back(make_pair(nextX, nextY));
            nextY += dy[dir];
            nextX += dx[dir];
            count++;
         } else {
            break;
         }
      } else {
         break;
      }
   }
   return count;
}
void check(int y, int x, int color) {
   int tempCount = 0;
   for (int i = 0; i < 8; i++) {
      if (i % 2 == 0) {
         answer.push_back(make_pair(x, y));
      }
      int nextY = y + dy[i];
      int nextX = x + dx[i];
      int count = 1;
      if (nextY < 0 || nextY >= MAX_N || nextX < 0 || nextX >= MAX_N) {
         continue;
      }
      if (graph[nextY][nextX] == color) {
         answer.push_back(make_pair(nextX, nextY));
         tempCount += proceed(nextY, nextX, color, i, count);
      }

      if (i % 2 != 0) {
         if (tempCount == 4) {
            ansColor = color;
            real = answer;
            return;
         }
         answer.clear();
         tempCount = 0;
      }
   }
   return;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   for (int i = 0; i < MAX_N; i++) {
      for (int j = 0; j < MAX_N; j++) {
         cin >> graph[i][j];
      }
   }

   for (int i = 0; i < MAX_N; i++) {
      for (int j = 0; j < MAX_N; j++) {
         if (graph[i][j] != 0) {
            check(i, j, graph[i][j]);
         }
      }
   }
   sort(real.begin(), real.end());
   cout << ansColor << endl;
   if (ansColor > 0) {
      cout << real[0].second + 1 << " " << real[0].first + 1;
   }
}