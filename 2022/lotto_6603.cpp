/*
    작성자: 김지수
    작성일: 2022/06/08
    백준 -- 로또 (6603번)
*/

#include <iostream>
#define MAX 13
using namespace std;
int setS[MAX];
int pick[MAX];

void makeComb(int pickCount, int n, int start) {
   // 6개 모두 골랐을때는 출력
   if (pickCount == 6) {
      for (int i = 0; i < 6; i++) {
         cout << pick[i] << " ";
      }
      cout << '\n';
      return;
   } else if (start >= n) {
      // 오름차순만 가능해서 다음으로 보는 숫자가 인덱스 범위 나갈수 있음
      return;
   } else {
      for (int i = start; i < n; i++) {
         pick[pickCount] = setS[i];
         makeComb(pickCount + 1, n, i + 1);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;

   while (true) {
      cin >> n;
      // 0 입력전까지는 계속 반복
      if (n == 0) {
         break;
      }
      for (int i = 0; i < n; i++) {
         cin >> setS[i];
      }
      makeComb(0, n, 0);
      cout << '\n';
   }
}