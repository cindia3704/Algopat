/*
    작성자: 김지수
    작성일: 2021/02/25
    백준 -- 별 찍기12(2522번)
    문제:예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
*/

#include <iostream>
using namespace std;

int main(void) {
   int n;
   cin >> n;

   for (int i = 1; i <= n; i++) {
      for (int j = 0; j < n - i; j++) {
         cout << " ";
      }
      for (int j = n - i; j < n; j++) {
         cout << "*";
      }
      cout << "\n";
   }
   for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
         cout << " ";
      }
      for (int j = i; j < n; j++) {
         cout << "*";
      }
      cout << "\n";
   }
}