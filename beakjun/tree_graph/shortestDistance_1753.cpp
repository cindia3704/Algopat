/*
    작성자: 김지수
    작성일: 2021/09/09
    백준 --  최단 경로 (1753번)
    문제:방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단
   경로를 구하는 프로그램을 작성하시오
*/

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_NODE = 20001;
const int MAX_NUM = 300001;
// 가리키는 노드 번호 , weight
vector<pair<int, int> > graph[MAX_NODE];
// 거리,노드
priority_queue<pair<int, int> > nextNodes;
int shortestDistance[MAX_NODE];

void dijkstra(int start) {
   nextNodes.push(make_pair(0, start));
   while (!nextNodes.empty()) {
      int distance = -nextNodes.top().first;
      int nowNode = nextNodes.top().second;
      nextNodes.pop();
      if (distance > shortestDistance[nowNode]) continue;
      for (int i = 0; i < graph[nowNode].size(); i++) {
         int nextNode = graph[nowNode][i].first;
         int weight = graph[nowNode][i].second;
         int nowDistance = distance + weight;

         if (shortestDistance[nextNode] > nowDistance) {
            shortestDistance[nextNode] = nowDistance;
            nextNodes.push(make_pair(-nowDistance, nextNode));
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   fill(shortestDistance, shortestDistance + MAX_NODE, MAX_NUM);

   int nodeNum, edgeNum, startNode;
   cin >> nodeNum >> edgeNum;
   cin >> startNode;
   shortestDistance[startNode] = 0;
   for (int i = 0; i < edgeNum; i++) {
      int u, v, weight;
      cin >> u >> v >> weight;
      graph[u].push_back(make_pair(v, weight));
   }
   dijkstra(startNode);
   for (int i = 1; i <= nodeNum; i++) {
      if (shortestDistance[i] == MAX_NUM) {
         cout << "INF" << endl;
      } else {
         cout << shortestDistance[i] << endl;
      }
   }
}
