/*
    작성자: 김지수
    작성일: 2021/04/15
    백준 -- 퇴사 (14501번)
    문제:
    - 오늘부터 N+1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은
   상담을 하려고 한다.
   - 각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수
   있는 금액 Pi로 이루어져 있다.
   상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을
   작성하시오.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 15 + 1;
const int MIN = -987654321;

int times[MAX];
int prices[MAX];
int totalDays;
int cache[MAX];

int findMaxPrice(int day) {
   int& ret = cache[day];
   if(day==totalDays+1){
      return 0;
   }
   if(day>totalDays+1){
      return MIN;
   }
   if (ret != -1) {
      return ret;
   }
   ret =0;
   // 오늘일 or 내일꺼 선택 
   ret += max(prices[day]+findMaxPrice(day+times[day]),findMaxPrice(day+1));
   return ret;
}

int main(void) {
   memset(cache, -1, sizeof(cache));
   cin >> totalDays;
   for (int i = 1; i <= totalDays; i++) {
      cin >> times[i] >> prices[i];
   }

   int maxNum = findMaxPrice(1);
   cout << maxNum << endl;
}