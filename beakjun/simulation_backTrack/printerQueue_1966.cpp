/*
    작성자: 김지수
    작성일: 2021/09/12
    백준 -- 프린터 큐 (1966번)
    문제:
    - 프린터 출력 조건:
        1) 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인
        2) 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면,
        이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다
        3) 그렇지 않다면 바로 인쇄를 한다
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int pCount[10];
int getMaxPriority() {
   int maxNum = 0;
   for (int i = 9; i >= 1; i--) {
      if (pCount[i] > 0) {
         return i;
      }
   }
   return maxNum;
}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int testCase;
   cin >> testCase;
   while (testCase--) {
      int numFile, interest;
      cin >> numFile >> interest;
      memset(pCount, 0, sizeof(pCount));
      queue<pair<int, int> > printer;
      for (int i = 0; i < numFile; i++) {
         int priority;
         cin >> priority;
         pCount[priority]++;
         printer.push(make_pair(priority, i));
      }
      int count = 0;
      while (!printer.empty()) {
         int maxPriority = getMaxPriority();
         pair<int, int> now = printer.front();

         if (now.first == maxPriority) {
            pCount[now.first]--;
            printer.pop();
            count++;
            if (now.second == interest) {
               cout << count << endl;
               break;
            }
         } else {
            printer.pop();
            printer.push(now);
         }
      }
   }
}