/*
    작성자: 김지수
    작성일: 2021/04/14
    백준 -- BFS DFS (1260번)
    문제:그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을
   작성하시오 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을
   먼저 방문
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1001;
bool visited[MAX];
vector<int> graph[MAX];

void dfs(int currentNode) {
   cout << currentNode << " ";
   visited[currentNode] = true;

   for (int i = 0; i < graph[currentNode].size(); i++) {
      int nextNode = graph[currentNode][i];
      if (!visited[nextNode]) {
         dfs(nextNode);
      }
   }
}

void bfs(int currentNode) {
   queue<int> order;
   visited[currentNode] = true;
   cout << currentNode << " ";
   order.push(currentNode);

   while (!order.empty()) {
      int index = order.front();
      order.pop();
      for (int i = 0; i < graph[index].size(); i++) {
         int next = graph[index][i];
         if (!visited[next]) {
            visited[next] = true;
            cout << next << " ";
            order.push(next);
         }
      }
   }
}

int main(void) {
   int totalNode, totalEdge, startNode;
   cin >> totalNode >> totalEdge >> startNode;
   memset(visited, false, sizeof(visited));
   for (int i = 0; i < totalEdge; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      graph[node1].push_back(node2);
      graph[node2].push_back(node1);
   }
   for (int i = 0; i <= totalNode; i++) {
      sort(graph[i].begin(), graph[i].end());
   }

   dfs(startNode);
   cout << endl;
   memset(visited, false, sizeof(visited));
   bfs(startNode);
}