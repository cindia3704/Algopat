/*
    작성자: 김지수
    작성일: 2021/09/17
    백준 -- 미로 만들기 (1347번)
    문제:
    - 홍준이는 미로안에서 남쪽을 보고 서있음
   - 홍준이는 미로에서 모든 행과 열의 이동할 수 있는 칸을 걸어다녔다. 그러면서
   자신의 움직임을 모두 노트에 쓰기로 했다.
*/
#include <cstring>
#include <iostream>
using namespace std;
// SWNE
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int MAX_N = 101;
int startY = 50, startX = 50, endY = 50, endX = 50;
int dir = 0;
int board[MAX_N][MAX_N];

pair<int, int> move(int y, int x, char command) {
   // 사람이 남쪽 봤을 때 입장에서 방향 고려!
   if (command == 'R') {
      dir = (dir + 1) % 4;
      return make_pair(y, x);
   }
   if (command == 'L') {
      dir = (dir + 3) % 4;
      return make_pair(y, x);
   } else if (command == 'F') {
      int nextY = y + dy[dir];
      int nextX = x + dx[dir];
      if (nextY > endY) {
         endY = nextY;
      }
      if (nextY < startY) {
         startY = nextY;
      }
      if (nextX > endX) {
         endX = nextX;
      }
      if (nextX < startX) {
         startX = nextX;
      }
      board[nextY][nextX] = 1;
      return make_pair(nextY, nextX);
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int length;  // 처음엔 남쪽 보고있음
   cin >> length;
   string path;
   cin >> path;
   memset(board, 0, sizeof(board));
   int nowY = 50, nowX = 50;
   board[nowY][nowX] = 1;
   for (int i = 0; i < length; i++) {
      pair<int, int> p = move(nowY, nowX, path[i]);
      nowY = p.first;
      nowX = p.second;
   }
   for (int i = startY; i <= endY; i++) {
      for (int j = startX; j <= endX; j++) {
         if (board[i][j] == 0) {
            cout << "#";
         } else {
            cout << ".";
         }
      }
      cout << endl;
   }
}