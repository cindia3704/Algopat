/*
    작성자: 김지수
    작성일: 2022/03/06
    백준 -- DFS와 BFS (1260번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 10001;
vector<int> graph[MAX];
int visited[MAX];

void bfs(int startNode) {
   queue<int> q;
   visited[startNode] = 1;
   q.push(startNode);
   while (!q.empty()) {
      int now = q.front();
      cout << now << " ";
      q.pop();
      for (int i = 0; i < graph[now].size(); i++) {
         int next = graph[now][i];
         if (visited[next] == 0) {
            visited[next] = 1;
            q.push(next);
         }
      }
   }
}

void dfs(int startNode) {
   cout << startNode << " ";
   for (int i = 0; i < graph[startNode].size(); i++) {
      if (visited[graph[startNode][i]] == 0) {
         visited[graph[startNode][i]] = 1;
         dfs(graph[startNode][i]);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int nodeNum, edgeNum, startNode;
   cin >> nodeNum >> edgeNum >> startNode;
   for (int i = 0; i < edgeNum; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   for (int i = 0; i <= nodeNum; i++) {
      sort(graph[i].begin(), graph[i].end());
   }

   memset(visited, 0, sizeof(visited));
   visited[startNode] = 1;
   dfs(startNode);
   cout << "\n";
   memset(visited, 0, sizeof(visited));
   bfs(startNode);
}