# 토마토 - 백준 7576번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/7576
<img width="1157" alt="스크린샷 2021-05-04 오후 4 10 49" src="https://user-images.githubusercontent.com/52744390/116970631-4b94b780-acf3-11eb-8532-4436481d8629.png">
<img width="1157" alt="스크린샷 2021-05-04 오후 4 11 01" src="https://user-images.githubusercontent.com/52744390/116970653-53545c00-acf3-11eb-9733-b0382858bbd0.png">

## 풀이: 
* 익은 토마토의 위치를 모두 파악해야함 (1개가 아닐수 있음) ➡️ 초기에 입력 받으며, 입력이 1인것을 queue에 저장하기 
* queue에 다음으로 방문해야할 위치(x,y좌표) & 해당 위치릐 토마토가 익는데 걸린 날(day)를 저장해야함 ➡️ struct 사용! 
* 입력이 -1인 경우 ➡️ 토마토 없음 BUT 모든 토마토가 익는데 걸리는 최소 날짜 구해야함. 즉, -1로 인해 다 못익을 수 있음 (상,하,좌,우로만 움직일 수 있기 때문) 
* 위 상황을 위해 방문한 위치 표시 & 마지막에 방문안했고, 그 값이 0 (안익은 토마토)인게 있는지 확인! 

## Code: 
1. 변수 선언 
```cpp
const int MAX_SIZE = 1000;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
bool visited[MAX_SIZE][MAX_SIZE];
int tomato[MAX_SIZE][MAX_SIZE];
int width, height;
struct Tomato {
   int x, y;
   int day;
};
queue<Tomato> q;
int ans = -1;
```
* dx & dy = 상하좌우 이동을 위해 필요! 
* visited = y,x 에 해당하는 자리 방문 여부 (초기에 memset을 이용해 모두 false로 초기) 
* tomato = 익은 토마토(1), 안익은 토마토(0), 토마토 없음(-1)을 입력 받는 변수 
* width,height = 창고의 가로 & 세로 
* Tomato = 토마토의 위치 & 익는데 걸린 날짜 저장을 위한 구조체 
* q = BFS에서 사용될 queue (FIFO) 
* ans = 최종 답! 


2. 초기 익은 토마토 위치 파악 
```cpp
for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> tomato[i][j];

         if (tomato[i][j] == 1) {
            Tomato start;
            start.y = i;
            start.x = j;
            start.day = 0;
            visited[i][j] = true;

            q.push(start);
         }
      }
   }
```
* 위 코드는 main 함수에 있음 
* 창고의 사이즈대로 입력받으며, 입력받은 값이 1(익은 토마토)면, BFS에서 사용할 queue에 넣어줌. 이때 이미 익은 토마토니, day = 0 
* queue에 넣으며 해당 위치를 이미 방문 했다 표시 

3. BFS 이용하여 안익은 토마토 익히기! 
```cpp
void getDaysForTomato() {
   while (!q.empty()) {
      Tomato now = q.front();
      int nowX = now.x;
      int nowY = now.y;
      int nowDay = now.day;
      ans = max(ans, nowDay);
      q.pop();

      for (int dir = 0; dir < 4; dir++) {
         Tomato next;
         next.x = nowX + dx[dir];
         next.y = nowY + dy[dir];
         next.day = nowDay + 1;

         if (next.x >= 0 && next.x < width && next.y >= 0 && next.y < height) {
            if (tomato[next.y][next.x] == 0 && !visited[next.y][next.x]) {
               q.push(next);
               visited[next.y][next.x] = true;
            }
         }
      }
   }
}
```
* 현 위치 & 날짜를 queue에서 가져옴. 
* 현 위치에서 갈수 있는 위치 (상하좌우)를 보며, 그 위치가 창고의 범위를 안넘어가고 & 0(안익은 토마토)인 경우 ➡️ queue에 넣고 방문 처리 

4. 안익은 토마토 있는지 확인 
```cpp
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (!visited[i][j] && tomato[i][j] == 0) {
            ans = -1;
         }
      }
   }
   cout << ans << endl;
```
* BFS 돌고 난 후 ➡️ BFS통해 방문 표시 완료 
* 즉 visited 가 아직 false일 경우는 2가지: 1.그 위치에 토마토가 없음 2.해당 자리를 방문할 수 없었음 
* 방문 할 수 없었으면, 창고에 있는 토마토 전체를 익게 할 수 없었으므로 최종답(ans)를 -1로 만듬 
   
## 결과: 
<img width="944" alt="스크린샷 2021-05-04 오후 4 26 08" src="https://user-images.githubusercontent.com/52744390/116972050-6ff19380-acf5-11eb-9e25-396d8a5ba7f5.png">
