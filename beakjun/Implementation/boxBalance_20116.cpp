/*
    작성자: 김지수
    작성일: 2022/03/15
    백준 -- 상자 균형 (20116번)
    문제:
*/

#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 200001;
int boxSize, boxNum;
double boxes[MAX];
double prefixSum[MAX];

bool check(int idx) {
   double sx, ex;
   sx = -boxSize + boxes[idx];
   ex = boxSize + boxes[idx];
   double midPoint = prefixSum[idx] / idx;
   if (midPoint > sx && midPoint < ex) {
      return true;  // stables
   } else {
      return false;  // unstable
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> boxNum >> boxSize;
   for (int i = boxNum - 1; i >= 0; i--) {
      cin >> boxes[i];
   }
   memset(prefixSum, 0, sizeof(prefixSum));
   for (int i = 1; i <= boxNum; i++) {
      prefixSum[i] = prefixSum[i - 1] + boxes[i - 1];
   }

   for (int i = 1; i < boxNum; i++) {
      if (check(i)) {
         continue;
      } else {
         cout << "unstable";
         return 0;
      }
   }
   cout << "stable";
}