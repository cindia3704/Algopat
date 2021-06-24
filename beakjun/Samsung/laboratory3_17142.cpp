/*
    작성자: 김지수
    작성일: 2021/06/25
    백준 -- 연구소 3 (17142번)
    문제:
    - 바이러스는 활성 상태와 비활성 상태가 있다
    -가장 처음에 모든 바이러스는 비활성 상태이고, 활성 상태인 바이러스는
   상하좌우로 인접한 모든 빈 칸으로 동시에 복제되며, 1초가 걸린다
    -  승원이는 연구소의 바이러스 M개를 활성 상태로 변경하려고 한다.
    -  0은 빈 칸, 1은 벽, 2는 바이러스의 위치이다.
    -연구소의 상태가 주어졌을 때, 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간을
   구해보자.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
const int MAX_N = 50;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int answer = 987654321;
int lab[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void bfs() {
   memset(visited, false, sizeof(visited));
   int temp[n][n];
   queue<pair<pair<int, int>, int> > q;

   // temp 로 하나 복사본 만들어서 진행
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         temp[i][j] = lab[i][j];
         if (lab[i][j] == -3) {  // 활성화된 바이러스
            q.push(make_pair(make_pair(i, j), 0));
            visited[i][j] = true;
            temp[i][j] = -1;
         }
         if (lab[i][j] == -2) {  // 벽은 볼 필요 없어서 방문 처리
            visited[i][j] = true;
         }
      }
   }

   while (!q.empty()) {
      int nowY = q.front().first.first;
      int nowX = q.front().first.second;
      int nowVal = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
         int nextY = nowY + dy[i];
         int nextX = nowX + dx[i];

         // -1부터 보는 이유는 비활성 바이러스에 활성 바이러스가 가면 비활->활
         // 로 바뀌기 때문
         if (nextY > -1 && nextY < n && nextX > -1 && nextX < n &&
             visited[nextY][nextX] == false && temp[nextY][nextX] >= -1) {
            int nextVal = nowVal + 1;
            temp[nextY][nextX] = nextVal;
            q.push(make_pair(make_pair(nextY, nextX), nextVal));
            visited[nextY][nextX] = true;
         }
      }
   }

   int maxNum = 0;
   bool all = false;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (temp[i][j] > 0 && lab[i][j] == 0) {
            maxNum = max(maxNum, temp[i][j]);
         }
         if (temp[i][j] == 0) {
            all = true;
            break;
         }
      }
   }
   if (!all) {
      answer = min(answer, maxNum);
   }
}

void getCombination(int count, int y, int x) {
   if (count == m) {
      bfs();
   }
   for (int i = y; i < n; i++) {
      for (int j = x; j < n; j++) {
         if (lab[i][j] == -1) {
            lab[i][j] = -3;  // 활성화된 바이러스 = -3
            getCombination(count + 1, i, j);
            lab[i][j] = -1;
         }
      }
      // x=0을 해줘야하는 이유? 다음에 불릴때 j=x 부터 시작하고 난 뒤, 다음 row
      // 로 가면 다시 0부터 봐야해서!!
      x = 0;
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         int num;
         cin >> num;
         if (num == 1) {  // 벽은 -2로
            lab[i][j] = -2;
         } else if (num == 2) {  // 바이러스 = -1로
            lab[i][j] = -1;
         } else {  // 빈공간 = 0
            lab[i][j] = num;
         }
      }
   }

   getCombination(0, 0, 0);
   //빈칸에 바이러스를 다 옮기지 못한경우 -1 출력
   if (answer == 987654321) {
      cout << -1;
   } else {
      cout << answer;
   }
}