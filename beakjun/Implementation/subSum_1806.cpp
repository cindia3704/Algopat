/*
    작성자: 김지수
    작성일: 2021/10/03
    백준 -- 부분합 (1806번)
    문제:
*/
#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int minLength = 987654321;
   int seqLength, targetNum;
   cin >> seqLength >> targetNum;
   int arr[seqLength];
   for (int i = 0; i < seqLength; i++) {
      cin >> arr[i];
   }

   int end = 0;
   int sum = 0;
   for (int i = 0; i < seqLength; i++) {
      while (sum < targetNum && end < seqLength) {
         sum += arr[end];
         end++;
      }
      if (sum >= targetNum) {
         int tempRange = end - i;
         sum -= arr[i];
         minLength = (minLength > tempRange) ? tempRange : minLength;
      }
   }
   if (minLength == 987654321) {
      minLength = 0;
   }
   cout << minLength;
}