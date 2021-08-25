/*
    작성자: 김지수
    작성일: 2021/08/26
    백준 -- 퇴사 2 (15486번)
    문제:
    - 백준이가 N+1일날 퇴사 하려고함
    - 1~N일까지 상담이 있고 , 완료하는데 걸리는 시간 & 금액 주어짐
    -  백준이가 얻을 수 있는 최대 수익을 구하라
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_DAYS = 1500001;
long long cache[MAX_DAYS], prices[MAX_DAYS], times[MAX_DAYS];
int days;

long long dp(int day) {
   long long &ret = cache[day];
   if (day == days + 1) {
      return 0;
   }
   if (day > days + 1) {
      return -987654321;
   }
   if (ret != -1) {
      return ret;
   } else {
      ret = max((prices[day] + dp(day + times[day])), dp(day + 1));
   }
   return ret;
}

int main(void) {
   memset(cache, -1, sizeof(cache));
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> days;
   for (int i = 1; i <= days; i++) {
      cin >> times[i] >> prices[i];
   }

   cout << dp(1);
}