/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- A+b-5 (10952번)
    문제:두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을
   작성하시오.
   입력 : 입력은 여러 개의 테스트 케이스로 이루어져 있다.각 테스트 케이스는 한
   줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B< 10) 입력의
   마지막에는 0 두 개가 들어온다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   int a, b;
   vector<int> sums;
   vector<int>::iterator ptr;

   while (cin >> a >> b && (a != 0 && b != 0)) {
      sums.push_back(a + b);
   }
   for (ptr = sums.begin(); ptr != sums.end(); ++ptr) {
      cout << *ptr << '\n';
   }
}