/*
    작성자: 김지수
    작성일: 2021/09/18
    백준 -- 진법변환 (2745번)
    문제:
*/

#include <tgmath.h>

#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string changedBase;
   int base;
   cin >> changedBase >> base;
   int number = 0;
   for (int i = 0; i < changedBase.length(); i++) {
      char now = changedBase[i];
      int nowInt = int(now);
      if (nowInt >= 65) {
         nowInt -= 55;
      } else {
         nowInt -= 48;
      }
      int multiple = pow(base, changedBase.length() - 1 - i);
      number += (nowInt * multiple);
   }
   cout << number << endl;
}