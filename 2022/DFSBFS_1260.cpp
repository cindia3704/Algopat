/*
    작성자: 김지수
    작성일: 2022/05/15
    백준 -- DFS와 BFS (1260번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];

// 깊이 우선 탐색 -> 연결된 노드로 계속 recursive하게 호출
void dfs(int start) {
   cout << start << " ";
   for (int i = 0; i < graph[start].size(); i++) {
      if (visited[graph[start][i]] == false) {
         visited[graph[start][i]] = true;
         dfs(graph[start][i]);
      }
   }
}

// 너비우선탐색 -> 옆에 있는 노드들 wide하게 탐색 후 깊게
void bfs(int start) {
   queue<int> q;
   q.push(start);
   visited[start] = true;
   while (!q.empty()) {
      int now = q.front();
      cout << now << " ";
      q.pop();
      for (int i = 0; i < graph[now].size(); i++) {
         if (visited[graph[now][i]] == false) {
            visited[graph[now][i]] = true;
            q.push(graph[now][i]);
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int nodeNum, edgeNum, startNode;
   cin >> nodeNum >> edgeNum >> startNode;

   // 양방향 노드
   for (int i = 0; i < edgeNum; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   // 방문가능한 정점이 여러개면 작은 노드부터
   for (int i = 1; i <= nodeNum; i++) {
      sort(graph[i].begin(), graph[i].end());
   }

   // 방문 안됨 처이
   memset(visited, false, sizeof(visited));
   // 첫 노드는 방문처리
   visited[startNode] = true;
   dfs(startNode);
   cout << endl;

   memset(visited, false, sizeof(visited));
   bfs(startNode);
}
