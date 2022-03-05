/*
    작성자: 김지수
    작성일: 2022/03/06
    백준 -- 영수증 (5565번)
*/

#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int total;
   cin >> total;
   for (int i = 0; i < 9; i++) {
      int price;
      cin >> price;
      total -= price;
   }
   cout << total;
}