/*
    작성자: 김지수
    작성일: 2021/03/8
    백준 -- 1로 만들기 (1463번)
    문제:정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
    - X가 3으로 나누어 떨어지면, 3으로 나눈다.
    - X가 2로 나누어 떨어지면, 2로 나눈다.
    - 1을 뺀다.
    정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고
   한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

// 계산 결과 저장해둘 배열
long long cache[1000001];

long long makeTo1(long long input) {
   long long &ret = cache[input];

   if (input == 1) {
      ret = 0;
      return ret;
   }
   if (ret != -1) {
      return ret;
   }

   ret = makeTo1(input - 1) + 1;
   if (input % 3 == 0) {
      ret = min(ret, makeTo1(input / 3) + 1);
   }
   if (input % 2 == 0) {
      ret = min(ret, makeTo1(input / 2) + 1);
   }

   return ret;
}

int main(void) {
   long long input;
   cin >> input;
   memset(cache, -1, sizeof(cache));
   cout << makeTo1(input) << endl;
}