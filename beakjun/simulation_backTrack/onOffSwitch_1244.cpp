/*
    작성자: 김지수
    작성일: 2021/09/17
    백준 -- 스위치 켜고 끄기 (1244번)
    문제:
    - 남자: 번호의 배수면 flip
    - 여자: 번호 중심으로 좌우 대칭이면 flip
*/

#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 101;
bool bulb[MAX_N];

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int lightNum;
   cin >> lightNum;
   for (int i = 1; i <= lightNum; i++) {
      cin >> bulb[i];
   }
   int studentNum;
   vector<pair<int, int> > student;
   cin >> studentNum;
   for (int i = 0; i < studentNum; i++) {
      int gender, number;
      cin >> gender >> number;
      student.push_back(make_pair(gender, number));
   }
   for (int i = 0; i < student.size(); i++) {
      int gen = student[i].first;
      int bulbNum = student[i].second;
      if (gen == 1) {
         for (int i = 1; i <= lightNum; i++) {
            if (i % bulbNum == 0) {
               bulb[i] = !bulb[i];
            }
         }
      } else {
         int startX = bulbNum, endX = bulbNum;
         while (startX >= 1 && endX <= lightNum) {
            startX--;
            endX++;
            if (bulb[startX] == bulb[endX]) {
               continue;
            } else {
               break;
            }
         }
         for (int i = startX + 1; i < endX; i++) {
            bulb[i] = !bulb[i];
         }
      }
   }
   for (int i = 1; i <= lightNum; i++) {
      cout << bulb[i] << " ";
      if (i % 20 == 0) {
         cout << "\n";
      }
   }
}