/*
    작성자: 김지수
    작성일: 2022/05/18
    백준 -- 정수 삼각형 (1932번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 501
using namespace std;

long long cache[MAX][MAX];
int board[MAX][MAX];
int boardSize;

// 위에서부터 밑으로 내려감 -> 입력으로 자기 바로 아래 or 자기 대각선 오른쪽
// 아래
long long findMaxTriangle(int y, int x) {
   long long &ret = cache[y][x];
   // 이전에 세팅됐으면 그거 리턴
   if (ret != -1) {
      return ret;
   }
   // 마지막줄 도착하면 보드 값 리턴
   if (y == boardSize - 1) {
      return board[y][x];
   } else {
      // 계산한 값중 큰값을 세팅
      ret = max(board[y][x] + findMaxTriangle(y + 1, x),
                board[y][x] + findMaxTriangle(y + 1, x + 1));
   }
   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   // 처음 보드는 아주 작은 값으로 세팅 -> 혹시 경계 넘어가도 최대값 찾는거니
   // 이걸 세팅하지 않게
   memset(board, -10000, sizeof(board));
   memset(cache, -1, sizeof(cache));
   cin >> boardSize;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < i + 1; j++) {
         cin >> board[i][j];
      }
   }

   cout << findMaxTriangle(0, 0);
}
