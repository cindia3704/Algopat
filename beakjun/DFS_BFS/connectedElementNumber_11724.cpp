
/*
    작성자: 김지수
    작성일: 2021/04/14
    백준 -- 연결 요소의 개수 (11724번)
    문제:
    - 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를
   구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1001;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) {
   visited[node] = true;
   for (int i = 0; i < graph[node].size(); i++) {
      int nextNode = graph[node][i];
      if (!visited[nextNode]) {
         dfs(nextNode);
      }
   }
}

int main(void) {
   int count = 0;
   memset(visited, false, sizeof(visited));
   int totalNode, totalEdge;
   cin >> totalNode >> totalEdge;

   for (int i = 0; i < totalEdge; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      graph[node1].push_back(node2);
      graph[node2].push_back(node1);
   }

   for (int i = 1; i <= totalNode; i++) {
      if (!visited[i]) {
         dfs(i);
         count++;
      }
   }
   cout << count << endl;
}