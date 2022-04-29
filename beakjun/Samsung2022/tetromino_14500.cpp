/*
    작성자: 김지수
    작성일: 2022/04/29
    백준 -- 테트로미노 (14500번)
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 505
using namespace std;
const char shape[19][4][5] = {
    {"1111", "0000", "0000", "0000"}, {"1000", "1000", "1000", "1000"},
    {"1100", "1100", "0000", "0000"}, {"1000", "1000", "1100", "0000"},
    {"1110", "1000", "0000", "0000"}, {"0100", "0100", "1100", "0000"},
    {"1000", "1110", "0000", "0000"}, {"1100", "0100", "0100", "0000"},
    {"1100", "1000", "1000", "0000"}, {"1110", "0010", "0000", "0000"},
    {"0010", "1110", "0000", "0000"}, {"1000", "1100", "0100", "0000"},
    {"0110", "1100", "0000", "0000"}, {"1100", "0110", "0000", "0000"},
    {"0100", "1100", "1000", "0000"}, {"0100", "1110", "0000", "0000"},
    {"0100", "1100", "0100", "0000"}, {"1110", "0100", "0000", "0000"},
    {"1000", "1100", "1000", "0000"}};

int height, width;
long long ans = 0;
int board[MAX][MAX];

void getAns(int idx, int sy, int sx) {
   long long ret = 0;
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         if (shape[idx][i][j] == '1') {
            ret += board[i + sy][j + sx];
         }
      }
   }
   ans = max(ans, ret);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> height >> width;
   for (int i = 0; i < height + 4; i++) {
      for (int j = 0; j < width + 4; j++) {
         board[i][j] = -1001;
      }
   }
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         int num;
         cin >> num;
         board[i][j] = num;
      }
   }

   for (int i = 0; i < 19; i++) {
      for (int j = 0; j < height; j++) {
         for (int k = 0; k < width; k++) {
            getAns(i, j, k);
         }
      }
   }
   cout << ans;
}