/*
    작성자: 김지수
    작성일: 2021/07/21
    백준 -- 경로 찾기 (11403번)
    문제:
    - 가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서
   j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오
*/
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 100;
int graph[MAX_N][MAX_N];
bool visited[MAX_N];

void dfs(int startNode, int nodeNum) {
   for (int i = 0; i < nodeNum; i++) {
      int nextNode = graph[startNode][i];
      if (!visited[i] && nextNode == 1) {
         visited[i] = true;
         dfs(i, nodeNum);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int nodeNum;
   cin >> nodeNum;
   for (int i = 0; i < nodeNum; i++) {
      for (int j = 0; j < nodeNum; j++) {
         cin >> graph[i][j];
      }
   }

   for (int i = 0; i < nodeNum; i++) {
      memset(visited, false, sizeof(visited));
      dfs(i, nodeNum);
      for (int j = 0; j < nodeNum; j++) {
         if (visited[j]) {
            cout << "1 ";
         } else {
            cout << "0 ";
         }
      }
      cout << endl;
   }
}