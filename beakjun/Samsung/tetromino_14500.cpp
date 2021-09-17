/*
    작성자: 김지수
    작성일: 2021/09/17
    백준 -- 테트로미노 (14500번)
    문제:
    - N*M 칸에 숫자 적혀 있음
    - 5가지의 테트로미노 있을때 이를 보드에 올려 겹치는 칸의 최대 합
    - 테트로미노 뒤집 or 회전 가능
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// 503인 이유? => 가장 작은 length = 1
const int MAX_N = 503;
int board[MAX_N][MAX_N];
// 1:2개, 2:1개, 3:8개, 4:4개, 5:4개
const char block[19][4][5] = {
    {"1111", "0000", "0000", "0000"}, {"1000", "1000", "1000", "1000"},
    {"1100", "1100", "0000", "0000"}, {"1110", "1000", "0000", "0000"},
    {"1000", "1000", "1100", "0000"}, {"0100", "0100", "1100", "0000"},
    {"1100", "1000", "1000", "0000"}, {"0010", "1110", "0000", "0000"},
    {"1110", "0010", "0000", "0000"}, {"1000", "1110", "0000", "0000"},
    {"1100", "0100", "0100", "0000"}, {"0100", "1100", "1000", "0000"},
    {"1000", "1100", "0100", "0000"}, {"0110", "1100", "0000", "0000"},
    {"1100", "0110", "0000", "0000"}, {"0100", "1100", "0100", "0000"},
    {"1000", "1100", "1000", "0000"}, {"1110", "0100", "0000", "0000"},
    {"0100", "1110", "0000", "0000"}};
int n, m;
int answer = 0;

void calcSum(int y, int x, int blockNum) {
   int tempSum = 0;
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         // 블록이 보드 넘어가는 경우 <- 이게 있어야 함!
         // why? 밑에서 &&board>0 일때로 하면 1인데 board<0인 경우에도 합을
         // 구하게 됨
         if (block[blockNum][i][j] == '1' && board[y + i][x + j] < 0) {
            return;
         }
         if (block[blockNum][i][j] == '1') {
            tempSum += board[y + i][x + j];
         }
      }
   }
   answer = max(answer, tempSum);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(board, -1601, sizeof(board));
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> board[i][j];
      }
   }

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         for (int k = 0; k < 19; k++) {
            calcSum(i, j, k);
         }
      }
   }
   cout << answer;
}
