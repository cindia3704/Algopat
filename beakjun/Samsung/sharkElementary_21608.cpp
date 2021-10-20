/*
    작성자: 김지수
    작성일: 2021/10/20
    백준 -- 상어초등학교 (21608번)
    문제:
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 21;
const int MAX_STUDENT = 441;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int board[MAX_N][MAX_N];
vector<int> bestfriends[MAX_STUDENT];
vector<int> studentNum;
int N;

int getEmptySpaces(int y, int x) {
   int count = 0;
   if (board[y][x] == 0) {
      for (int dir = 0; dir < 4; dir++) {
         int nextY = y + dy[dir];
         int nextX = x + dx[dir];
         if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N) {
            continue;
         }
         if (board[nextY][nextX] == 0) {
            count++;
         }
      }
   }
   return count;
}

pair<int, int> getMostFriendSpot(int myNum) {
   int y = -1;
   int x = -1;
   int count = -1;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         int tempCount = 0;
         for (int dir = 0; dir < 4; dir++) {
            int nextY = i + dy[dir];
            int nextX = j + dx[dir];
            if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N) {
               continue;
            }
            for (int k = 0; k < 4; k++) {
               if (board[nextY][nextX] == bestfriends[myNum][k]) {
                  tempCount++;
                  break;
               }
            }
         }
         if (tempCount > count && (board[i][j] == 0)) {
            y = i;
            x = j;
            count = tempCount;
         } else if (tempCount == count && (board[i][j] == 0)) {
            int prevCount = getEmptySpaces(y, x);
            int nowCount = getEmptySpaces(i, j);
            if (nowCount > prevCount) {
               y = i;
               x = j;
            }
         }
      }
   }
   return make_pair(y, x);
}

int calculateScore() {
   int score = 0;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         int now = board[i][j];
         int count = 0;
         for (int dir = 0; dir < 4; dir++) {
            int nextY = i + dy[dir];
            int nextX = j + dx[dir];
            if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N) {
               continue;
            }
            for (int k = 0; k < 4; k++) {
               if (bestfriends[now][k] == board[nextY][nextX]) {
                  count++;
                  break;
               }
            }
         }
         if (count == 1) {
            score += 1;
         } else if (count == 2) {
            score += 10;
         } else if (count == 3) {
            score += 100;
         } else if (count == 4) {
            score += 1000;
         }
      }
   }
   return score;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(board, 0, sizeof(board));
   cin >> N;
   for (int i = 0; i < pow(N, 2); i++) {
      int nowNum;
      cin >> nowNum;
      studentNum.push_back(nowNum);
      for (int j = 0; j < 4; j++) {
         int friendNum;
         cin >> friendNum;
         bestfriends[nowNum].push_back(friendNum);
      }
   }

   for (int i = 0; i < pow(N, 2); i++) {
      pair<int, int> p = getMostFriendSpot(studentNum[i]);
      board[p.first][p.second] = studentNum[i];
   }
   cout << calculateScore();
}