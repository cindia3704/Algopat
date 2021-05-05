/*
    작성자: 김지수
    작성일: 2021/05/05
    백준 -- 제곱수의 합 (1699번)
    문제:
    - 어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다
    -  예를 들어 11=32+12+12(3개 항)이다. 이런 표현방법은 여러 가지가 될 수
   있는데, 11의 경우 11=22+22+12+12+12(5개 항)도 가능하다.
   - 주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를
   구하는 프로그램을 작성하시오.
*/

#include <math.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 100000;
int cache[MAX_N];

int main(void) {
   memset(cache, 0, sizeof(cache));
   int num;
   cin >> num;

   for (int i = 1; i <= num; i++) {
      cache[i] = i;
      for (int j = 1; j <= sqrt(i); j++) {
         cache[i] = min(cache[i - j * j] + 1, cache[i]);
      }
   }

   cout << cache[num] << endl;
}