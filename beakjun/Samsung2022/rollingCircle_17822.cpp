/*
    작성자: 김지수
    작성일: 2022/04/26
    백준 -- 원판 돌리기 (17822번)
    문제:
*/

#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
#define MAX 52

using namespace std;
struct TURN {
   int circleNum;
   int dir;
   int laps;
};
deque<int> circle[MAX];
int totalCircle, numberCount, totalTurn;
vector<TURN> turnInfo;
vector<pair<int, int> > v;

int findAdj(int y, int x, int num) {
   int count = 0;
   if (y == totalCircle) {
      if (circle[y - 1][x] == num) {
         count++;
         v.push_back(make_pair(y - 1, x));
      }
   } else if (y == 1) {
      if (circle[y + 1][x] == num) {
         count++;
         v.push_back(make_pair(y + 1, x));
      }
   } else {
      if (circle[y + 1][x] == num) {
         count++;
         v.push_back(make_pair(y + 1, x));
      }
      if (circle[y - 1][x] == num) {
         count++;
         v.push_back(make_pair(y - 1, x));
      }
   }

   if (x == 0) {
      if (circle[y][x + 1] == num) {
         count++;
         v.push_back(make_pair(y, x + 1));
      }
      if (circle[y][numberCount - 1] == num) {
         count++;
         v.push_back(make_pair(y, numberCount - 1));
      }
   } else if (x == numberCount - 1) {
      if (circle[y][x - 1] == num) {
         count++;
         v.push_back(make_pair(y, x - 1));
      }
      if (circle[y][0] == num) {
         count++;
         v.push_back(make_pair(y, 0));
      }
   } else {
      if (circle[y][x - 1] == num) {
         count++;
         v.push_back(make_pair(y, x - 1));
      }
      if (circle[y][x + 1] == num) {
         count++;
         v.push_back(make_pair(y, x + 1));
      }
   }
   if (count > 0) {
      v.push_back(make_pair(y, x));
      count++;
   }
   return count;
}

double getAvg() {
   double sum = 0.0;
   int count = 0;
   for (int i = 1; i <= totalCircle; i++) {
      for (int j = 0; j < numberCount; j++) {
         if (circle[i][j] != -1) {
            count++;
            sum += circle[i][j];
         }
      }
   }
   double avg = (sum / count);

   return avg;
}

void noAdj() {
   double avg = getAvg();

   for (int i = 1; i <= totalCircle; i++) {
      for (int j = 0; j < numberCount; j++) {
         if (circle[i][j] != -1) {
            if (circle[i][j] < avg) {
               circle[i][j] += 1;
            } else if (circle[i][j] > avg) {
               circle[i][j] -= 1;
            }
         }
      }
   }
}

void turnCircle(int turns, int seq, int circleNum) {
   if (turns == 0) {
      for (int i = 0; i < seq; i++) {
         int temp = circle[circleNum].back();
         circle[circleNum].pop_back();
         circle[circleNum].push_front(temp);
      }
   } else {
      for (int i = 0; i < seq; i++) {
         int temp = circle[circleNum].front();
         circle[circleNum].pop_front();
         circle[circleNum].push_back(temp);
      }
   }
}

long long getTotalSum() {
   int ret = 0;
   for (int i = 1; i <= totalCircle; i++) {
      for (int j = 0; j < numberCount; j++) {
         if (circle[i][j] != -1) {
            ret += circle[i][j];
         }
      }
   }
   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> totalCircle >> numberCount >> totalTurn;
   for (int i = 1; i <= totalCircle; i++) {
      for (int j = 0; j < numberCount; j++) {
         int num;
         cin >> num;
         circle[i].push_back(num);
      }
   }
   for (int i = 0; i < totalTurn; i++) {
      TURN now;
      cin >> now.circleNum >> now.dir >> now.laps;
      turnInfo.push_back(now);
   }

   for (int i = 0; i < totalTurn; i++) {
      int countSum = 0;
      TURN now = turnInfo[i];
      for (int j = 1; j <= totalCircle; j++) {
         if (j % now.circleNum == 0) {
            turnCircle(now.dir, now.laps, j);
         }
      }
      for (int k = 1; k <= totalCircle; k++) {
         for (int t = 0; t < numberCount; t++) {
            if (circle[k][t] != -1) {
               countSum += findAdj(k, t, circle[k].at(t));
            }
         }
      }
      for (int i = 0; i < v.size(); i++) {
         circle[v[i].first][v[i].second] = -1;
      }

      if (countSum == 0) {
         noAdj();
      }
   }
   cout << getTotalSum();
}