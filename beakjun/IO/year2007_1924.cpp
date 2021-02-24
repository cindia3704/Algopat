/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 2007년(1924번)
    문제:오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨
   요일일까? 이를 알아내는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int getDayCountForMonth(int month) {
   int dayCount = 0;
   switch (month) {
      case 4:
      case 6:
      case 9:
      case 11:
         dayCount = 30;
         break;
      case 2:
         dayCount = 28;
         break;
      default:
         dayCount = 31;
         break;
   }
   return dayCount;
}

int getDayCount(int month, int day) {
   int dayCount = 0;
   month = month - 1;
   while (month > 0) {
      dayCount += getDayCountForMonth(month);
      month--;
   }
   dayCount += day;
   return dayCount;
}

string getDayOfWeek(int days) {
   const char* daysOfWeek[7] = {"MON", "TUE", "WED", "THU",
                                "FRI", "SAT", "SUN"};
   int index = days % 7;
   return daysOfWeek[index];
}

int main(void) {
   int month, day;
   cin >> month >> day;
   int days = getDayCount(month, day);
   int difference = days - 1;
   string dayOfWeek = getDayOfWeek(difference);
   cout << dayOfWeek << '\n';
}