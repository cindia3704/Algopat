/*
    작성자: 김지수
    작성일: 2021/10/23
    백준 -- 게리멘더링 2 (17779번)
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 22;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {-1, 1, 1, -1};
int n;
int village[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int answer = 987654321;

int getMaxDifference() {
   int peopleSum[5];
   fill(peopleSum, peopleSum + 5, 0);
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         int villageNum = village[i][j];
         int peopleNum = board[i][j];
         if (villageNum == 0) {
            peopleSum[4] += peopleNum;
         } else {
            peopleSum[villageNum - 1] += peopleNum;
         }
      }
   }

   sort(peopleSum, peopleSum + 5);
   int maxNum = peopleSum[4];
   int minNum = peopleSum[0];
   return maxNum - minNum;
}

void fillVillage(int villageNum, int sy, int sx, int ey, int ex) {
   if (villageNum == 1 || villageNum == 2) {
      for (int i = sy; i <= ey; i++) {
         for (int j = sx; j <= ex; j++) {
            if (village[i][j] == 5) {
               break;
            } else {
               village[i][j] = villageNum;
            }
         }
      }
   } else {
      for (int i = sy; i <= ey; i++) {
         for (int j = sx; j >= ex; j--) {
            if (village[i][j] == 5) {
               break;
            } else {
               village[i][j] = villageNum;
            }
         }
      }
   }
}

void makeVillage(int x, int y, int d1, int d2, vector<pair<int, int> > cor) {
   memset(village, 0, sizeof(village));
   for (int i = 0; i < 4; i++) {
      int nowY = cor[i].first;
      int nowX = cor[i].second;
      int destY = y;
      int destX = x;
      int nextY = nowY;
      int nextX = nowX;
      village[nowY][nowX] = 5;

      if (i < 3) {
         destY = cor[i + 1].first;
         destX = cor[i + 1].second;
      }
      while (true) {
         nextY += dy[i];
         nextX += dx[i];
         if (nextY == destY && nextX == destX) {
            break;
         }
         village[nextY][nextX] = 5;
      }
   }

   fillVillage(1, 1, 1, y, x + d1);
   fillVillage(2, y, 1, n, x + d2);
   fillVillage(3, 1, n, y - d1 + d2, x + d1 + 1);
   fillVillage(4, y - d1 + d2 + 1, n, n, x + d2);
   int tempNum = getMaxDifference();
   if (answer > tempNum) {
      answer = tempNum;
   }
   return;
}

void makeCombination() {
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         int maxD1 = i - 1;
         int maxD2 = n - i - 1;
         if (maxD1 < 1 || maxD2 < 1) {
            continue;
         } else {
            for (int d1 = 1; d1 <= maxD1; d1++) {
               for (int d2 = 1; d2 <= maxD2; d2++) {
                  vector<pair<int, int> > coord;
                  bool cant = false;
                  int cor1Y = i - d1;
                  int cor1X = j + d1;
                  int cor2Y = i + d2;
                  int cor2X = j + d2;
                  int cor3Y = i - d1 + d2;
                  int cor3X = j + d1 + d2;
                  if (cor1Y <= 0 || cor1X <= 0 || cor1Y > n || cor1X > n ||
                      cor2Y <= 0 || cor2X <= 0 || cor2Y > n || cor2X > n ||
                      cor3Y <= 0 || cor3X <= 0 || cor3Y > n || cor3X > n) {
                     continue;
                  } else {
                     coord.push_back(make_pair(i, j));
                     coord.push_back(make_pair(cor1Y, cor1X));
                     coord.push_back(make_pair(cor3Y, cor3X));
                     coord.push_back(make_pair(cor2Y, cor2X));
                     makeVillage(j, i, d1, d2, coord);
                  }
                  coord.clear();
               }
            }
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         cin >> board[i][j];
      }
   }
   makeCombination();
   cout << answer;
}
