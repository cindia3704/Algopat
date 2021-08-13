/*
    작성자: 김지수
    작성일: 2021/08/13
    백준 -- 주지수 (15724번)
    문제:
    - 1X1의 단위 구역을 여러 개 묶어서 하나의 거대 행정구역인 주지수(마을의 땅을
   셈)를 만들 예정
    - 4개의 숫자로 직사각형 범위 알려주면 -> 사는 사람 수 합 구하라
*/

#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 1024;
int village[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int countPeople(int y, int x) {
   int& ret = cache[y][x];
   if (y == 0 && x == 0) {
      ret = village[y][x];
   }
   if (y < 0 || x < 0) {
      return 0;
   }
   if (ret != -1) {
      return ret;
   } else {
      ret = village[y][x] + countPeople(y - 1, x) + countPeople(y, x - 1) -
            countPeople(y - 1, x - 1);
   }
   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(cache, -1, sizeof(cache));
   int height, width;
   cin >> height >> width;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> village[i][j];
      }
   }
   int num;
   cin >> num;
   for (int i = 0; i < num; i++) {
      int startY, startX, endY, endX;
      cin >> startY >> startX >> endY >> endX;
      int total = countPeople(endY - 1, endX - 1);
      total -=
          countPeople(startY - 2, endX - 1) + countPeople(endY - 1, startX - 2);
      total += countPeople(startY - 2, startX - 2);
      cout << total << "\n";
   }
}