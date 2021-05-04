# 숨바꼭질 - 백준 1697번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/1697
<img width="1238" alt="스크린샷 2021-05-04 오후 2 32 24" src="https://user-images.githubusercontent.com/52744390/116964078-8c85cf80-ace5-11eb-84f7-f64ed6b7c4e7.png">
   
## 풀이: 
* 수빈이의 위치로부터 수빈이의 동생이 있는 위치까지 가야함. 따라서 수빈이의 위치를 root로 생각하고, 계속 자식 노드 추가하며 해당 자식 노드가 수빈이 동생의 위치와 같은지 확인하면 됨. 
* 자식노드 만드는 방법? ➡️ 수빈이가 현 위치에서 갈 수 있는 노드들로! (BFS) 
* 수빈이는 X - 1 / X + 1 / 2 * X 의 자리로 이동할 수 있다. (현재 자리가 X일때!) 
* 따라서 각 노드는 3개의 자식을 가짐! BUT 시간제한으로 인해 visited 하나둬서 해당 노드를 이미 방문 한적 있다면 자식노드 추가하지 않음! 
* 수빈이가 동생을 찾는 가장 짧은 시간을 구해야 하기 때문에 각 노드를 방문한 시간도 가지고 있어야함! 

    
## Code: 
1. 변수 선언 
```cpp
const int MAX_N = 100001;
int me, sis;
bool visited[MAX_N];
```
* me = 수빈이의 위치 (입력 받음) 
* sis = 수빈이의 동생의 위치 (입력 받음) 
* visited = 해당 index값을 갖는 노드를 방문 했는지 여부 ➡️ main함수에서 memset을 이용해 false로 모두 초기화 
* MAX_N이 100001인 이유? ➡️ 수빈이 / 동생의 최대 위치 = 100000 BUT 노드가 1부터 시작! 따라서 +1 

2. BFS 
```cpp
int findSis(int start) {
   queue<pair<int, int> > locAndTime;
   locAndTime.push(make_pair(start, 0));
   visited[start] = true;

   while (!locAndTime.empty()) {
      int loc = locAndTime.front().first;
      int time = locAndTime.front().second;
      locAndTime.pop();

      if (loc == sis) {
         return time;
      }
      if (loc * 2 < MAX_N && !visited[loc * 2]) {
         locAndTime.push(make_pair(loc * 2, time + 1));
         visited[loc * 2] = true;
      }
      if (loc + 1 < MAX_N && !visited[loc + 1]) {
         locAndTime.push(make_pair(loc + 1, time + 1));
         visited[loc + 1] = true;
      }
      if (loc - 1 >= 0 && !visited[loc - 1]) {
         locAndTime.push(make_pair(loc - 1, time + 1));
         visited[loc - 1] = true;
      }
   }
}
```
* locAndTime = 다음에 방문해야 할 노드들 넣어두는 queue(FIFO)! pair<int,int>로 만든 이유? ➡️ 노드 & 해당 노드 방문한 시간을 모두 저장해야함! 
* 수빈이의 위치를 root로 만들기로 했기 때문에 맨 처음에 queue에 넣어줌! + 방문 표시! 
* queue가 빔(그래프를 모두 탐색함) or 수빈이 동생 위치에 도달 ➡️  종료! 
* while문에서 queue에서 맨 앞에서 하나씩 빼서 node & time 얻고 수빈이 동생 찾았는지 check & 해당 노드에서 갈수 있는 다음 노드 queue에 넣기
* 한번 방문한 노드는 다시 방문 안하기 위해 if 문에서 queue에 넣으며 방문 처리! WHY? ➡️ queue의 front에서 빼며 방문 처리 하면, 그 노드를 빼기 전까지는 방문을 안했다고 표시 되어 계속 같은 노드가 넣어질 수 있음 
* 주의!! 다음으로 방문 할 위치의 범위!!! 

## 결과: 
<img width="925" alt="스크린샷 2021-05-04 오후 2 48 53" src="https://user-images.githubusercontent.com/52744390/116965016-da033c00-ace7-11eb-89eb-695d32750bc4.png">
