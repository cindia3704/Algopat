/*
    작성자: 김지수
    작성일: 2021/04/15
    백준 -- 숫자 고르기 (2668번)
    문제:
    - 세로 두 줄, 가로로 N개의 칸으로 이루어진 표가 있다.
    - 첫째 줄의 각 칸에는 정수 1, 2, …, N이 차례대로 들어 있고 둘째 줄의 각
   칸에는 1이상 N이하인 정수가 들어 있다.
   - 첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과, 뽑힌
   정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치한다.
    -이러한 조건을 만족시키도록 정수들을 뽑되, 최대로 많이 뽑는 방법을 찾는
   프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
vector<int> selectedNode;  // 최종으로 넣는 노드
bool visited[MAX];         // selectedNode에 들어가있는 노드들
bool visitedContact[MAX];  // cycle 찾으려할때 방문한 노드
vector<int> contact;       // cycle 찾으려 할때 노드 기록용

void dfs(int node, int firstNode) {
   contact.push_back(node);
   visitedContact[node] = true;

   for (int i = 0; i < graph[node].size(); i++) {
      int next = graph[node][i];

      if (!visitedContact[next]) {
         dfs(next, firstNode);
      }

      if (next == firstNode) {
         for (int j = 0; j < contact.size(); j++) {
            visited[contact[j]] = true;
            selectedNode.push_back(contact[j]);
         }
         break;
      }
   }
}

int main(void) {
   memset(visited, false, sizeof(visited));
   memset(visitedContact, false, sizeof(visitedContact));
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++) {
      int node;
      cin >> node;
      graph[i].push_back(node);
   }

   for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
         dfs(i, i);
         contact.clear();
         memset(visitedContact, false, sizeof(visitedContact));
      }
   }
   sort(selectedNode.begin(), selectedNode.end());

   cout << selectedNode.size() << endl;
   for (int i = 0; i < selectedNode.size(); i++) {
      cout << selectedNode[i] << endl;
   }
}