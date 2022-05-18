/*
    작성자: 김지수
    작성일: 2022/05/18
    백준 -- N과 M(3) (15651번)
    -> N개 중 중복있을수 있게 M개 고르기
*/

#include <iostream>
#define MAX 8
using namespace std;
int n, m;
int pick[MAX];

void pickCard(int pickCount) {
   if (pickCount == m) {
      for (int i = 0; i < m; i++) {
         cout << pick[i] << " ";
      }
      cout << "\n";
      return;
   } else if (pickCount > m) {
      return;
   } else {
      // 중복없이 뽑아서 뽑은 여부 판단 안함
      for (int i = 1; i <= n; i++) {
         pick[pickCount] = i;
         pickCard(pickCount + 1);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n >> m;

   pickCard(0);
}