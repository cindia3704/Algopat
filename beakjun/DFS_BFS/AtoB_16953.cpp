/*
    작성자: 김지수
    작성일: 2021/04/24
    백준 -- A->B (16953번)
    문제:
    - 정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.
        1. 2를 곱한다.
        2. 1을 수의 가장 오른쪽에 추가한다.
    - A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
queue<pair<long long, long long> > calc;
int countOp = -1;

void bfs(long long a, long long b) {
   calc.push(make_pair(a, 1));

   while (!calc.empty()) {
      long long now = calc.front().first;
      int cnt = calc.front().second;
      calc.pop();

      long long times2 = now * 2;
      long long add1 = now * 10 + 1;

      if (times2 < b) {
         calc.push(make_pair(times2, cnt + 1));
      }
      if (add1 < b) {
         calc.push(make_pair(add1, cnt + 1));
      }
      if (times2 == b || add1 == b) {
         countOp = cnt + 1;
         break;
      }
   }
}

int main(void) {
   long long a, b;
   cin >> a >> b;

   bfs(a, b);
   cout << countOp << endl;
}