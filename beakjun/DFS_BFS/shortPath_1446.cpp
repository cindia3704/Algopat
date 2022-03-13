/*
    작성자: 김지수
    작성일: 2022/03/13
    백준 -- 지름길 (1446번)
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10001;
struct Path {
   int e, w;
};
int shortestDistance[MAX];
vector<Path> p[MAX];

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n, target;
   cin >> n >> target;
   for (int i = 0; i <= target; i++) {
      shortestDistance[i] = i;
   }
   for (int i = 0; i < n; i++) {
      Path now;
      int start;
      cin >> start >> now.e >> now.w;
      if (now.e - start <= now.w) continue;
      if (now.e > target) continue;
      p[start].push_back(now);
   }

   int bf;
   for (int i = 0; i <= target; i++) {
      if (i == 0) {
         bf = -1;
      } else {
         bf = shortestDistance[i - 1];
      }
      shortestDistance[i] = min(shortestDistance[i], bf + 1);
      for (int j = 0; j < p[i].size(); j++) {
         int end = p[i][j].e;
         int weight = p[i][j].w;
         if (shortestDistance[i] + weight < shortestDistance[end]) {
            shortestDistance[end] = shortestDistance[i] + weight;
         }
      }
   }
   cout << shortestDistance[target];
}