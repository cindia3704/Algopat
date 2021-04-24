/*
    작성자: 김지수
    작성일: 2021/04/24
    백준 -- 결혼식 (5567번)
    문제:
    - 상근이는 자신의 결혼식에 학교 동기 중 자신의 친구와 친구의 친구를
   초대하기로 했다.
    - 상근이의 동기는 모두 N명이고, 이 학생들의 학번은 모두 1부터 N까지이다.
   상근이의 학번은 1이다.
   -  결혼식에 초대할 사람의 수를 구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
   int node, height;
};
const int MAX = 500 + 1;
vector<int> graph[MAX];
bool visited[MAX];
vector<int> result;

void bfs(Node startNode) {
   queue<Node> friendComming;
   friendComming.push(startNode);
   visited[startNode.node] = true;

   while (!friendComming.empty()) {
      Node now = friendComming.front();
      friendComming.pop();

      for (int i = 0; i < graph[now.node].size(); i++) {
         int next = graph[now.node][i];

         if (!visited[next]) {
            Node nextNode;
            nextNode.node = next;
            nextNode.height = now.height + 1;

            friendComming.push(nextNode);
            visited[next] = true;
            if (nextNode.height > 0 && nextNode.height < 3) {
               result.push_back(nextNode.node);
            }
         }
      }
   }
}

int main(void) {
   Node start;
   memset(visited, false, sizeof(false));
   int friendNum, listLen;
   cin >> friendNum;
   cin >> listLen;

   for (int i = 0; i < listLen; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   start.node = 1;
   start.height = 0;
   bfs(start);
   cout << result.size() << endl;
}