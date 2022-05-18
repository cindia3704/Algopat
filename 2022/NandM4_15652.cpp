/*
    작성자: 김지수
    작성일: 2022/05/18
    백준 -- N과 M(1) (15649번)
    -> N개 중 M개 고르기
    -> 중복 가능 but 비내림차순
*/

#include <iostream>
#define MAX 9
using namespace std;
int n, m;
int pick[MAX];

void pickCard(int pickCount, int start) {
   if (pickCount == m) {
      for (int i = 0; i < m; i++) {
         cout << pick[i] << " ";
      }
      cout << "\n";
      return;
   } else if (pickCount > m) {
      return;
   } else {
      // 비내림차순 -> 이전카드부터 시작가능! & 중복가능이라 중복여부 판단 안함
      for (int i = start; i <= n; i++) {
         pick[pickCount] = i;
         pickCard(pickCount + 1, i);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> n >> m;
   pickCard(0, 1);
}