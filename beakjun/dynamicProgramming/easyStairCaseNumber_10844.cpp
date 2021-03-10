/*
    작성자: 김지수
    작성일: 2021/03/10
    백준 -- 쉬운 계단 수 (10844번)
    문제:45656이란 수를 보자.

   이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

   세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

   N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을
   작성하시오. (0으로 시작하는 수는 없다.)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const long long MAX = 1000000000;

long long cache[101][10];

int staircaseNum(int place, int first) {
   long long& ret = cache[place][first];
   if (place == 1) return ret = 1;
   if (first == 0) {
      ret = staircaseNum(place - 1, first + 1);
   }
   if (ret != -1) {
      return ret;
   } else {
      if (first == 9) {
         ret = staircaseNum(place - 1, first - 1);
      } else {
         ret = staircaseNum(place - 1, first - 1) % MAX +
               staircaseNum(place - 1, first + 1) % MAX;
      }
   }
   return ret % MAX;
}

int main(void) {
   int n;
   long long ans = 0;
   cin >> n;
   memset(cache, -1, sizeof(cache));
   for (int i = 1; i <= 9; i++) {
      ans = ans + staircaseNum(n, i) % MAX;
   }
   cout << ans % MAX << endl;
}