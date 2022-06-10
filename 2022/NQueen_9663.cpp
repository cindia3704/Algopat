/*
    작성자: 김지수
    작성일: 2022/06/11
    백준 -- N-Queen (9663번)
*/

#include <cstring>
#include <iostream>
#define MAX 40
using namespace std;

int n;
int ans = 0;
bool isused1[MAX];
bool isused2[2 * MAX - 1];
bool isused3[2 * MAX - 1];

void makeComb(int pickCount, int sy) {
   if (pickCount == n) {
      ans++;
      return;
   } else {
      for (int j = 0; j < n; j++) {
         if (isused1[j] == false) {
            if (isused2[sy + j] == false) {
               if (isused3[j - sy + n - 1] == false) {
                  isused3[j - sy + n - 1] = true;
                  isused2[sy + j] = true;
                  isused1[j] = true;
                  makeComb(pickCount + 1, sy + 1);
                  isused3[j - sy + n - 1] = false;
                  isused2[sy + j] = false;
                  isused1[j] = false;
               }
            }
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(isused1, false, sizeof(isused1));
   memset(isused2, false, sizeof(isused2));
   memset(isused3, false, sizeof(isused3));

   cin >> n;
   makeComb(0, 0);

   cout << ans;
}