/*
    작성자: 김지수
    작성일: 2021/10/16
    백준 -- 톱니바퀴 (17140번)
    문제:
*/

#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
vector<deque<int> > wheels;
vector<pair<int, int> > turnInfo;
vector<pair<int, int> > turn;
const int scoreS[] = {1, 2, 4, 8};
bool turned[4];

// 마지막에 점수 부여
int calculatePoint() {
   int sum = 0;
   for (int i = 0; i < 4; i++) {
      if (wheels[i][0] == 1) {
         sum += scoreS[i];
      }
   }
   return sum;
}

void turnWheel(int wheelNum, int dir) {
   if (dir == 1) {
      int temp = wheels[wheelNum][7];
      wheels[wheelNum].pop_back();
      wheels[wheelNum].push_front(temp);
   } else {
      int temp = wheels[wheelNum][0];
      wheels[wheelNum].pop_front();
      wheels[wheelNum].push_back(temp);
   }
}

void turnAll(int wheelNum, int dir) {
   int nowR = 0, nowL = 0, next = 0, right = 0, left = 0;
   if (!turned[wheelNum]) {
      turned[wheelNum] = true;
   }
   switch (wheelNum) {
      case 0:
         nowR = wheels[wheelNum].at(2);
         next = wheels[wheelNum + 1].at(6);
         if (nowR != next && !turned[wheelNum + 1]) {
            turned[wheelNum + 1] = true;
            if (dir == 1) {
               turn.push_back(make_pair(wheelNum + 1, -1));
               turnAll(wheelNum + 1, -1);
            } else {
               turn.push_back(make_pair(wheelNum + 1, 1));
               turnAll(wheelNum + 1, 1);
            }
         }
         break;
      case 1:
         nowR = wheels[wheelNum].at(2);
         nowL = wheels[wheelNum].at(6);
         right = wheels[wheelNum + 1].at(6);
         left = wheels[wheelNum - 1].at(2);
         if (nowR != right && !turned[wheelNum + 1]) {
            turned[wheelNum + 1] = true;
            if (dir == 1) {
               turn.push_back(make_pair(wheelNum + 1, -1));
               turnAll(wheelNum + 1, -1);
            } else {
               turn.push_back(make_pair(wheelNum + 1, 1));
               turnAll(wheelNum + 1, 1);
            }
         }
         if (nowL != left && !turned[wheelNum - 1]) {
            turned[wheelNum - 1] = true;
            if (dir == 1) {
               turn.push_back(make_pair(wheelNum - 1, -1));
               turnAll(wheelNum - 1, -1);
            } else {
               turn.push_back(make_pair(wheelNum - 1, 1));
               turnAll(wheelNum - 1, 1);
            }
         }
         break;
      case 2:
         nowR = wheels[wheelNum].at(2);
         nowL = wheels[wheelNum].at(6);
         right = wheels[wheelNum + 1].at(6);
         left = wheels[wheelNum - 1].at(2);

         if (nowR != right && !turned[wheelNum + 1]) {
            turned[wheelNum + 1] = true;
            if (dir == 1) {
               turnWheel(wheelNum + 1, -1);
            } else {
               turnWheel(wheelNum + 1, 1);
            }
         }
         if (nowL != left && !turned[wheelNum - 1]) {
            turned[wheelNum - 1] = true;
            if (dir == 1) {
               turn.push_back(make_pair(wheelNum - 1, -1));
               turnAll(wheelNum - 1, -1);
            } else {
               turn.push_back(make_pair(wheelNum - 1, 1));
               turnAll(wheelNum - 1, 1);
            }
         }
         break;
      case 3:
         nowL = wheels[wheelNum].at(6);
         next = wheels[wheelNum - 1].at(2);
         if (nowL != next && !turned[wheelNum - 1]) {
            turned[wheelNum - 1] = true;
            if (dir == 1) {
               //    turnWheel(wheelNum - 1, -1);
               turn.push_back(make_pair(wheelNum - 1, -1));
               turnAll(wheelNum - 1, -1);
            } else {
               //    turnWheel(wheelNum - 1, 1);
               turn.push_back(make_pair(wheelNum - 1, 1));
               turnAll(wheelNum - 1, 1);
            }
         }
         break;
      default:
         break;
   }
}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   for (int i = 0; i < 4; i++) {
      deque<int> dq;
      string seq;
      cin >> seq;
      for (int j = 0; j < seq.length(); j++) {
         dq.push_back(seq[j] - '0');
      }
      wheels.push_back(dq);
   }
   int turnNum;
   cin >> turnNum;
   for (int i = 0; i < turnNum; i++) {
      int wheelNum, dir;
      cin >> wheelNum >> dir;
      turnInfo.push_back(make_pair(wheelNum - 1, dir));
   }

   for (int i = 0; i < turnNum; i++) {
      memset(turned, false, sizeof(turned));
      int wheelNum = turnInfo[i].first;
      int dir = turnInfo[i].second;

      turn.clear();
      turnAll(wheelNum, dir);
      turn.push_back(make_pair(wheelNum, dir));
      for (int i = 0; i < turn.size(); i++) {
         turnWheel(turn[i].first, turn[i].second);
      }
   }
   cout << calculatePoint();
}