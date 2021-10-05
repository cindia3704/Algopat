/*
    작성자: 김지수
    작성일: 2021/10/05
    백준 -- 최소 힙(1927번)
    문제:
*/

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   priority_queue<int> q;
   int seqSize;
   cin >> seqSize;
   for (int i = 0; i < seqSize; i++) {
      int num;
      cin >> num;
      if (num == 0) {
         if (q.empty()) {
            cout << 0 << '\n';
         } else {
            cout << -q.top() << '\n';
            q.pop();
         }
      } else {
         q.push(-num);
      }
   }
}