/*
    작성자: 김지수
    작성일: 2021/06/25
    백준 -- 섬의 개수 (4963번)
    문제:
    - 두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서
   갈 수 있는 경로가 있어야 한다.
    - 섬의 개수를 세는 프로그램을 작성하시오.
*/

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 50;
//동서남북 & 대각선들
const int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int answer;
vector<int> result;

void bfs(int y, int x, int height, int width) {
   answer++;
   queue<pair<int, int> > q;
   visited[y][x] = true;
   q.push(make_pair(y, x));
   while (!q.empty()) {
      int nowX = q.front().second;
      int nowY = q.front().first;
      q.pop();
      for (int dir = 0; dir < 8; dir++) {
         int nextX = nowX + dx[dir];
         int nextY = nowY + dy[dir];
         // 확인하는 범위(다음 x & y) 체크 해야함!
         if (nextX > -1 && nextX < width && nextY > -1 && nextY < height &&
             graph[nextY][nextX] == 1 && visited[nextY][nextX] == false) {
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = true;
         }
      }
   }
}

void handle(int width, int height) {
   if (width != 0 && height != 0) {
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            if (graph[i][j] == 1 && visited[i][j] == false) {
               bfs(i, j, height, width);
            }
         }
      }
      result.push_back(answer);
   }
}

int main(void) {
   int width, height;
   do {
      cin >> width >> height;
      answer = 0;
      memset(visited, false, sizeof(visited));
      memset(graph, -1, sizeof(graph));
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            cin >> graph[i][j];
         }
      }
      handle(width, height);
   } while (width != 0 && height != 0);

   //결과 출력
   for (int i = 0; i < result.size(); i++) {
      cout << result[i] << endl;
   }
}