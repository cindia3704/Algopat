/*
    작성자: 김지수
    작성일: 2022/05/16
    백준 -- 연결 요소의 개수 (1260번)
*/

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
int nodeNum, edgeNum;
vector<int> graph[MAX];
bool visited[MAX];

void bfs(int start) {
   queue<int> q;
   q.push(start);
   visited[start] = true;
   while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int i = 0; i < graph[now].size(); i++) {
         int next = graph[now][i];
         if (visited[next] == false) {
            visited[next] = true;
            q.push(next);
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> nodeNum >> edgeNum;
   for (int i = 0; i < edgeNum; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   memset(visited, false, sizeof(visited));

   int connectionComponentCount = 0;
   for (int i = 1; i <= nodeNum; i++) {
      if (visited[i] == false) {
         bfs(i);
         connectionComponentCount++;
      }
   }
   cout << connectionComponentCount;
}