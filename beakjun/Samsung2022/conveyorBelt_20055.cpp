/*
    작성자: 김지수
    작성일: 2022/04/29
    백준 -- 컨베이어 벨트 위의 로봇 (20055번)
    문제:
*/
#include <deque>
#include <iostream>
using namespace std;
struct BELT {
   int weight;
   bool haveRobot;
};
deque<BELT> belt;
int beltSize, targetZero;
void turnBelt() {
   BELT temp = belt.back();
   belt.pop_back();
   belt.push_front(temp);
}

int countZero() {
   int count = 0;
   for (int i = 0; i < beltSize * 2; i++) {
      if (belt[i].weight == 0) {
         count++;
      }
   }
   return count;
}

void addRobot() { belt.front().haveRobot = true; }

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> beltSize >> targetZero;

   for (int i = 0; i < beltSize * 2; i++) {
      BELT now;
      cin >> now.weight;
      now.haveRobot = false;
      belt.push_back(now);
   }
   int turn = 0;
   while (true) {
      turn++;
      turnBelt();
      belt[beltSize - 1].haveRobot = false;

      for (int i = beltSize - 1; i > 0; i--) {
         if (belt[i].haveRobot == false && belt[i].weight > 0) {
            if (belt[i - 1].haveRobot == true) {
               belt[i - 1].haveRobot = false;
               belt[i].weight--;
               belt[i].haveRobot = true;
            }
            if (belt[beltSize - 1].haveRobot == true) {
               belt[beltSize - 1].haveRobot = false;
            }
         }
      }
      if (belt[0].weight > 0 && belt[0].haveRobot == false) {
         belt[0].haveRobot = true;
         belt[0].weight--;
      }

      if (countZero() >= targetZero) {
         break;
      }
   }
   cout << turn;
}