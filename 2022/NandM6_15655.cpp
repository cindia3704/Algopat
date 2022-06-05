/*
    작성자: 김지수
    작성일: 2022/06/05
    백준 -- N과 M (6) (15655번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 9

int seq[MAX];
int pick[MAX];

using namespace std;
void makeCombination(int total, int totalPickNum, int nowPick, int start) {
   if (nowPick == totalPickNum) {
      for (int i = 0; i < nowPick; i++) {
         cout << pick[i] << " ";
      }
      cout << '\n';
      return;
   }
   for (int i = start; i < total; i++) {
      pick[nowPick] = seq[i];
      makeCombination(total, totalPickNum, nowPick + 1, i + 1);
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int seqLength, pickNum;
   cin >> seqLength >> pickNum;

   for (int i = 0; i < seqLength; i++) {
      cin >> seq[i];
   }
   sort(seq, seq + seqLength);
   makeCombination(seqLength, pickNum, 0, 0);
}