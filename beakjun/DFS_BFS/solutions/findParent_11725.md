# 트리의 부모 찾기 - 백준 11725번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/11725   
<img width="1167" alt="스크린샷 2021-04-27 오후 2 05 03" src="https://user-images.githubusercontent.com/52744390/116188000-9184d500-a761-11eb-900c-480f63fe9d81.png">

   
## 풀이: 
* 입력으로부터 양방향 그래프를 생성 
* dfs, bfs로 그래프를 탐색하면서 현재 노드의 부모를 알아내면 됨 ➡️ BFS 가 같은 레벨에 있는 노드 (같은 부모 갖는 노드)를 순서대로 방문하기 떄문에 BFS 택함! 

## Code: 
1. 변수 선언 
```cpp
const int MAX_NODE = 100000 + 1;
vector<int> graph[MAX_NODE];
bool visited[MAX_NODE];
int parent[MAX_NODE];
queue<int> q;
```
* MAX_NODE가 100000+1인 이유 ➡️ 최대 노드 수  = 100000 BUT 1번 부터 시작! 
* graph = 양방향 그래프 
* visited = 각 노드 방문 여부 
* parent = bfs로 노드 방문 하며, 해당 노드의 부모 노드를 저장!
* q = bfs에서 사용할 큐 


2. 양방향 그래프 생성
```cpp
   cin >> totalNode;

   for (int i = 0; i < totalNode - 1; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
```

3. BFS로 방문하면서 각 노드의 부모 저장 
```cpp
void findParent(int start) {
   q.push(start);

   while (!q.empty()) {
      int nowNode = q.front();
      visited[nowNode] = true;
      q.pop();

      for (int i = 0; i < graph[nowNode].size(); i++) {
         int nextNode = graph[nowNode][i];
         if (!visited[nextNode]) {
            parent[nextNode] = nowNode;
            q.push(nextNode);
         }
      }
   }
}
```
* 방문하는 노드를 큐에 넣고, 다음 차례에서 q에서 하나 뺴서, 그 노드의 자식노드 모두 큐에 넣음! 
* 이때, for문에서 큐에 넣는 노드들 = 모두 부모노드가 같음! ➡️ parent배열에 해당 정보 저장 
* q에 아무런 element가 없으면 bfs 끝 & 모든 노드 방문 완료! 

5. 노드 2번부터 순서대로 부모 노드 출력! 
```cpp
for (int i = 2; i <= totalNode; i++) {
      cout << parent[i] << "\n";
   }
```
* 주의!! endl로 하면 시간초과 나옴!! 
   
   
## 결과: 
<img width="929" alt="스크린샷 2021-04-27 오후 2 13 41" src="https://user-images.githubusercontent.com/52744390/116188662-c6ddf280-a762-11eb-9d00-95316d7a870f.png">
