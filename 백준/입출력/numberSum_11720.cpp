/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 숫자의 합 (11720번)
    문제:N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는
   프로그램을 작성하시오.
*/

#include <iostream>
#include <string>
using namespace std;

int main(void) {
   int count;
   string input;
   cin >> count;
   cin.ignore();
   int answer = 0;
   getline(cin, input);
   for (int i = 0; i < count; i++) {
      char sub = input[i];
      int inputSubstring = sub - '0';
      answer += inputSubstring;
   }
   cout << answer;
}