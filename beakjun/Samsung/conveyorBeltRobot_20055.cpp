/*
    작성자: 김지수
    작성일: 2021/10/05
    백준 -- 컨베이어 벨트 위의 로봇 (20055번)
    문제:
*/

#include <iostream>
#include <queue>
using namespace std;
int beltSize, limit;
int countZero;
struct Belt {
   int weight;
   bool haveBox;
};
deque<Belt> dq;
int countZeros() {
   int count = 0;
   for (int i = 0; i < 2 * beltSize; i++) {
      if (dq[i].weight == 0) {
         count++;
      }
   }
   return count;
}

int playStage(int stage) {
   while (true) {
      stage++;
      Belt temp = dq.back();
      dq.pop_back();
      dq.push_front(temp);
      dq[beltSize - 1].haveBox = false;

      for (int i = beltSize - 2; i >= 0; i--) {
         if (dq[i].haveBox && !dq[i + 1].haveBox && dq[i + 1].weight > 0) {
            dq[i + 1].weight--;
            dq[i + 1].haveBox = true;
            dq[i].haveBox = false;
         }
      }
      dq[beltSize - 1].haveBox = false;
      if (dq[0].weight > 0 && !dq[0].haveBox) {
         dq[0].weight--;
         dq[0].haveBox = true;
      }

      countZero = countZeros();
      if (countZero >= limit) {
         break;
      }
   }
   return stage;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> beltSize >> limit;
   for (int i = 0; i < beltSize * 2; i++) {
      int num;
      cin >> num;
      if (num == 0) {
         countZero++;
      }
      Belt b;
      b.weight = num;
      b.haveBox = false;
      dq.push_back(b);
   }
   cout << playStage(0);
}
