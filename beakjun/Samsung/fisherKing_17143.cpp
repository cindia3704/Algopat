/*
    작성자: 김지수
    작성일: 2021/10/19
    백준 -- 낚시왕 (17143번)
    문제:
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 102;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};
int height, width, sharkNum;
struct Shark {
   int y, x, speed, dir, size;
};

vector<Shark> sharkInfo[MAX_N][MAX_N];
int sharksCaught = 0;

int flipDir(int dir) {
   int ret;
   if (dir == 0) {
      ret = 1;
   } else if (dir == 1) {
      ret = 0;
   } else if (dir == 2) {
      ret = 3;
   } else {
      ret = 2;
   }
   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width >> sharkNum;
   for (int i = 0; i < sharkNum; i++) {
      Shark s;
      cin >> s.y >> s.x >> s.speed >> s.dir >> s.size;
      s.y -= 1;
      s.x -= 1;
      s.dir -= 1;
      // 다시 재자리로 + 같은 방향으로 돌아오는 경우!!! ** 주의~~ 이거 안하면
      // 시간초과!!
      if (s.dir == 1 || s.dir == 0) {
         s.speed %= ((height - 1) * 2);
      } else {
         s.speed %= ((width - 1) * 2);
      }
      sharkInfo[s.y][s.x].push_back(s);
   }
   int x = -1;
   while (++x <= width) {
      for (int i = 0; i < height; i++) {
         if (!sharkInfo[i][x].empty()) {
            sharksCaught += sharkInfo[i][x][0].size;
            sharkInfo[i][x].pop_back();
            break;
         }
      }
      vector<Shark> tempSharks[MAX_N][MAX_N];
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            if (sharkInfo[i][j].empty()) continue;
            Shark sharkNow = sharkInfo[i][j][0];
            sharkInfo[i][j].pop_back();

            int count = sharkNow.speed;
            int &nowDir = sharkNow.dir;
            int &nowY = sharkNow.y;
            int &nowX = sharkNow.x;
            while (count--) {
               int nextY = nowY + dy[nowDir];
               int nextX = nowX + dx[nowDir];
               if (nextY < 0 || nextX < 0 || nextY >= height ||
                   nextX >= width) {
                  nowDir = flipDir(nowDir);
               }
               nowY += dy[nowDir];
               nowX += dx[nowDir];
            }

            if (!tempSharks[nowY][nowX].empty()) {
               if (tempSharks[nowY][nowX][0].size < sharkNow.size) {
                  tempSharks[nowY][nowX].pop_back();
                  tempSharks[nowY][nowX].push_back(sharkNow);
               }
            } else {
               tempSharks[nowY][nowX].push_back(sharkNow);
            }
         }
      }
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            sharkInfo[i][j] = tempSharks[i][j];
         }
      }
   }
   cout << sharksCaught;
}