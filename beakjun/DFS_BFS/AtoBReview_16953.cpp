/*
    작성자: 김지수
    작성일: 2022/03/07
    백준 -- A->B (16953번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000000000;

long long bfs(long long num, long long maxNum) {
   long long result = -1;
   queue<pair<long long, long long> > q;
   q.push(make_pair(num, 0));
   while (!q.empty()) {
      long long now = q.front().first;
      long long nowCount = q.front().second;
      if (now == maxNum) {
         result = nowCount + 1;
         break;
      }
      q.pop();
      long long nextTimes2 = now * 2;
      long long nextIs1 = now * 10 + 1;
      if (nextTimes2 <= maxNum) {
         q.push(make_pair(nextTimes2, nowCount + 1));
      }
      if (nextIs1 <= maxNum) {
         q.push(make_pair(nextIs1, nowCount + 1));
      }
   }
   return result;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   long long a, b;
   cin >> a >> b;

   cout << bfs(a, b);
}