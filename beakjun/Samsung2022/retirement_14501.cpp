/*
    작성자: 김지수
    작성일: 2022/04/03
    백준 -- 퇴사 (14501번)
    문제:
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 16;
struct SCHED {
   int days, bill;
};

vector<SCHED> schedule;
int schedNum;
int maxProfit = -1;

void work(int day, int profit) {
   if (day >= schedNum) {
      maxProfit = max(maxProfit, profit);
      return;
   } else {
      if (schedule[day].days + day <= schedNum) {
         work(day + schedule[day].days, profit + schedule[day].bill);
      }
      work(day + 1, profit);
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> schedNum;
   for (int i = 0; i < schedNum; i++) {
      SCHED now;
      cin >> now.days >> now.bill;
      schedule.push_back(now);
   }
   work(0, 0);
   cout << maxProfit;
}