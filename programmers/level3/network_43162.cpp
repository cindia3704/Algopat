/*
    작성자: 김지수
    작성일: 2021/09/25
    programmers -- 네트워크 (43162번)
*/
#include <cstring>
#include <queue>
#include <string>
#include <vector>

using namespace std;
const int MAX_N = 200;

bool visited[MAX_N];
vector<int> graph[MAX_N];
void bfs(int node, vector<vector<int>> computers) {
   queue<int> q;
   q.push(node);
   visited[node] = true;
   while (!q.empty()) {
      int nowNode = q.front();
      q.pop();
      for (int i = 0; i < graph[nowNode].size(); i++) {
         int nextNode = graph[nowNode][i];

         if (!visited[nextNode]) {
            q.push(nextNode);
            visited[nextNode] = true;
         }
      }
   }
}

int solution(int n, vector<vector<int>> computers) {
   int answer = 0;
   memset(visited, false, sizeof(visited));
   int computerNum = computers.size();

   for (int i = 0; i < computerNum; i++) {
      for (int j = 0; j < computerNum; j++) {
         if (computers[i][j] == 1) {
            graph[i].push_back(j);
         }
      }
   }

   for (int i = 0; i < computerNum; i++) {
      if (!visited[i]) {
         answer++;
         bfs(i, computers);
      }
   }
   return answer;
}