/*
    작성자: 김지수
    작성일: 2022/06/11
    백준 -- 2048(Easy) (12100번)
*/

#include <cstring>
#include <iostream>
#define MAX 21
using namespace std;
bool visited[MAX][MAX];
int n;
int ans = 0;

void moveBoard(int board[21][21], int turn) {
   // 방문처리
   memset(visited, false, sizeof(visited));
   if (turn == 1) {
      for (int i = 0; i < n; i++) {
         for (int j = n - 1; j >= 0; j--) {
            // 해당칸이 비어있지 않음
            if (board[i][j] != 0) {
               // 오른쪽으로 이동
               int nextIdx = j + 1;
               while (nextIdx < n) {
                  if (board[i][nextIdx] != 0) {
                     if (board[i][nextIdx] == board[i][j] &&
                         visited[i][nextIdx] == false) {
                        visited[i][nextIdx] = true;
                        // 예)2 2 4 16인데 왼쪽 이동-> 4 4 16 0 이 되어야함.
                        // (1턴에 여러번 합쳐지면 안됨)=> 방문처리
                        board[i][nextIdx] = 2 * board[i][nextIdx];
                        board[i][j] = 0;
                     } else {
                        if (nextIdx - 1 != j) {
                           board[i][nextIdx - 1] = board[i][j];
                           board[i][j] = 0;
                        }
                     }
                     break;
                  } else {
                     nextIdx++;
                  }
                  // 마지막이 0이면 그 위치로 옮겨야함
                  if (nextIdx == n) {
                     board[i][nextIdx - 1] = board[i][j];
                     board[i][j] = 0;
                  }
               }
            }
         }
      }
   } else if (turn == 3) {
      for (int i = 0; i < n; i++) {
         for (int j = 1; j < n; j++) {
            // 해당칸이 비어있지 않음
            if (board[i][j] != 0) {
               // 왼쪽으로 이동
               int nextIdx = j - 1;
               while (nextIdx >= 0) {
                  if (board[i][nextIdx] != 0) {
                     if (board[i][nextIdx] == board[i][j] &&
                         visited[i][nextIdx] == false) {
                        visited[i][nextIdx] = true;
                        board[i][nextIdx] = 2 * board[i][nextIdx];
                        board[i][j] = 0;
                     } else {
                        if (nextIdx + 1 != j) {
                           board[i][nextIdx + 1] = board[i][j];
                           board[i][j] = 0;
                        }
                     }
                     break;
                  } else {
                     nextIdx--;
                  }
                  // 마지막이 0이면 그 위치로 옮겨야함
                  if (nextIdx == -1) {
                     board[i][nextIdx + 1] = board[i][j];
                     board[i][j] = 0;
                  }
               }
            }
         }
      }
   } else if (turn == 2) {
      for (int i = 0; i < n; i++) {
         for (int j = n - 1; j >= 0; j--) {
            // 해당칸이 비어있지 않음
            if (board[j][i] != 0) {
               // 아래쪽으로 이동
               int nextIdx = j + 1;
               while (nextIdx < n) {
                  if (board[nextIdx][i] != 0) {
                     if (board[nextIdx][i] == board[j][i] &&
                         visited[nextIdx][i] == false) {
                        visited[nextIdx][i] = true;
                        board[nextIdx][i] = 2 * board[nextIdx][i];
                        board[j][i] = 0;
                     } else {
                        if (nextIdx - 1 != j) {
                           board[nextIdx - 1][i] = board[j][i];
                           board[j][i] = 0;
                        }
                     }
                     break;
                  } else {
                     nextIdx++;
                  }
                  // 마지막이 0이면 그 위치로 옮겨야함
                  if (nextIdx == n) {
                     board[nextIdx - 1][i] = board[j][i];
                     board[j][i] = 0;
                  }
               }
            }
         }
      }
   } else if (turn == 0) {
      for (int i = 0; i < n; i++) {
         for (int j = 1; j < n; j++) {
            // 해당칸이 비어있지 않음
            if (board[j][i] != 0) {
               // 위쪽으로 이동
               int nextIdx = j - 1;
               while (nextIdx >= 0) {
                  if (board[nextIdx][i] != 0) {
                     if (board[nextIdx][i] == board[j][i] &&
                         visited[nextIdx][i] == false) {
                        visited[nextIdx][i] = true;
                        board[nextIdx][i] = 2 * board[nextIdx][i];
                        board[j][i] = 0;
                     } else {
                        if (nextIdx + 1 != j) {
                           board[nextIdx + 1][i] = board[j][i];
                           board[j][i] = 0;
                        }
                     }
                     break;
                  } else {
                     nextIdx--;
                  }
                  // 마지막이 0이면 그 위치로 옮겨야함
                  if (nextIdx == -1) {
                     board[nextIdx + 1][i] = board[j][i];
                     board[j][i] = 0;
                  }
               }
            }
         }
      }
   }
   return;
}

void makeComb(int pickCount, int board[21][21]) {
   if (pickCount == 5) {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (board[i][j] > ans) {
               ans = board[i][j];
            }
         }
      }
      return;
   } else if (pickCount > 5) {
      return;
   } else {
      // up,right,down,left 뽑기
      for (int turn = 0; turn < 4; turn++) {
         // 복사본 만들기
         int copy[MAX][MAX];
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               copy[i][j] = board[i][j];
            }
         }
         moveBoard(copy, turn);
         makeComb(pickCount + 1, copy);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n;
   int board[MAX][MAX];
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> board[i][j];
      }
   }

   makeComb(0, board);
   cout << ans;
}