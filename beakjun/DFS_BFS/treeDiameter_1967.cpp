/*
    작성자: 김지수
    작성일: 2021/09/09
    백준 -- 트리의 지름(1967번)
    문제:
    - 입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을
   구해서 출력하는 프로그램을 작성하라
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 10001;
int ans = 0;

vector<pair<int, int> > graph[MAX_N];
bool visited[MAX_N];
void dfs(int start, int distance) {
   visited[start] = true;
   for (int i = 0; i < graph[start].size(); i++) {
      int nextNode = graph[start][i].first;
      if (visited[nextNode] == false) {
         visited[nextNode] = true;
         dfs(nextNode, distance + graph[start][i].second);
      }
   }
   ans = max(ans, distance);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(visited, false, sizeof(visited));

   int nodeNum;
   cin >> nodeNum;
   for (int i = 0; i < nodeNum - 1; i++) {
      int node1, node2, weight;
      cin >> node1 >> node2 >> weight;
      graph[node1].push_back(make_pair(node2, weight));
      graph[node2].push_back(make_pair(node1, weight));
   }

   for (int i = 1; i <= nodeNum; i++) {
      memset(visited, false, sizeof(visited));
      dfs(i, 0);
   }
   cout << ans << endl;
}
