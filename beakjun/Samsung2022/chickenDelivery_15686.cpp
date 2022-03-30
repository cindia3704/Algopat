/*
    작성자: 김지수
    작성일: 2022/03/30
    백준 -- 치킨 배달
    문제:
*/

#include <math.h>

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 51;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int boardSize, maxChickenStoreNum;
int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];

int minDistance = 987654321;
struct House {
   int y, x, distance;
};

int calcDist(int sy, int sx, int ey, int ex) {
   return abs(sy - ey) + abs(sx - ex);
}

void findMinDist() {
   vector<pair<int, int> > chickenStore;
   vector<pair<int, int> > house;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         if (board[i][j] == 1) {
            house.push_back(make_pair(i, j));
         } else if (board[i][j] == 3) {
            chickenStore.push_back(make_pair(i, j));
         }
      }
   }

   int distNow = 0;
   for (int i = 0; i < house.size(); i++) {
      int minDistaceNow = 987654321;
      for (int j = 0; j < chickenStore.size(); j++) {
         int tempDist = calcDist(chickenStore[j].first, chickenStore[j].second,
                                 house[i].first, house[i].second);
         minDistaceNow = min(minDistaceNow, tempDist);
      }
      distNow += minDistaceNow;
   }

   minDistance = min(minDistance, distNow);
}

void getCombination(int sy, int sx, int count) {
   if (count == maxChickenStoreNum) {
      findMinDist();
      return;
   } else {
      for (int i = sy; i < boardSize; i++) {
         for (int j = sx; j < boardSize; j++) {
            if (board[i][j] == 2) {
               board[i][j] = 3;
               getCombination(i, j, count + 1);
               board[i][j] = 2;
            }
         }
         sx = 0;
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> boardSize >> maxChickenStoreNum;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         cin >> board[i][j];
      }
   }

   getCombination(0, 0, 0);
   cout << minDistance;
}