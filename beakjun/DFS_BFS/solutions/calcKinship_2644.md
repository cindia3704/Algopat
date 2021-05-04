# 촌수 계산 - 백준 2644번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/2644
<img width="1154" alt="스크린샷 2021-05-04 오후 4 29 16" src="https://user-images.githubusercontent.com/52744390/116972371-e0001980-acf5-11eb-98c5-5bed104a05b6.png">   

## 풀이: 
* 먼저 나, 아버지, 아버지의 형제, 할아버지와의 관계 구조를 그리면 다음과 같이 나타낼수 있다. 
![IMG_F071F37A516C-1](https://user-images.githubusercontent.com/52744390/116972707-60267f00-acf6-11eb-9ec4-0931f44da443.jpeg)
   
* 언뜻 보면 트리 구조를 이용해 풀 수 있겠다 생각하겠지만, 문제에서 예시로 준 촌수 계산을 따라가 보면 다음과 같다. 
![IMG_0C45438371DA-1](https://user-images.githubusercontent.com/52744390/116972811-8cda9680-acf6-11eb-8ebf-fafb97a83d8e.jpeg)
   
* 나와 할아버지 = 2촌 (보라색 선)
* 나와 아버지의 형제 = 3촌(분홍색 선) 
* 따라서 관계를 양방향 그래프로 나타내고, 주어진 두 사람간의 거리를 구하면 된다. 

## Code: 
1. 변수 선언 
```cpp
const int MAX_N = 101;
vector<int> graph[MAX_N];
bool visited[MAX_N];
int find1, find2;
int ans = -1;
```
* graph = 가족 관계를 나타낼 양방향 그래프 (입력 받음) 
* visited = 노드 방문 여부 표시 
* find1, find2 = 두 노드 사이 거리를 구해야 할 노드들 (입력 받음)
* ans = 최종 답 
   
2. 양방향 그래프 만들기 
```cpp
   for (int i = 0; i < totalEdge; i++) {
      int n1, n2;
      cin >> n1 >> n2;
      graph[n1].push_back(n2);
      graph[n2].push_back(n1);
   }
```
* 연결된 두 노드를 입력 받으면 두번 푸씨하며 양방향 그래프 만듬 

3. DFS -- 두 노드간 거리를 구하면 되기 때문 (깊이 따라 감) 
```cpp 
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
```
* dfs 이기 때문에, 현재 방문한 노드가 find2면 최종답 업데이트!
* 지금 방문한 노드의 자식노드를 차례로 방문! (방문 표시 함) 

## 결과: 
<img width="931" alt="스크린샷 2021-05-04 오후 4 43 01" src="https://user-images.githubusercontent.com/52744390/116973641-cbbd1c00-acf7-11eb-951a-db53d8b622c2.png">
