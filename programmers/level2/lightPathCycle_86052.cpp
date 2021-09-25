/*
    작성자: 김지수
    작성일: 2021/09/25
    programmers -- 빛의 경로 사이클 (86052번)
*/
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <vector>

using namespace std;
const int MAX_N = 500;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

char graph[MAX_N][MAX_N];
// 시작 노드, 다음 노드, in dir
bool visited[MAX_N][MAX_N][4];
int startY = -1, startX = -1, startDir = -1;
vector<int> answer;
struct INFO {
   int y, x, count, dir;
};

int changeDir(char c, int dir) {
   if (c == 'R') {
      return (dir + 1) % 4;
   } else if (c == 'L') {
      return (dir + 3) % 4;

   } else {
      return dir % 4;
   }
}

void bfs(int y, int x, int dir, int count, int h, int w) {
   queue<INFO> q;
   INFO start;
   start.y = y;
   start.x = x;
   start.count = count;
   start.dir = dir;
   q.push(start);
   visited[y][x][dir] = true;
   while (!q.empty()) {
      int nowY = q.front().y;
      int nowX = q.front().x;
      int nowCount = q.front().count;
      int nowDir = q.front().dir;
      q.pop();

      int nextDir = changeDir(graph[nowY][nowX], nowDir);
      int nextY = ((nowY + dy[nextDir]) >= 0) ? (nowY + dy[nextDir]) % h
                                              : (nowY + dy[nextDir] + h) % h;
      int nextX = ((nowX + dx[nextDir]) >= 0) ? (nowX + dx[nextDir]) % w
                                              : (nowX + dx[nextDir] + w) % w;

      if (visited[nextY][nextX][nextDir]) {
         answer.push_back(nowCount);
         return;
      } else {
         INFO next;
         next.y = nextY;
         next.x = nextX;
         next.dir = nextDir;
         next.count = nowCount + 1;
         q.push(next);
         visited[nextY][nextX][nextDir] = true;
      }
   }
}

vector<int> solution(vector<string> grid) {
   int h = grid.size();
   int w = grid[0].length();
   for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
         graph[i][j] = grid[i][j];
      }
   }
   memset(visited, false, sizeof(visited));

   for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
         for (int k = 0; k < 4; k++) {
            if (!visited[i][j][k]) {
               bfs(i, j, k, 1, h, w);
            }
         }
      }
   }
   sort(answer.begin(), answer.end());
   return answer;
}