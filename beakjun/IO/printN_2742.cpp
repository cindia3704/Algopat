/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 기찍(2742번)
    문제:자연수 N이 주어졌을 때, N부터 1까지 한 줄에 하나씩 출력하는 프로그램을
   작성하시오.
*/

#include <iostream>
using namespace std;

int main(void) {
   int n;
   cin >> n;
   while (n > 0) {
      cout << n << '\n';
      n--;
   }
}