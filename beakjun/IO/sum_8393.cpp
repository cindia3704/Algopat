/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 합(8393번)
    문제:n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int main(void) {
   int ans = 0;
   int n;
   cin >> n;
   while (n > 0) {
      ans += n;
      n--;
   }
   cout << ans << '\n';
}