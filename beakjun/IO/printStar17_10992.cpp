/*
    작성자: 김지수
    작성일: 2021/02/25
    백준 -- 별 찍기17(10992번)
    문제:예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
*/

#include <iostream>
using namespace std;

int main(void) {
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++) {
      if (i == n) {
         for (int j = 0; j < 2 * n - 1; j++) {
            cout << "*";
         }
      } else {
         for (int j = 0; j < n - i; j++) {
            cout << " ";
         }
         for (int j = n - i; j < (n - 1) + i; j++) {
            if (j == n - i || j == (n - 1) + i - 1) {
               cout << "*";
            } else {
               cout << " ";
            }
         }
      }
      cout << "\n";
   }
}