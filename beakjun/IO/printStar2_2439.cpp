/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 별 찍기2(2438번)
    문제:첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
   하지만, 오른쪽을 기준으로 정렬한 별(예제 참고)을 출력하시오.
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
      for (int j = n - i; j <= n - 1; j++) {
         cout << "*";
      }
      cout << '\n';
   }
}