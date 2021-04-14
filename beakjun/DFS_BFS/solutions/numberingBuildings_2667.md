# 단지 번호 붙이기 - 백준 2667번 풀이
   
## 문제: 
link : https://www.acmicpc.net/problem/2667   
<img width="1143" alt="스크린샷 2021-04-15 오전 5 10 17" src="https://user-images.githubusercontent.com/52744390/114772534-e0695c80-9da8-11eb-8321-261dfd032171.png">
<img width="1143" alt="스크린샷 2021-04-15 오전 5 10 29" src="https://user-images.githubusercontent.com/52744390/114772555-e6f7d400-9da8-11eb-8d70-59718055e68e.png">

   
## 풀이: 
결국 주어진 입력중 인접한 공간이 1일때 연결되는 그래프라고 생각하면 된다.   
그후: 
   1. 총 단지수 = 연결되지 않은 그래프의 총 수 
   2. 단지 내의 집수 = 각 그래프당 노드 개수 

## Code: 
1. 문제에서 연결 조건 = 현 위치로 부터 상, 하, 좌, 우. 따라서 dx 와 dy를 다음과 같이 정의:  
순서대로 위, 오른쪽, 아래, 왼쪽을 나타낸다. 
```cpp
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
```

2. 입력을 저장해놔야한다. 이때 입력이 띄어쓰기 없이 들어옴. 따라서 char로 받아서 저장. 
```cpp
char house[MAX][MAX];

for (int i = 0; i < n; i++) {
      cin >> house[i];
}
```
3. 입력이 1이고, 아직 방문하지 않은 곳이면: 
- 총 단지수 증가 
- 해당 단지 내의 집 수 알아내기 
```cpp
for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         int count = 0;
         if (house[i][j] == '1' && visited[i][j] == false) {
            count++;
            count = dfs(i, j, count);
            numBuilding.push_back(count);
         }
     }
}
```
위 코드에서 count = 해당 단지의 집 수를 뜻함. (단지마다 집을 처음 셀때 0부터 시작해야하므로 for문 안에서 초기화)   
총 단지수에 대한 변수를 따로 설정하지 않고, 단지 찾을때 마다 'numBuilding' vector에 넣음 ( 즉, numBuilding의 사이즈가 총 단지 수)   
   
4. 한 단지내의 집 수 알아내기
```cpp
int dfs(int i, int j, int count) {
   visited[i][j] = true;
   for (int step = 0; step < 4; step++) {
      int nextX = i + dx[step];
      int nextY = j + dy[step];
      if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n) {
         if (!visited[nextX][nextY] && house[nextX][nextY] == '1') {
            visited[nextX][nextY] = true;
            count++;
            count = dfs(nextX, nextY, count);
         }
      }
   }
   return count;
}
```
- 먼저 해당 집을 방문했다는 표시 ➡️ visited = true 
- 상, 하, 좌, 우에 아직 방문 안했고 집이 있음 (1이다) = count 증가 <- 즉 단지 내 집 수 증가    
- 그리고 거기에서 다시 dfs 부름 ( 그 위치 방문했다고 표시 & 상,하,좌,우 확인해서 연결된 집 찾기)   
__** 주의!! 상,하,좌,우 확인 시 boundary 조건 잘 확인하자!__

5. 단지 내 집 수를 오름차순 정렬: 
```cpp
   sort(numBuilding.begin(), numBuilding.end());
```
## 결과: 
<img width="914" alt="스크린샷 2021-04-15 오전 5 29 02" src="https://user-images.githubusercontent.com/52744390/114774772-7ef6bd00-9dab-11eb-8f09-458c1e5b795c.png">

