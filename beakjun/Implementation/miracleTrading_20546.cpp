/*
    작성자: 김지수
    작성일: 2021/10/02
    백준 -- 기적의 매매법 (20546번)
    문제:
*/

#include <iostream>
#include <vector>
using namespace std;
const int TRADE_DAY = 14;
const string choices[] = {"BNP", "TIMING", "SAMESAME"};

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int initialAmount;
   int value[TRADE_DAY];

   cin >> initialAmount;
   for (int i = 0; i < TRADE_DAY; i++) {
      cin >> value[i];
   }
   int moneyLeftJ = initialAmount;
   int stockAmountJ = 0;
   int moneyLeftS = initialAmount;
   int stockAmountS = 0;
   int count = 0;
   for (int i = 0; i < TRADE_DAY; i++) {
      if (value[i] <= moneyLeftJ) {
         stockAmountJ += (moneyLeftJ / value[i]);
         moneyLeftJ = moneyLeftJ % value[i];
      }
      if (i >= 3) {
         if (value[i - 1] > value[i] && value[i - 2] > value[i - 1] &&
             value[i - 3] > value[i - 2]) {
            if (value[i] <= moneyLeftS) {
               stockAmountS += (moneyLeftS / value[i]);
               moneyLeftS = moneyLeftS % value[i];
            }
         } else if (value[i - 1] < value[i] && value[i - 2] < value[i - 1] &&
                    value[i - 3] < value[i - 2]) {
            if (stockAmountS > 0) {
               moneyLeftS += (stockAmountS * value[i]);
               stockAmountS = 0;
            }
         }
      }
   }

   int lastMoneyJ = moneyLeftJ + (stockAmountJ * value[TRADE_DAY - 1]);
   int lastMoneyS = moneyLeftS + (stockAmountS * value[TRADE_DAY - 1]);

   if (lastMoneyJ > lastMoneyS) {
      cout << choices[0];
   } else if (lastMoneyJ == lastMoneyS) {
      cout << choices[2];
   } else {
      cout << choices[1];
   }
}