/*
    작성자: 김지수
    작성일: 2021/09/14
    백준 -- 마법사 상어와 파이어볼 (20056번)
    문제:
*/

#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 50;
struct Fireball {
   int y, x;
   int mass, dir, speed;
};
vector<Fireball> ballList;
vector<Fireball> temp[MAX_N][MAX_N];
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dirEvenOrOdd[4] = {0, 2, 4, 6};
const int dirElse[4] = {1, 3, 5, 7};

void divide(int y, int x) {
   int massSum = 0, speedSum = 0;
   bool allEven = true, allOdd = true;
   for (int i = 0; i < temp[y][x].size(); i++) {
      Fireball b = temp[y][x][i];
      massSum += b.mass;
      speedSum += b.speed;
      if (b.dir % 2 != 0) {
         allOdd = false;
      } else {
         allEven = false;
      }
   }
   for (int i = 0; i < 4; i++) {
      Fireball b;
      b.y = y;
      b.x = x;
      b.mass = massSum / 5;
      b.speed = speedSum / temp[y][x].size();
      if (!allEven && !allOdd) {
         b.dir = dirElse[i];
      } else {
         b.dir = dirEvenOrOdd[i];
      }
      if (b.mass <= 0) {
         continue;
      } else {
         ballList.push_back(b);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int boardSize, ballNum, round;
   cin >> boardSize >> ballNum >> round;
   for (int i = 0; i < ballNum; i++) {
      Fireball b;
      int y, x;
      cin >> y >> x >> b.mass >> b.speed >> b.dir;
      b.y = y - 1;
      b.x = x - 1;
      ballList.push_back(b);
   }
   int roundCount = 0;
   while (roundCount < round) {
      for (int i = 0; i < ballList.size(); i++) {
         Fireball b = ballList[i];
         b.x += dx[b.dir] * b.speed;
         b.y += dy[b.dir] * b.speed;
         if (b.x < 0) {
            b.x = abs(boardSize + (b.x) % boardSize) % boardSize;
         } else {
            b.x = abs(boardSize + b.x) % boardSize;
         }
         if (b.y < 0) {
            b.y = abs(boardSize + (b.y) % boardSize) % boardSize;
         } else {
            b.y = abs(boardSize + b.y) % boardSize;
         }
         temp[b.y][b.x].push_back(b);
      }
      ballList.clear();
      for (int i = 0; i < boardSize; i++) {
         for (int j = 0; j < boardSize; j++) {
            if (temp[i][j].size() > 1) {
               divide(i, j);
            } else if (temp[i][j].size() == 1 && temp[i][j][0].mass > 0) {
               ballList.push_back(temp[i][j][0]);
            }
            temp[i][j].clear();
         }
      }
      roundCount++;
   }
   int sum = 0;
   for (int i = 0; i < ballList.size(); i++) {
      sum += ballList[i].mass;
   }
   cout << sum << endl;
}