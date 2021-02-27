/*
    작성자: 김지수
    작성일: 2021/02/27
    백준 -- 설탕 배달 (2839번)
    문제:상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다.
   설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 봉지는 3킬로그램 봉지와
   5킬로그램 봉지가 있다.상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지
   몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int getSugarBagNeeded(int sugar) {
   if (sugar == 0) {
      return 0;
   } else if (sugar % 5 != 0 && sugar < 3) {
      return -1;
   } else if (sugar % 5 != 0) {
      sugar = sugar - 3;
      int next = getSugarBagNeeded(sugar);
      if (next == -1) {
         return -1;
      } else {
         return 1 + next;
      }
   } else {
      sugar = sugar - 5;
      return 1 + getSugarBagNeeded(sugar);
   }
}

int main(void) {
   int totalSugar;
   cin >> totalSugar;
   int answer = getSugarBagNeeded(totalSugar);
   cout << answer;
}