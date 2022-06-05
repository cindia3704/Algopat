/*
    작성자: 김지수
    작성일: 2022/06/05
    백준 -- N과 M (8) (15657번)
    - 같은 수 여러번 골라도 됨
*/

#include <algorithm>
#include <iostream>
#define MAX 9
using namespace std;
int n, m;
int seq[MAX];
int pick[MAX];

void makeComb(int nowPick, int start) {
   if (nowPick == m) {
      for (int i = 0; i < nowPick; i++) {
         cout << pick[i] << " ";
      }
      cout << '\n';
      return;
   } else {
      for (int i = start; i < n; i++) {
         pick[nowPick] = seq[i];
         // 방금 뽑은 수보다 크거나 같은 수가 다음수여야함.
         makeComb(nowPick + 1, i);
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
   makeComb(0, 0);
}