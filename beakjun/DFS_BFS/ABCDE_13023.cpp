/*
    작성자: 김지수
    작성일: 2021/04/14
    백준 -- ABCDE (13023번)
    문제:
    - BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로
   번호가 매겨져 있고, 일부 사람들은 친구이다
   - 오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지
    구해보려고 한다.
        -A는 B와 친구다.
        -B는 C와 친구다.
        -C는 D와 친구다.
        -D는 E와 친구다.
    위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.
*/

// 결국 깊이가 5이상인게 있는지 물어보는 문제!

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
const int MAX = 2000;

using namespace std;
vector<int> graph[MAX];
bool visited[MAX];
bool found = false;

void dfs(int node, int countNode) {
   visited[node] = true;
   if (countNode == 4) {
      found = true;
   }
   for (int i = 0; i < graph[node].size(); i++) {
      int nextNode = graph[node][i];
      if (found) {
         return;
      }
      if (!visited[nextNode]) {
         dfs(nextNode, countNode + 1);
      }
   }
   // 만족못하면, backtracking해야해서 다시 visited false로
   visited[node] = false;
}
int main(void) {
   memset(visited, false, sizeof(visited));
   int totalNode, totalEdge;
   cin >> totalNode >> totalEdge;

   for (int i = 0; i < totalEdge; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      // 친구 관계여서 양방향!
      graph[node1].push_back(node2);
      graph[node2].push_back(node1);
   }
   for (int i = 0; i < totalNode; i++) {
      if (!found) {
         memset(visited, false, sizeof(visited));
         dfs(i, 0);
      } else {
         break;
      }
   }
   int answer = (found == true) ? 1 : 0;
   cout << answer << endl;
}