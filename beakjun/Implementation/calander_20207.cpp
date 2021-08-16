/*
    작성자: 김지수
    작성일: 2021/08/16
    백준 -- 달력 (20207)
    문제:
    - 달력에 표시해 놓은 일정이 지워지지 않게 다음 규칙으로 코팅지 붙임:
        - 연속된 두 날에 각각 일정이 1개 이상 -> 일정이 연속되었다고 표현
        - 연속된 모든 일정은 하나의 직사각형에 포함되어야 함
        - 연속된 일정을 모두 감싸는 가장 작은 직사각형의 크기만큼 코팅지를 오림
    - 달력 규칙:
        - 일정은 시작 날짜 & 종료 날짜 포함
        - 시작일이 가장 앞선 일정부터 차례대로 채워짐
        - 시작일이 같을 경우 일정의 기간이 긴 것이 먼저 채워짐
        - 일정은 가능한 최 상단에 배치
        - 일정 하나의 세로의 길이는 1
        - 하루 폭 = 1
    - 코팅지 면적 구하라
*/
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 1002;
int calendar[MAX_N];

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(calendar, 0, sizeof(calendar));

   int scheduleNum;
   cin >> scheduleNum;
   int maxDate = 0;
   for (int i = 0; i < scheduleNum; i++) {
      int startDate, endDate;
      cin >> startDate >> endDate;
      if (endDate > maxDate) {
         maxDate = endDate;
      }
      for (int day = startDate; day <= endDate; day++) {
         calendar[day]++;
      }
   }

   int sum = 0;
   int start = 0;
   int end = 0;
   int maxNum = 0;
   for (int i = 0; i <= maxDate + 1; i++) {
      if (calendar[i] > 0) {
         if (start == 0) {
            start = i;
         }
      } else {
         if (end < start) {
            end = i;
            maxNum = *max_element(calendar + start, calendar + end);
            sum += (end - start) * maxNum;
            start = 0;
         }
      }
   }
   cout << sum;
}