/*
    작성자: 김지수
    작성일: 2022/04/19
    백준 -- 뱀 (3190번)
    문제:
*/

#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#define APPLE 1
#define BODY 2
using namespace std;
const int MAX = 101;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int board[MAX][MAX];
int boardSize, appleNum, turnNum;
queue<pair<int, char> > turn;
deque<pair<int, int> > snake;

int changeDir(int dir, char direction) {
   int ret = dir;
   if (direction == 'D') {
      switch (dir) {
         case 0:
            ret = 1;
            break;
         case 1:
            ret = 2;
            break;
         case 2:
            ret = 3;
            break;
         case 3:
            ret = 0;
            break;
      }
   } else {
      switch (dir) {
         case 0:
            ret = 3;
            break;
         case 1:
            ret = 0;
            break;
         case 2:
            ret = 1;
            break;
         case 3:
            ret = 2;
            break;
      }
   }
   return ret;
}

bool move(int dir) {
   bool ret = true;
   pair<int, int> nowHead = snake.front();
   pair<int, int> nowTail = snake.back();
   int nextY = nowHead.first + dy[dir];
   int nextX = nowHead.second + dx[dir];

   if (nextY < 0 || nextY >= boardSize || nextX < 0 || nextX >= boardSize) {
      ret = false;
      return ret;
   }
   if (board[nextY][nextX] == BODY) {
      ret = false;
      return ret;
   } else {
      if (board[nextY][nextX] == APPLE) {
         board[nextY][nextX] = BODY;
         snake.push_front(make_pair(nextY, nextX));
      } else {
         board[nowTail.first][nowTail.second] = 0;
         snake.pop_back();
         snake.push_front(make_pair(nextY, nextX));
         board[nextY][nextX] = BODY;
      }
   }

   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> boardSize;
   cin >> appleNum;
   memset(board, 0, sizeof(board));

   for (int i = 0; i < appleNum; i++) {
      int y, x;
      cin >> y >> x;
      y--;
      x--;

      board[y][x] = APPLE;
   }

   cin >> turnNum;
   for (int i = 0; i < turnNum; i++) {
      int turns;
      char dir;
      cin >> turns >> dir;
      turn.push(make_pair(turns, dir));
   }

   snake.push_back(make_pair(0, 0));
   board[0][0] = BODY;

   int nowDir = 0;
   int seconds = 0;
   while (1) {
      bool notstop = move(nowDir);
      pair<int, char> turnInfo = turn.front();
      if (!notstop) {
         break;
      }
      seconds++;
      if (seconds == turnInfo.first) {
         nowDir = changeDir(nowDir, turnInfo.second);
         turn.pop();
      }
   }
   cout << seconds + 1;
}