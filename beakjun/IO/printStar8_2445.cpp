/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 별 찍기8(2445번)
    문제:예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
*/

#include <iostream>
using namespace std;

int main(void) {
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
         cout << "*";
      }
      for (int j = i; j < 2 * n - i; j++) {
         cout << " ";
      }
      for (int j = n - i; j < n; j++) {
         cout << "*";
      }
      cout << "\n";
   }
   for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
         cout << "*";
      }
      for (int j = i; j < 2 * n - i; j++) {
         cout << " ";
      }
      for (int j = 2 * n - i; j < 2 * n; j++) {
         cout << "*";
      }
      cout << "\n";
   }
}
