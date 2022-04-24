/*
    작성자: 김지수
    작성일: 2022/04/23
    백준 -- 주사위 굴리기 (14499번)
    문제:
*/

#include <cstring>
#include <iostream>
#include <vector>
#define MAX 21
using namespace std;
const int dx[4] = {1, -1, 0, 0};  // E,W,N,S
const int dy[4] = {0, 0, -1, 1};
int height, width;
int diceY, diceX;
int board[MAX][MAX];
vector<int> moveDir;
int bnr[3] = {1, 2, 3};  // bottom, north, right
int dice[6] = {0, 0, 0, 0, 0, 0};

void printTop() {
   //    cout << "\n=== BNR === " << endl;
   //    for (int i = 0; i < 3; i++) {
   //       cout << "bnr: " << bnr[i] << "  dice:" << dice[(bnr[i] - 1)] <<
   //       endl;
   //    }
   //    for (int i = 0; i < 6; i++) {
   //       cout << "i:" << i + 1 << "  dice:" << dice[i] << endl;
   //    }
   cout << dice[(7 - bnr[0]) - 1] << endl;
}
void moveDice(int turn) {
   int north = bnr[1];
   int bottom = bnr[0];
   int right = bnr[2];
   if (turn == 0) {  // right
      bnr[0] = right;
      bnr[2] = 7 - bottom;
   } else if (turn == 1) {  // left
      bnr[2] = bottom;
      bnr[0] = 7 - right;
   } else if (turn == 2) {  // up
      bnr[0] = north;
      bnr[1] = 7 - bottom;
   } else {  // down
      bnr[0] = 7 - north;
      bnr[1] = bottom;
   }
}

void rollDice(int turn) {
   int nowDir = moveDir[turn];
   int nextY = diceY + dy[nowDir];
   int nextX = diceX + dx[nowDir];
   // cout << "TURN: " << turn << "  next:" << nextY << "," << nextX << endl;
   if (nextY < 0 || nextY >= height || nextX < 0 || nextX >= width) {
      return;
   } else {
      moveDice(nowDir);
      //   cout << "BOARD:" << board[nextY][nextX]
      //        << "  dice bottom:" << dice[bnr[0] - 1] << endl;
      if (board[nextY][nextX] == 0) {
         board[nextY][nextX] = dice[bnr[0] - 1];
      } else {
         dice[bnr[0] - 1] = board[nextY][nextX];
         board[nextY][nextX] = 0;
         // cout << " add: " << bnr[0] << " :" << dice[bnr[0] - 1] << endl;
      }
      printTop();
      diceX = nextX;
      diceY = nextY;
      return;
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int turnNum;
   cin >> height >> width >> diceY >> diceX >> turnNum;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> board[i][j];
      }
   }
   for (int i = 0; i < turnNum; i++) {
      int num;
      cin >> num;
      num--;
      moveDir.push_back(num);
   }
   for (int i = 0; i < turnNum; i++) {
      rollDice(i);
   }
}