/*
    작성자: 김지수
    작성일: 2021/08/06
    백준 -- 감시(15683번)
    문제:
    - 최대 8x8 인 사무실에 최대 8개의 cctv를 설치하려함
    - cctv는 5가지 종류 있고, 모두 90도 회전 가능하다
    - CCTV가 감시할 수 없는 영역은 사각지대라고 한다
    - 사각 지대의 최소 크기를 구하라
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 8;
int height, width;

int room[MAX_N][MAX_N];
struct CCTV {
   int x, y, type;
};
vector<CCTV> cctv;
const int dirs[5] = {4, 2, 4, 4, 1};  // 1~5번 cctv가 회전할수 있는 방법 개수
int answer = 64;                      // 사각지대 최대 크기 = 64 (8x8)

void backUp(int original[MAX_N][MAX_N], int backup[MAX_N][MAX_N]) {
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         backup[i][j] = original[i][j];
      }
   }
}

void fillUp(int direction, int x, int y) {
   direction = direction % 4;
   if (direction == 0) {  // 오른쪽
      while (x >= 0 && x < width) {
         if (room[y][x] == 6) {
            break;
         } else {
            room[y][x] = 7;
            x++;
         }
      }
   } else if (direction == 1) {  //아래
      while (y >= 0 && y < height) {
         if (room[y][x] == 6) {
            break;
         } else {
            room[y][x] = 7;
            y++;
         }
      }
   } else if (direction == 2) {  // 왼쪽
      while (x >= 0 && x < width) {
         if (room[y][x] == 6) {
            break;
         } else {
            room[y][x] = 7;
            x--;
         }
      }
   } else if (direction == 3) {  //위
      while (y >= 0 && y < height) {
         if (room[y][x] == 6) {
            break;
         } else {
            room[y][x] = 7;
            y--;
         }
      }
   }
}

int countNotZero() {
   int ans = 0;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         if (room[i][j] == 0) {
            ans++;
         }
      }
   }

   return ans;
}

void bfs(int start) {
   int roomCopy[MAX_N][MAX_N];
   if (start == cctv.size()) {
      // answer update
      int count = countNotZero();
      if (answer > count) {
         answer = count;
      }
   } else {
      int cctvType = cctv[start].type;
      int cctvX = cctv[start].x;
      int cctvY = cctv[start].y;

      for (int turnNum = 0; turnNum < dirs[cctvType]; turnNum++) {
         backUp(room, roomCopy);  // 초기 상태 복사  -> room 으로 기능 수행!
         if (cctvType == 0) {
            fillUp(turnNum, cctvX, cctvY);
         } else if (cctvType == 1) {
            fillUp(turnNum, cctvX, cctvY);
            fillUp(turnNum + 2, cctvX, cctvY);
         } else if (cctvType == 2) {
            fillUp(turnNum, cctvX, cctvY);
            fillUp(turnNum + 3, cctvX, cctvY);
         } else if (cctvType == 3) {
            fillUp(turnNum, cctvX, cctvY);
            fillUp(turnNum + 2, cctvX, cctvY);
            fillUp(turnNum + 3, cctvX, cctvY);
         } else if (cctvType == 4) {
            fillUp(turnNum, cctvX, cctvY);
            fillUp(turnNum + 1, cctvX, cctvY);
            fillUp(turnNum + 2, cctvX, cctvY);
            fillUp(turnNum + 3, cctvX, cctvY);
         }
         bfs(start + 1);
         backUp(roomCopy, room);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(room, -1, sizeof(room));

   cin >> height >> width;

   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> room[i][j];
         if (room[i][j] != 0 && room[i][j] != 6) {
            CCTV newCCTV;
            newCCTV.x = j;
            newCCTV.y = i;
            newCCTV.type = room[i][j] - 1;
            cctv.push_back(newCCTV);
         }
      }
   }

   bfs(0);
   cout << answer;
}