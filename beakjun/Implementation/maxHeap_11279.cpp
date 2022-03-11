/*
    작성자: 김지수
    작성일: 2022/03/12
    백준 -- 최대 힙 (11279번)
*/

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   priority_queue<long long> q;
   int n;
   cin >> n;
   while (n--) {
      int num;
      cin >> num;
      if (num == 0) {
         if (q.empty()) {
            cout << 0 << '\n';
         } else {
            cout << q.top() << '\n';
            q.pop();
         }
      } else {
         q.push(num);
      }
   }
}