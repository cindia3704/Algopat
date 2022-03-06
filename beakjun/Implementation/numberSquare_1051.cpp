/*
    작성자: 김지수
    작성일: 2022/03/06
    백준 -- 숫자 정사각형 (1051번)
*/

#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 50;
int board[MAX][MAX];

int maxSquare(int y, int x) {
   int result = 1;
   for (int i = 0; i < y; i++) {
      for (int j = 0; j < x; j++) {
         for (int k = 1; k < min(y, x); k++) {
            if (i + k < y && j + k < x && (board[i][j] == board[i][j + k]) &&
                (board[i][j] == board[i + k][j]) &&
                (board[i][j] == board[i + k][j + k])) {
               result = max(result, k + 1);
            }
         }
      }
   }
   return result * result;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int y, x;
   cin >> y >> x;
   for (int i = 0; i < y; i++) {
      for (int j = 0; j < x; j++) {
         char input;
         cin >> input;
         board[i][j] = input - '0';
      }
   }

   cout << maxSquare(y, x);
}