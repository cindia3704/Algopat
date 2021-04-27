/*
    작성자: 김지수
    작성일: 2021/04/27
    백준 -- 트리의 부모 찾기 (11725번)
    문제:
    - 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각
   노드의 부모를 구하는 프로그램을 작성하시오.
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_NODE = 100000 + 1;
vector<int> graph[MAX_NODE];
bool visited[MAX_NODE];
int parent[MAX_NODE];
queue<int> q;

void findParent(int start) {
   q.push(start);

   while (!q.empty()) {
      int nowNode = q.front();
      visited[nowNode] = true;
      q.pop();

      for (int i = 0; i < graph[nowNode].size(); i++) {
         int nextNode = graph[nowNode][i];
         if (!visited[nextNode]) {
            parent[nextNode] = nowNode;
            q.push(nextNode);
         }
      }
   }
}

int main(void) {
   memset(visited, false, sizeof(visited));
   int totalNode;
   cin >> totalNode;

   for (int i = 0; i < totalNode - 1; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   findParent(1);

   for (int i = 2; i <= totalNode; i++) {
      cout << parent[i] << "\n";
   }
}