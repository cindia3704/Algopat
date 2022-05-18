/*
    작성자: 김지수
    작성일: 2022/05/18
    백준 -- N과 M(1) (15649번)
    -> N개 중 중복없이 M개 고르기
*/

#include <cstring>
#include <iostream>
#define MAX 9
using namespace std;
int n, m;
bool picked[MAX];
int picks[MAX];

void pick(int pickCount) {
   //현재 뽑은 개수 == 뽑으려하는 개수
   if (pickCount == m) {
      for (int i = 0; i < m; i++) {
         cout << picks[i] << " ";
      }
      cout << "\n";  // endl쓰면 시간초과남
      return;
   } else if (pickCount > m) {
      return;
   } else {
      // 모든 수 돌면서 아직 안뽑힌 수면 추가
      for (int i = 1; i <= n; i++) {
         // 중복 없으니까 뽑은 여부 관리
         if (picked[i] == false) {
            picked[i] = true;
            picks[pickCount] = i;
            pick(pickCount + 1);
            picked[i] = false;
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n >> m;

   pick(0);
}