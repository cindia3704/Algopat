/*
    작성자: 김지수
    작성일: 2022/06/05
    백준 -- N과 M (7) (15656번)
    - 같은 수 여러번 골라도 됨
*/

#include <algorithm>
#include <iostream>
#define MAX 9
using namespace std;
int n, m;

int seq[MAX];
int pick[MAX];

void makeComb(int nowPick) {
   if (nowPick == m) {
      for (int i = 0; i < nowPick; i++) {
         cout << pick[i] << " ";
      }
      cout << '\n';
      return;
   } else {
      for (int i = 0; i < n; i++) {
         pick[nowPick] = seq[i];
         makeComb(nowPick + 1);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      cin >> seq[i];
   }
   sort(seq, seq + n);
   makeComb(0);
}