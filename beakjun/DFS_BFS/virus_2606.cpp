/*
    작성자: 김지수
    작성일: 2021/04/24
    백준 -- 바이러스 (2606번)
    문제:
    - 신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다
    - 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는
   모든 컴퓨터는 웜 바이러스에 걸리게 된다
   - 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_COMPUTER = 100 + 1;
int numOfComputer, numOfLinks;
vector<int> graph[MAX_COMPUTER];
bool visited[MAX_COMPUTER];

void findAllInfectedComputer(int startNode) {
   visited[startNode] = true;
   int siblingSize = graph[startNode].size();
   for (int i = 0; i < siblingSize; i++) {
      int nextNode = graph[startNode][i];
      if (!visited[nextNode]) {
         findAllInfectedComputer(nextNode);
      }
   }
}
int countInfected() {
   int count = 0;
   for (int i = 2; i <= numOfComputer; i++) {
      if (visited[i] == true) {
         count++;
      }
   }
   return count;
}

int main(void) {
   memset(visited, false, sizeof(visited));
   cin >> numOfComputer;
   cin >> numOfLinks;

   for (int i = 0; i < numOfLinks; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      graph[node1].push_back(node2);
      graph[node2].push_back(node1);
   }

   findAllInfectedComputer(1);
   cout << countInfected() << endl;
}