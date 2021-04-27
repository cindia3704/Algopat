/*
    작성자: 김지수
    작성일: 2021/04/27
    백준 -- 알파벳 (1987번)
    문제:
    - 세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다.
    -  보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열)
   에는 말이 놓여 있다.
   - 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한
   칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야
   한다
   -  말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오
   -  말이 지나는 칸은 좌측 상단의 칸도 포함된다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//상하좌우
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MAX_B = 20;
int width, height;
char board[MAX_B][MAX_B];
vector<int> ans;
bool visited[MAX_B][MAX_B];
int maxNum = 0;

void dfs(int startY, int startX) {
   visited[startY][startX] = true;
   ans.push_back(board[startY][startX]);
   maxNum = maxNum > ans.size() ? maxNum : ans.size();

   for (int i = 0; i < 4; i++) {
      int nextY = startY + dy[i];
      int nextX = startX + dx[i];
      int nextAlpha = board[nextY][nextX];
      bool found = find(ans.begin(), ans.end(), nextAlpha) != ans.end();

      if (!visited[nextY][nextX] && !found && nextX >= 0 && nextX < width &&
          nextY >= 0 && nextY < height) {
         dfs(nextY, nextX);

         visited[nextY][nextX] = false;
         ans.erase(remove(ans.begin(), ans.end(), nextAlpha));
      }
   }
}

int main(void) {
   memset(visited, false, sizeof(visited));
   cin >> height >> width;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> board[i][j];
      }
   }
   dfs(0, 0);
   cout << maxNum << endl;
}