/*
    작성자: 김지수
    작성일: 2022/04/23
    백준 -- 상어초등학교 (21608번)
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define EMPTY -1

using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
const int MAX = 441;
const int MAXB = 21;
struct SEAT {
   int numFriends;
   int numEmpty;
   int y;
   int x;
};
int boardSize;
int board[MAXB][MAXB];  // EMPTY = -1

vector<int> bf[MAX];  // 각 학생마다 좋아하는 학생
vector<int> seq;      // 자리채우는 순서
vector<SEAT> possibleSeat;

bool cmp(SEAT &a, SEAT &b) {
   if (a.numFriends == b.numFriends) {
      if (a.numEmpty == b.numEmpty) {
         if (a.x == b.x) {
            return a.y < b.y;
         }
         return a.x < b.x;
      }
      return a.numEmpty > b.numEmpty;
   }
   return a.numFriends > b.numFriends;
}
long long getScore() {
   long long ans = 0;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         int now = board[i][j];
         int countFriends = 0;
         for (int dir = 0; dir < 4; dir++) {
            int nextY = i + dy[dir];
            int nextX = j + dx[dir];
            if (nextY < 0 || nextY >= boardSize || nextX < 0 ||
                nextX >= boardSize) {
               continue;
            } else {
               for (int k = 0; k < bf[now].size(); k++) {
                  if (board[nextY][nextX] == bf[now][k]) {
                     countFriends++;
                  }
               }
            }
         }
         if (countFriends == 1) {
            ans += 1;
         } else if (countFriends == 2) {
            ans += 10;
         } else if (countFriends == 3) {
            ans += 100;
         } else if (countFriends == 4) {
            ans += 1000;
         }
      }
   }
   return ans;
}
void getPossibleSeat(int studentNumber) {
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         if (board[i][j] == EMPTY) {
            SEAT now;
            now.y = i;
            now.x = j;
            now.numFriends = 0;
            now.numEmpty = 0;
            for (int dir = 0; dir < 4; dir++) {
               int nextY = i + dy[dir];
               int nextX = j + dx[dir];
               if (nextY < 0 || nextY >= boardSize || nextX < 0 ||
                   nextX >= boardSize) {
                  continue;
               } else {
                  if (board[nextY][nextX] == EMPTY) {
                     now.numEmpty++;
                  } else {
                     for (int k = 0; k < bf[studentNumber].size(); k++) {
                        if (board[nextY][nextX] == bf[studentNumber][k]) {
                           now.numFriends++;
                        }
                     }
                  }
               }
            }
            possibleSeat.push_back(now);
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> boardSize;
   for (int i = 0; i < boardSize * boardSize; i++) {
      int student;
      cin >> student;
      seq.push_back(student);
      for (int j = 0; j < 4; j++) {
         int friendNum;
         cin >> friendNum;
         bf[student].push_back(friendNum);
      }
   }
   memset(board, EMPTY, sizeof(board));
   for (int i = 0; i < seq.size(); i++) {
      int nowStudent = seq[i];
      // cout << "\n=== i:" << i << "  nowStudent#:" << nowStudent << endl;
      getPossibleSeat(nowStudent);
      // cout << "Possible SEat:" << possibleSeat.size() << endl;
      sort(possibleSeat.begin(), possibleSeat.end(), cmp);
      board[possibleSeat[0].y][possibleSeat[0].x] = nowStudent;
      //   cout << "y:" << possibleSeat[0].y << "  x:" << possibleSeat[0].x
      //        << "  student:" << nowStudent << endl;
      possibleSeat.clear();
   }
   cout << endl;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
   // cout << endl;
   cout << getScore();
}