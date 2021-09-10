/*
    작성자: 김지수
    작성일: 2021/09/10
    백준 --  월드컵 (6987번)
    문제: 월드컵 6팀이서 하는데 가능한 결과 조합이면 1 아니면 0 출력
*/
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct result {
   int win, lose, tie;
};
// 6개의 팀의 결과 담는 배열
result ret[6];
bool validResult(int t1, int t2) {
   if (t1 == 5) {
      int sumOfLeftResult = 0;
      for (int i = 0; i < 6; i++) {
         sumOfLeftResult += ret[i].win;
         sumOfLeftResult += ret[i].tie;
         sumOfLeftResult += ret[i].lose;
      }
      if (sumOfLeftResult == 0) {
         return true;
      } else {
         return false;
      }
   }
   bool valid = false;
   if (ret[t1].win > 0 && ret[t2].lose > 0) {
      ret[t1].win--;
      ret[t2].lose--;
      if (t2 == 5) {
         valid = validResult(t1 + 1, t1 + 2);
      } else {
         valid = validResult(t1, t2 + 1);
      }
      ret[t1].win++;
      ret[t2].lose++;
   }
   if (!valid) {
      if (ret[t1].lose > 0 && ret[t2].win > 0) {
         ret[t1].lose--;
         ret[t2].win--;
         if (t2 == 5) {
            valid = validResult(t1 + 1, t1 + 2);
         } else {
            valid = validResult(t1, t2 + 1);
         }
         ret[t1].lose++;
         ret[t2].win++;
      }
   }
   if (!valid) {
      if (ret[t1].tie > 0 && ret[t2].tie > 0) {
         ret[t1].tie--;
         ret[t2].tie--;
         if (t2 == 5) {
            valid = validResult(t1 + 1, t1 + 2);
         } else {
            valid = validResult(t1, t2 + 1);
         }
         ret[t1].tie++;
         ret[t2].tie++;
      }
   }
   return valid;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   for (int i = 0; i < 4; i++) {
      memset(ret, 0, sizeof(ret));
      for (int j = 0; j < 6; j++) {
         cin >> ret[j].win >> ret[j].tie >> ret[j].lose;
      }
      if (validResult(0, 1)) {
         cout << 1 << endl;
      } else {
         cout << 0 << endl;
      }
   }
}