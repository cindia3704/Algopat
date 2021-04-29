/*
    작성자: 김지수
    작성일: 2021/04/29
    백준 -- 숨바꼭질 (1912번)
    문제:
    - 수빈이는 동생과 숨바꼭질을 하고 있다
    - 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에
   있다
   -  만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게
   된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
   - 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른
   시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 100001;
int me, sis;
bool visited[MAX_N];

int findSis(int start) {
   queue<pair<int, int> > locAndTime;
   locAndTime.push(make_pair(start, 0));
   visited[start] = true;

   while (!locAndTime.empty()) {
      int loc = locAndTime.front().first;
      int time = locAndTime.front().second;
      locAndTime.pop();

      if (loc == sis) {
         return time;
      }
      if (loc * 2 < MAX_N && !visited[loc * 2]) {
         locAndTime.push(make_pair(loc * 2, time + 1));
         visited[loc * 2] = true;
      }
      if (loc + 1 < MAX_N && !visited[loc + 1]) {
         locAndTime.push(make_pair(loc + 1, time + 1));
         visited[loc + 1] = true;
      }
      if (loc - 1 >= 0 && !visited[loc - 1]) {
         locAndTime.push(make_pair(loc - 1, time + 1));
         visited[loc - 1] = true;
      }
   }
}

int main(void) {
   memset(visited, false, sizeof(visited));
   cin >> me >> sis;
   cout << findSis(me) << endl;
   return 0;
}