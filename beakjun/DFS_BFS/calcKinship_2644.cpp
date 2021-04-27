/*
    작성자: 김지수
    작성일: 2021/04/27
    백준 -- 촌수 계산 (2644번)
    문제:
    - 우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한
   문화를 가지고 있다.
    - 본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를
   계산한다.
   -  예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는
   2촌이 되고, 아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이
   된다.
   - 여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의
   촌수를 계산하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 101;
vector<int> graph[MAX_N];
bool visited[MAX_N];
int find1, find2;
int ans = -1;
void findKinShip(int start, int height) {
   visited[start] = true;
   if (start == find2) {
      ans = height;
   }
   for (int i = 0; i < graph[start].size(); i++) {
      if (!visited[graph[start][i]]) {
         findKinShip(graph[start][i], height + 1);
         visited[graph[start][i]] = true;
      }
   }
}
int main(void) {
   memset(visited, false, sizeof(visited));
   int totalNode, totalEdge;
   cin >> totalNode;
   cin >> find1 >> find2;
   cin >> totalEdge;
   for (int i = 0; i < totalEdge; i++) {
      int n1, n2;
      cin >> n1 >> n2;
      graph[n1].push_back(n2);
      graph[n2].push_back(n1);
   }
   findKinShip(find1, 0);
   cout << ans << endl;
}
