/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- A+b-6 (10953번)
    문제:두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을
   작성하시오.
   입력 : 첫째 줄에 테스트 케이스의 개수 T가 주어진다.각 테스트 케이스는 한 줄로
   이루어져 있으며, 각 줄에 A와 B가 주어진다. A와 B는 콤마(,)로 구분되어 있다.
   (0 < A, B < 10)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
   int testCase, a, b;
   char delemeter = ',';
   cin >> testCase;
   vector<int> sums;
   vector<int>::iterator ptr;
   for (int i = 0; i < testCase; i++) {
      cin >> a >> delemeter >> b;
      sums.push_back(a + b);
   }
   for (ptr = sums.begin(); ptr != sums.end(); ++ptr) {
      cout << *ptr << '\n';
   }
}
