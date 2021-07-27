/*
    작성자: 김지수
    작성일: 2021/07/27
    백준 -- 뱀 (1390번)
    문제:
    - 뱀은 사과먹으면 길어짐
    - 뱀이 벽/ 자기자신과 부딪히면 게임이 끝난다.
    - 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은
   처음에 오른쪽을 향한다.
    - 뱀은 매 초마다 다음과 같이 움직인다:
        - 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        - 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는
        움직이지 않는다.
        - 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을
        비워준다. 즉, 몸길이는 변하지 않는다.
    - 이 게임이 몇 초에 끝나는지 계산하라
*/

#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 100;
vector<pair<int, char> > dirs;
int board[MAX_N][MAX_N];
int dy = 0;
int dx = 1;

// L-> 왼쪽으로 90도 회전, D-> 오른쪽으로 90도 회전
void changeDir(char command) {
   if (command == 'D') {
      if (dy == 0) {
         dy = dx;
         dx = 0;
      } else {
         dx = -dy;
         dy = 0;
      }
   } else {
      if (dy == 0) {
         dy = -dx;
         dx = 0;
      } else {
         dx = dy;
         dy = 0;
      }
   }
}

int startGame(int turnCount, int boardSize) {
   // 뱀의 머리추가, 꼬리 삭제 등을 하기위해 deque 사용!
   deque<pair<int, int> > snake;
   int nowX = 0, nowY = 0;
   int nowTime = 0;
   int wormLength = 1;
   // 처음엔 길이가 1 따라서 뱀의 모든 부위 위치는 뱀의 머리만 있다
   snake.push_back(make_pair(nowY, nowX));

   int index = 0;
   int turnTime = dirs[index].first;
   char turnDir = dirs[index].second;

   while (true) {
      if (turnTime == nowTime) {
         changeDir(turnDir);
         index++;
         turnTime = dirs[index].first;
         turnDir = dirs[index].second;
      }
      nowX = nowX + dx;
      nowY = nowY + dy;
      pair<int, int> p = make_pair(nowY, nowX);

      // 게임판 범위 벗어남
      if (nowX < 0 || nowX > boardSize - 1 || nowY < 0 ||
          nowY > boardSize - 1) {
         return nowTime + 1;
      } else {
         // 새로 추가하려는 뱀의 머리위치가 현재 뱀의 다른 부위와 부딛힐때
         if (find(snake.begin(), snake.end(), p) != snake.end()) {
            return nowTime + 1;
         } else {
            // 사과가 있으면 꼬리는 지우지 말고, 머리만 추가 + 사과 먹었으니
            // 보드 0으로 바꿈
            if (board[nowY][nowX] == 1) {
               wormLength++;
               board[nowY][nowX] = 0;
               snake.push_front(make_pair(nowY, nowX));
            } else {
               // 사과 없으면 앞으로 전진 => 머리추가, 꼬리 삭제 (뱀 길이 유지)
               snake.push_front(make_pair(nowY, nowX));
               snake.pop_back();
            }
         }
      }

      nowTime++;
   }
}

int main(void) {
   // 게임판의 모든 칸을 0으로 초기화
   memset(board, 0, sizeof(board));
   ios::sync_with_stdio(false);
   cin.tie(0);

   int boardSize, appleNum, turnCount;
   cin >> boardSize;
   cin >> appleNum;

   // 사과가 있는 위치는 1로 표시
   for (int i = 0; i < appleNum; i++) {
      int x, y;
      cin >> x >> y;
      board[x - 1][y - 1] = 1;
   }

   cin >> turnCount;

   for (int i = 0; i < turnCount; i++) {
      int seconds;
      char direction;
      cin >> seconds >> direction;
      dirs.push_back(make_pair(seconds, direction));
   }

   cout << startGame(turnCount, boardSize);
}