/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 별 찍기5(2442번)
    문제:첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ..., N번째 줄에는 별 2×N-1개를
   찍는 문제 별은 가운데를 기준으로 대칭이어야 한다.
*/

#include <iostream>
using namespace std;

int main(void) {
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      for (int j = 1; j < n - i; j++) {
         cout << " ";
      }
      for (int j = n - i; j <= n + i; j++) {
         cout << "*";
      }
      cout << "\n";
   }
}