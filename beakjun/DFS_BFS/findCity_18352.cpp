/*
    작성자: 김지수
    작성일: 2021/09/03
    백준 -- 특정 거리의 도시 찾기 (18352번)
    문제:
    - 1~N의 도시 + M개의 단방향 도로
    - 도시 X로부터 출발하여 도달할 수 있는 모든 도시 중에서, 최단 거리가 정확히
   K인 모든 도시들의 번호를 출력하라
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 300001;
bool visited[MAX_N];
vector<int> graph[MAX_N];
vector<int> ans;

void bfs(int start, int distance) {
   queue<pair<int, int> > q;
   q.push(make_pair(start, 0));
   visited[start] = true;
   while (!q.empty()) {
      int nowNode = q.front().first;
      int nowDist = q.front().second;
      q.pop();
      if (distance == nowDist) {
         ans.push_back(nowNode);
         continue;
      }
      for (int i = 0; i < graph[nowNode].size(); i++) {
         int nextNode = graph[nowNode][i];
         if (!visited[nextNode]) {
            visited[graph[nowNode][i]] = true;
            q.push(make_pair(nextNode, nowDist + 1));
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(visited, false, sizeof(visited));

   int numCity, numRoad, distance, startCity;
   cin >> numCity >> numRoad >> distance >> startCity;
   for (int i = 0; i < numRoad; i++) {
      int from, to;
      cin >> from >> to;
      graph[from].push_back(to);
   }

   bfs(startCity, distance);

   if (ans.size() == 0) {
      cout << -1;
   } else {
      sort(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); i++) {
         cout << ans[i] << endl;
      }
   }
}