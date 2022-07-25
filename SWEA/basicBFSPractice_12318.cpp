/*
    작성자: 김지수
    작성일: 2022/07/26
    SWEA -- 기초 BFS 연습 (12318번)
*/

#define QUEUE_SIZE 100

int board[10][10];
bool visited[10][10];

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

struct BLOCK {
   int x, y;
   int dist;
};

int boardSize;
int rear, front;
int qsize;
BLOCK q[QUEUE_SIZE];

bool isEmpty() {
   if (qsize == 0) {
      return true;
   }
   else {
      return false;
   }
}

void enqueue(BLOCK b) {
   rear = (rear + 1) % QUEUE_SIZE;
   q[rear] = b;
   qsize++;
   return;
}

BLOCK dequeue() {
   front = (front + 1) % QUEUE_SIZE;
   qsize-- ;
   return q[front];
}

void bfs_init(int map_size, int map[10][10]) {
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         board[i][j] = 0;
      }
   }
   boardSize = map_size;
   for (int i = 0; i < map_size; i++) {
      for (int j = 0; j < map_size; j++) {
         board[i][j] = map[i][j];
      }
   }
}
int bfs(int x1, int y1, int x2, int y2) {
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         visited[i][j] = false;
      }
   }
   front = -1;
   rear = -1;
   qsize = 0;
   visited[y1 - 1][x1 - 1] = true;
   BLOCK start;
   start.y = y1 - 1;
   start.x = x1 - 1;
   start.dist = 0;
   enqueue(start);
   bool found = false;
   int ans = 0;
   while (!isEmpty()) {
      BLOCK now = dequeue();
      if (now.y == y2 - 1 && now.x == x2 - 1) {
         found = true;
         ans = now.dist;
         break;
      }
      for (int i = 0; i < 4; i++) {
         int nextY = now.y + dy[i];
         int nextX = now.x + dx[i];
         if (nextY < 0 || nextY >= boardSize || nextX < 0 || nextX >= boardSize) {
            continue;
         }
         if (!visited[nextY][nextX] && board[nextY][nextX] == 0) {
            visited[nextY][nextX] = true;
            BLOCK next;
            next.y = nextY;
            next.x = nextX;
            next.dist = now.dist + 1;
            enqueue(next);
         }
      }
   }
   if (!found) {
      return -1;
   }
   else {
      return ans;
   }
}