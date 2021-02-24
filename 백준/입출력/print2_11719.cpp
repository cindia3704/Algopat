/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 그대로 출력하기2 (11719번)
    문제:입력 받은 대로 출력하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
   string line;
   while (getline(cin, line)) {
      cout << line << '\n';
   }
}
