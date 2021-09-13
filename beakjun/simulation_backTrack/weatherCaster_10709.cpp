/*
    작성자: 김지수
    작성일: 2021/09/13
    백준 -- 기상캐스터 (10709번)
    문제:
    - WxH 크기의 직사각형에 1x1의 각 구역에 구름이 있을 수 있고 없을 수 있음
    - 모든 구름은 1분이 지날 때마다 1킬로미터씩 동쪽으로 이동
    - 기상청에서 일하고 있는 여러분은 각 구역에 대해서 지금부터 몇 분뒤 처음으로
   하늘에 구름이 오는지를 예측하는 일을 맡았다
*/

#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 100;
int height, width;
int sky[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void moveCloud(int y, int x) {
   int count = 0;
   for (int i = x + 1; i < width; i++) {
      count++;
      if (sky[y][i] == -1 || (sky[y][i] != -1 && sky[y][i] > count)) {
         sky[y][i] = count;
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         char input;
         cin >> input;
         if (input == 'c') {
            sky[i][j] = 0;
         } else {
            sky[i][j] = -1;
         }
      }
   }
   memset(visited, false, sizeof(visited));
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (sky[i][j] == 0) {
            visited[i][j] = true;
            moveCloud(i, j);
         }
      }
   }
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cout << sky[i][j] << " ";
      }
      cout << "\n";
   }
}