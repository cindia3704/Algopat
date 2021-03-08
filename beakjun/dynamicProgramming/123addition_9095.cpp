/*
    작성자: 김지수
    작성일: 2021/03/09
    백준 -- 1,2,3 더하기 (9095번)
    문제:정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는
   프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;
int cache[12];

int main(void) {
   int testcase, n;
   cin >> testcase;
   cache[1] = 1;
   cache[2] = 2;
   cache[3] = 4;
   for (int i = 0; i < testcase; i++) {
      cin >> n;
      for (int j = 4; j <= n; j++) {
         cache[j] = cache[j - 1] + cache[j - 2] + cache[j - 3];
      }
      cout << cache[n] << endl;
   }
}
