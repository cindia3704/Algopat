/*
    작성자: 김지수
    작성일: 2021/10/04
    백준 -- 돌려 돌려 돌림판 (11504번)
    문제:
*/

#include <math.h>

#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tc;
   cin >> tc;
   while (tc--) {
      int seqSize, digitSize;
      cin >> seqSize >> digitSize;
      int num1[digitSize];
      int num2[digitSize];
      int seq[seqSize];
      int count = 0;
      for (int i = 0; i < digitSize; i++) {
         cin >> num1[i];
      }
      for (int i = 0; i < digitSize; i++) {
         cin >> num2[i];
      }
      for (int i = 0; i < seqSize; i++) {
         cin >> seq[i];
      }
      int n1 = 0;
      int n2 = 0;
      int digit = pow(10, digitSize - 1);
      for (int i = 0; i < digitSize; i++) {
         n1 += digit * (num1[i]);
         n2 += digit * (num2[i]);
         digit /= 10;
      }
      for (int i = 0; i < seqSize; i++) {
         bool found = true;
         int digit = pow(10, digitSize - 1);
         int tempNum = 0;
         for (int j = 0; j < digitSize; j++) {
            int nowIdx = (i + j) % seqSize;
            tempNum += digit * (seq[nowIdx]);
            digit /= 10;
         }
         if (tempNum >= n1 && tempNum <= n2) {
            count++;
         }
      }
      cout << count << endl;
   }
}