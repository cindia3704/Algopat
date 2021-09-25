/*
    작성자: 김지수
    작성일: 2021/09/25
    programmers -- 가장 먼 노드 (49189번)
*/

#include <queue>
#include <string>
#include <vector>

using namespace std;
const int MAX_N = 20001;
int depth = 0;
bool visited[MAX_N];
vector<int> temp;
vector<int> graph[MAX_N];

void bfs(int start) {
   queue<pair<int, int>> q;
   q.push({start, 0});
   visited[start] = true;
   while (!q.empty()) {
      int nowNode = q.front().first;
      int level = q.front().second;
      q.pop();
      if (level > depth && graph[level].size() != 0) {
         temp.clear();
         depth = level;
      }
      if (level == depth) {
         temp.push_back(nowNode);
      }
      for (int i = 0; i < graph[nowNode].size(); i++) {
         int nextNode = graph[nowNode][i];
         if (!visited[nextNode]) {
            q.push({nextNode, level + 1});
            visited[nextNode] = true;
         }
      }
   }
}
int solution(int n, vector<vector<int>> edge) {
   int answer = 0;
   fill(visited, visited + MAX_N, false);
   for (int i = 0; i < edge.size(); i++) {
      int node1 = edge[i][0];
      int node2 = edge[i][1];
      graph[node1].push_back(node2);
      graph[node2].push_back(node1);
   }
   bfs(1);
   answer = temp.size();
   return answer;
}