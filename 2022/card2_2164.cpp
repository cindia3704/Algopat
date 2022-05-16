/*
    작성자: 김지수
    작성일: 2022/05/16
    백준 -- 카드2 (2164번)
*/

#include <deque>
#include <iostream>
using namespace std;
deque<int> dq;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int num;
   cin >> num;
   for (int i = 1; i <= num; i++) {
      dq.push_back(i);
   }

   while (true) {
      // 카드 1장 남을때까지 반복
      if (dq.size() == 1) {
         break;
      }
      // 가장 앞 카드 바닥에 버림
      dq.pop_front();

      // 가장 앞 카드를 맨 뒤로 보냄
      int temp = dq.front();
      dq.push_back(temp);
      dq.pop_front();
   }
   cout << dq.front();
}