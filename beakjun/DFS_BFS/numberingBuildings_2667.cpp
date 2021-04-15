/*
    작성자: 김지수
    작성일: 2021/04/14
    백준 -- 단지 번호 붙이기 (2667번)
    문제:
    - 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
    - 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를
   붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이
   있는 경우를 말한다.
   - 대각선상에 집이 있는 경우는 연결된 것이 아니다
   -첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를
   오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 25;
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];
char house[MAX][MAX];
vector<int> numBuilding;

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

int main(void) {
   memset(visited, false, sizeof(visited));
   cin >> n;

   for (int i = 0; i < n; i++) {
      cin >> house[i];
   }

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
   sort(numBuilding.begin(), numBuilding.end());
   cout << numBuilding.size() << endl;
   for (int i = 0; i < numBuilding.size(); i++) {
      cout << numBuilding[i] << endl;
   }
}