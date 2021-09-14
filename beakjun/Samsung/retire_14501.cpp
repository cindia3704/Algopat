/*
    작성자: 김지수
    작성일: 2021/09/15
    백준 -- 퇴사 (14501번)
    문제:
    - 오늘부터 N+1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은
   상담을 하려고 한다.
   - 각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수
   있는 금액 Pi로 이루어져 있다.
   상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을
   작성하시오.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 16;
int totalDays;
int times[MAX_N];
int payment[MAX_N];
int maxPayment = 0;
void work(int day, int paymentTilNow) {
   if (day == totalDays + 1) {
      maxPayment = max(maxPayment, paymentTilNow);
      return;
   } else if (day > totalDays + 1) {
      return;
   } else {
      work(day + 1, paymentTilNow);
      work(day + times[day], paymentTilNow + payment[day]);
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> totalDays;
   for (int i = 1; i <= totalDays; i++) {
      cin >> times[i] >> payment[i];
   }
   work(1, 0);
   cout << maxPayment << endl;
}