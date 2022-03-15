/*
    작성자: 김지수
    작성일: 2022/03/15
    백준 -- 빙고 (2578번)
    문제:
*/

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 25;
int board[MAX][MAX];

int checkRow(int y) {
   for (int j = 0; j < 5; j++) {
      if (board[y][j] != 0) {
         return 0;
      }
   }
   return 1;
}

int checkCol(int x) {
   for (int i = 0; i < 5; i++) {
      if (board[i][x] != 0) {
         return 0;
      }
   }
   return 1;
}

int checkDiag() {
   int sum = 0;
   if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 &&
       board[3][3] == 0 && board[4][4] == 0) {
      sum++;
   }
   if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 &&
       board[3][1] == 0 && board[4][0] == 0) {
      sum++;
   }
   return sum;
}
int checkBingo() {
   int result = 0;
   for (int i = 0; i < 5; i++) {
      result += checkRow(i);
      result += checkCol(i);
   }
   result += checkDiag();
   return result;
}

pair<int, int> getPosition(int num) {
   pair<int, int> result = make_pair(-1, -1);
   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
         if (board[i][j] == num) {
            result = make_pair(i, j);
            break;
         }
      }
   }
   return result;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
         cin >> board[i][j];
      }
   }

   int count = 0;
   vector<int> nums;
   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
         int num;
         cin >> num;
         nums.push_back(num);
      }
   }
   for (int i = 0; i < nums.size(); i++) {
      pair<int, int> pos = getPosition(nums[i]);
      board[pos.first][pos.second] = 0;
      count++;
      int ans = checkBingo();
      if (ans >= 3) {
         cout << count << endl;
         return 0;
      }
   }
}