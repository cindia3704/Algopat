/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 별 찍기3(2440번)
    문제:첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를
   찍는 문제
*/

#include <iostream>
using namespace std;

int main(void) {
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
         cout << "*";
      }
      cout << '\n';
   }
}