/*
    작성자: 김지수
    작성일: 2022/05/18
    백준 -- 모든 순열 (10974번)
*/

#include <cstring>
#include <iostream>
#define MAX 9
using namespace std;
int n;
bool picked[MAX];
int pick[MAX];

void makeComb(int countPick) {
   if (countPick == n) {
      for (int i = 0; i < n; i++) {
         cout << pick[i] << " ";
      }
      cout << "\n";
      return;
   } else if (countPick > n) {
      return;
   } else {
      for (int i = 1; i <= n; i++) {
         if (picked[i] == false) {
            picked[i] = true;
            pick[countPick] = i;
            makeComb(countPick + 1);
            picked[i] = false;
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> n;
   memset(picked, false, sizeof(picked));
   makeComb(0);
}