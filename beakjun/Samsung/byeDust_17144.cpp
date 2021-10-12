/*
    작성자: 김지수
    작성일: 2021/10/13
    백준 -- 미세먼지 안녕! (17144번)
    문제:
*/

#include <cstring>
#include <iostream>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const int MAX_N = 1001;
int height, width, untilTime;
int cleanerX1, cleanerX2, cleanerY1, cleanerY2;
int graph[MAX_N][MAX_N];

void copyToGraph(int t[MAX_N][MAX_N]) {
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         graph[i][j] = t[i][j];
      }
   }
   return;
}

long long calcDustAmount() {
   long long sum = 0;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         sum += graph[i][j];
      }
   }
   return sum;
}

void moveDust() {
   int temp[MAX_N][MAX_N];
   memset(temp, 0, sizeof(temp));

   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         temp[i][j] = graph[i][j];
      }
   }
   for (int j = 0; j < width; j++) {
      temp[cleanerY1][j + 1] = graph[cleanerY1][j];
   }
   for (int i = cleanerY1; i > 0; i--) {
      temp[i - 1][width - 1] = graph[i][width - 1];
   }
   for (int j = width - 1; j > 0; j--) {
      temp[0][j - 1] = graph[0][j];
   }
   for (int i = 0; i < cleanerY1; i++) {
      temp[i + 1][0] = graph[i][0];
   }

   for (int j = 0; j < width; j++) {
      temp[cleanerY2][j + 1] = graph[cleanerY2][j];
   }
   for (int i = cleanerY2; i < height; i++) {
      temp[i + 1][width - 1] = graph[i][width - 1];
   }
   for (int j = width - 1; j > 0; j--) {
      temp[height - 1][j - 1] = graph[height - 1][j];
   }
   for (int i = height - 1; i > cleanerY2; i--) {
      temp[i - 1][0] = graph[i][0];
   }
   temp[cleanerY1][cleanerX1] = 0;
   temp[cleanerY2][cleanerX2] = 0;

   copyToGraph(temp);
   return;
}

long long getDustAmount(int time) {
   long long answer = 0;
   while (true) {
      if (time == untilTime) {
         long long ret = calcDustAmount();
         answer = ret;
         break;
      } else {
         int temp[MAX_N][MAX_N];
         memset(temp, 0, sizeof(temp));
         for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
               int nowDustAmount = graph[i][j];
               int giveDustAmount = nowDustAmount / 5;
               int count = 0;
               if ((i == cleanerY1 && j == cleanerX1) ||
                   (i == cleanerY2 && j == cleanerX2)) {
                  continue;
               }
               for (int dir = 0; dir < 4; dir++) {
                  int nextY = i + dy[dir];
                  int nextX = j + dx[dir];
                  if (nextY < 0 || nextX < 0 || nextY >= height ||
                      nextX >= width ||
                      (nextY == cleanerY1 && nextX == cleanerX1) ||
                      (nextY == cleanerY2 && nextX == cleanerX2)) {
                     continue;
                  } else {
                     count++;
                     temp[nextY][nextX] += giveDustAmount;
                  }
               }
               temp[i][j] += (nowDustAmount - (count * giveDustAmount));
            }
         }

         copyToGraph(temp);
         moveDust();
         time++;
      }
   }
   return answer;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> height >> width >> untilTime;
   bool foundFirst = false;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         cin >> graph[i][j];
         if (graph[i][j] == -1 && foundFirst == false) {
            foundFirst = true;
            cleanerX1 = j;
            cleanerY1 = i;
            cleanerX1 = j;
            cleanerY2 = i + 1;
         }
      }
   }
   cout << getDustAmount(0);
}