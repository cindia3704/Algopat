/*
    작성자: 김지수
    작성일: 2022/03/07
    백준 -- 효율적인 해킹 (1325번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 10001;
vector<int> graph[MAX];
bool visited[MAX];

int bfs(int node) {
   int count = 0;
   queue<int> q;
   visited[node] = true;
   q.push(node);
   while (!q.empty()) {
      int now = q.front();
      q.pop();
      count++;
      for (int i = 0; i < graph[now].size(); i++) {
         if (!visited[graph[now][i]]) {
            visited[graph[now][i]] = true;
            q.push(graph[now][i]);
         }
      }
   }
   return count;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int nodeNum, edgeNum;
   cin >> nodeNum >> edgeNum;
   for (int i = 0; i < edgeNum; i++) {
      int a, b;
      cin >> a >> b;
      graph[b].push_back(a);
   }
   int maxHack = 0;
   vector<int> ans;
   for (int i = 1; i <= nodeNum; i++) {
      memset(visited, false, sizeof(visited));
      int tempHack = bfs(i);
      if (tempHack > maxHack) {
         ans.clear();
         maxHack = tempHack;
         ans.push_back(i);
      } else if (tempHack == maxHack) {
         ans.push_back(i);
      }
   }
   sort(ans.begin(), ans.end());
   for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
   }
}