/*
    작성자: 김지수
    작성일: 2021/10/05
    백준 -- 킹 (1063번)
    문제:
*/
#include <iostream>
#include <vector>
using namespace std;
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
vector<int> commands;
pair<int, int> finalPosK;
pair<int, int> finalPosR;

void move(int ky, int kx, int ry, int rx) {
   int nowKy = ky;
   int nowKx = kx;
   int nowRy = ry;
   int nowRx = rx;
   for (int i = 0; i < commands.size(); i++) {
      int nextKy = nowKy + dy[commands[i]];
      int nextKx = nowKx + dx[commands[i]];
      int nextRx = nowRx;
      int nextRy = nowRy;
      if (nextKy == nextRy && nextKx == nextRx) {
         nextRx += dx[commands[i]];
         nextRy += dy[commands[i]];
      }
      if (nextKy < 0 || nextKy >= 8 || nextKx < 0 || nextKx >= 8 ||
          nextRy < 0 || nextRy >= 8 || nextRx < 0 || nextRx >= 8) {
         continue;
      } else {
         nowKx = nextKx;
         nowKy = nextKy;
         nowRx = nextRx;
         nowRy = nextRy;
      }
   }
   finalPosK = make_pair(nowKx, nowKy);
   finalPosR = make_pair(nowRx, nowRy);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string kingPos, rockPos;
   int numCommand;
   cin >> kingPos >> rockPos >> numCommand;

   pair<int, int> positionK, positionR;
   positionK = make_pair(kingPos[0] - 'A', kingPos[1] - '1');
   positionR = make_pair(rockPos[0] - 'A', rockPos[1] - '1');

   for (int i = 0; i < numCommand; i++) {
      string command;
      cin >> command;
      int dir;
      if (command == "T") {
         dir = 0;
      } else if (command == "B") {
         dir = 1;
      } else if (command == "R") {
         dir = 2;
      } else if (command == "L") {
         dir = 3;
      } else if (command == "RT") {
         dir = 4;
      } else if (command == "RB") {
         dir = 5;
      } else if (command == "LB") {
         dir = 6;
      } else {
         dir = 7;
      }
      commands.push_back(dir);
   }

   move(positionK.second, positionK.first, positionR.second, positionR.first);

   cout << char(finalPosK.first + 'A') << char(finalPosK.second + '1') << '\n';
   cout << char(finalPosR.first + 'A') << char(finalPosR.second + '1') << '\n';
}