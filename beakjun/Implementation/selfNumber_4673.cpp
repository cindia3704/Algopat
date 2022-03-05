/*
    작성자: 김지수
    작성일: 2022/03/05
    백준 -- 셀프 넘버 (4673번)
*/

#include <cstring>
#include <iostream>
using namespace std;
int arr[10001];

void dn(int num) {
   int result = num;
   int tempNum = num;
   while (true) {
      int temp = tempNum / 10;
      int temp2 = tempNum % 10;
      tempNum /= 10;

      if (temp >= 10) {  // 몫이 10이상이면  나머지만 더함
         result += temp2;
      } else {  // 몫이 10미만이면 몫(1의 자리) & 나머지 모두 더함
         result += temp;
         result += temp2;
      }
      if (tempNum <= 9) {
         break;
      }
   }
   if (result != num && result < 10001) {
      arr[result] = 1;
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(arr, 0, sizeof(arr));
   for (int i = 1; i < 10001; i++) {
      dn(i);
   }
   for (int i = 1; i < 10001; i++) {
      if (arr[i] != 1) {
         cout << i << '\n';
      }
   }
}