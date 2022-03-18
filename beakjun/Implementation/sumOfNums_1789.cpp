/*
    작성자: 김지수
    작성일: 2022/03/18
    백준 -- 수들의 합 (1789번)
    문제:
*/

#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   unsigned long long num, sum = 0;
   int count = 0;
   cin >> num;
   for (int i = 1; sum < num; i++) {
      if (sum + i < num) {
         sum += i;
         count++;
      } else if (sum + i == num) {
         cout << count + 1;
         return 0;
      } else {
         cout << count;
         return 0;
      }
   }
}