# 바이러스 - 백준 2606번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/2606   
<img width="1157" alt="스크린샷 2021-04-24 오전 3 08 44" src="https://user-images.githubusercontent.com/52744390/115912511-62910980-a4aa-11eb-963b-fc08ce4a7b3a.png">
   
   
## 풀이: 
입력으로 주어지는 node & edge 는, 서로 연결되지 않은 그래프들로 나뉘어 질수 있다.    
이때, 노드 1번과 한 그래프 상에 있는 모든 노드를 찾고, 노드 1을 제외한 그래프 상의 노드 개수를 반환하면 된다. 
   
   
## Code: 
1. 변수 선언 
```cpp
const int MAX_COMPUTER = 100 + 1;    
int numOfComputer, numOfLinks;
vector<int> graph[MAX_COMPUTER];
bool visited[MAX_COMPUTER];
```
* MAX_COMPUTER 이 100+1인 이유? ➡️ 최대 입력될수 있는 노드수 = 100. 하지만, 노드가 1번 부터 시작!  ➡️ 즉, 100개의 노드가 있다면 1~101번 일것이기 때문! 
* numOfComputer = 노드 개수, numOfLinks = edge수
   
   
2. 입력 받아서 그래프로 만들기 
```cpp
   memset(visited, false, sizeof(visited));
   cin >> numOfComputer;
   cin >> numOfLinks;

   for (int i = 0; i < numOfLinks; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      graph[node1].push_back(node2);
      graph[node2].push_back(node1);
   }
```
* 첫줄은 visited 배열의 값을 모두 false로 초기화 하기 위함! 
* for 문에서 edge이루는 node 두개 입력받음! 방향 없기 때문에 --> 양방향 그래프로 만듬! 
   
   
3. 1번 노드와 연결된 모든 노드 찾기 (DFS) 
```cpp
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
```
* 재귀로 DFS(깊이 우선 탐색)! 
* 새로운 노드 방문 할 때 마다 visited = true로 설정한다. 
* 다음으로 방문 할 노드는 현재 노드와 연결되어있고, visited = false이 것들! 
   
   
4. 1번 노드를 제외한 그래프 상의 노드 개수 찾기 
```cpp
int countInfected() {
   int count = 0;
   for (int i = 2; i <= numOfComputer; i++) {
      if (visited[i] == true) {
         count++;
      }
   }
   return count;
}
```
* 방문된 노드들, 즉 visited = true인 애들 = 바이러스 전염된 노드들! 
* 노드 1은 제외해야하므로, for 문은 노드2 부터 시작! 
   
## 결과: 
<img width="924" alt="스크린샷 2021-04-24 오전 3 22 05" src="https://user-images.githubusercontent.com/52744390/115913957-40988680-a4ac-11eb-8fe6-803a3b1b0712.png">
