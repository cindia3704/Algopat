/*
    작성자: 김지수
    작성일: 2022/03/13
    백준 -- 케빈 베이컨의 6단계 법칙 (1389번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 101;

bool visited[MAX];
vector<int> graph[MAX];

int bfs(int start) {
   int sum = 0;
   queue<pair<int, int> > q;
   q.push(make_pair(start, 0));
   visited[start] = true;
   while (!q.empty()) {
      int now = q.front().first;
      int nowCount = q.front().second;
      sum += nowCount;
      q.pop();
      for (int i = 0; i < graph[now].size(); i++) {
         int next = graph[now][i];
         if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, nowCount + 1));
         }
      }
   }
   return sum;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int nodeNum, edgeNum;
   cin >> nodeNum >> edgeNum;
   for (int i = 0; i < edgeNum; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   int minLength = 987654321;
   vector<int> ans;
   for (int i = 1; i < nodeNum + 1; i++) {
      memset(visited, false, sizeof(visited));

      int temp = bfs(i);
      if (minLength == temp) {
         ans.push_back(i);
      } else if (minLength > temp) {
         ans.clear();
         minLength = temp;
         ans.push_back(i);
      }
   }
   sort(ans.begin(), ans.end());
   cout << ans[0];
}