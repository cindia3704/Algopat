/*
    작성자: 김지수
    작성일: 2021/10/05
    백준 -- 투명 (1531번)
    문제:
*/
#include <cstring>
#include <iostream>
using namespace std;
int visited[101][101];

int main(void) {
   memset(visited, 0, sizeof(visited));
   ios::sync_with_stdio(false);
   cin.tie(0);
   int invisibleNum, minNum;
   cin >> invisibleNum >> minNum;
   for (int i = 0; i < invisibleNum; i++) {
      int sy, sx, ey, ex;
      cin >> sx >> sy >> ex >> ey;
      for (int j = sy; j <= ey; j++) {
         for (int k = sx; k <= ex; k++) {
            visited[j][k]++;
         }
      }
   }
   int count = 0;
   for (int i = 1; i < 101; i++) {
      for (int j = 1; j < 101; j++) {
         if (visited[i][j] > minNum) {
            count++;
         }
      }
   }
   cout << count;
}