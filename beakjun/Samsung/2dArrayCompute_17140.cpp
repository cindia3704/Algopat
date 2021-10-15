/*
    작성자: 김지수
    작성일: 2021/10/15
    백준 -- 2차원 배열의 연산 (17140번)
    문제:
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 101;
int targetY, targetX, targetNum;
int nowH = 3, nowW = 3;
int board[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];
int countIdx[MAX_N];

void copyToBoard() {
   for (int i = 0; i < nowH; i++) {
      for (int j = 0; j < nowW; j++) {
         board[i][j] = temp[i][j];
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> targetY >> targetX >> targetNum;
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         cin >> board[i][j];
      }
   }

   int time = 0;
   while (true) {
      if (time >= MAX_N) {
         time = -1;
         break;
      }
      if (board[targetY - 1][targetX - 1] == targetNum) {
         break;
      } else {
         memset(temp, 0, sizeof(temp));
         int maxNum = 0;
         if (nowH >= nowW) {
            int maxW = 0;
            // 각 row 마다 계산
            for (int i = 0; i < nowH; i++) {
               memset(countIdx, 0, sizeof(countIdx));
               for (int j = 0; j < nowW; j++) {
                  countIdx[board[i][j]]++;
                  if (board[i][j] > maxNum) {
                     maxNum = board[i][j];
                  }
               }
               vector<pair<int, int> > v;
               for (int j = 1; j <= maxNum; j++) {
                  if (countIdx[j] > 0) {
                     v.push_back(make_pair(countIdx[j], j));
                  }
               }
               sort(v.begin(), v.end());

               for (int j = 0; j < v.size(); j++) {
                  temp[i][j * 2] = v[j].second;
                  temp[i][j * 2 + 1] = v[j].first;
               }
               int tempW = v.size() * 2;
               if (tempW > 100) {
                  tempW = 100;
               }
               if (tempW > maxW) {
                  maxW = tempW;
               }
            }
            nowW = maxW;
            copyToBoard();
         } else {
            int maxH = 0;
            // 각 col 마다 계산
            for (int i = 0; i < nowW; i++) {
               memset(countIdx, 0, sizeof(countIdx));
               for (int j = 0; j < nowH; j++) {
                  countIdx[board[j][i]]++;
                  if (board[j][i] > maxNum) {
                     maxNum = board[j][i];
                  }
               }
               vector<pair<int, int> > v;
               for (int j = 1; j <= maxNum; j++) {
                  if (countIdx[j] > 0) {
                     v.push_back(make_pair(countIdx[j], j));
                  }
               }
               sort(v.begin(), v.end());

               for (int j = 0; j < v.size(); j++) {
                  temp[j * 2][i] = v[j].second;
                  temp[j * 2 + 1][i] = v[j].first;
               }
               int tempH = v.size() * 2;
               if (tempH > 100) {
                  tempH = 100;
               }
               if (tempH > maxH) {
                  maxH = tempH;
               }
            }
            nowH = maxH;
            copyToBoard();
         }
      }
      time++;
   }

   cout << time;
}