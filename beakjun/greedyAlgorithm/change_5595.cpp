/*
    작성자: 김지수
    작성일: 2021/02/27
    백준 -- 거스름 돈 (5585번)
    문제:타로는 자주 JOI잡화점에서 물건을 산다. JOI잡화점에는 잔돈으로 500엔,
   100엔, 50엔, 10엔, 5엔, 1엔이 충분히 있고, 언제나 거스름돈 개수가 가장 적게
   잔돈을 준다. 타로가 JOI잡화점에서 물건을 사고 카운터에서 1000엔 지폐를 한장
   냈을 때, 받을 잔돈에 포함된 잔돈의 개수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;
int getNumberOfCoins(int payback) {
   if (payback == 0) {
      return 0;
   }
   if (payback >= 500) {
      payback -= 500;
      return 1 + getNumberOfCoins(payback);
   } else if (payback < 500 && payback >= 100) {
      payback -= 100;
      return 1 + getNumberOfCoins(payback);
   } else if (payback < 100 && payback >= 50) {
      payback -= 50;
      return 1 + getNumberOfCoins(payback);
   } else if (payback < 50 && payback >= 10) {
      payback -= 10;
      return 1 + getNumberOfCoins(payback);
   } else if (payback < 10 && payback >= 5) {
      payback -= 5;
      return 1 + getNumberOfCoins(payback);
   } else {
      payback -= 1;
      return 1 + getNumberOfCoins(payback);
   }
}

int main(void) {
   int cost, payback;
   cin >> cost;
   payback = 1000 - cost;
   cout << getNumberOfCoins(payback);
}