/*
    작성자: 김지수
    작성일: 2021/10/09
    백준 -- 수열 (2559번)
    문제:
*/

#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int seqLength, limit;
   cin >> seqLength >> limit;
   int arr[seqLength];
   for (int i = 0; i < seqLength; i++) {
      cin >> arr[i];
   }
   int maxSum = -987654321;
   int tempSum = 0;
   int end = 0;
   for (int i = 0; i < seqLength; i++) {
      while (end < seqLength) {
         tempSum += arr[end];
         end++;
         if (end - i >= limit) {
            maxSum = (maxSum < tempSum) ? tempSum : maxSum;
            break;
         }
      }
      tempSum -= arr[i];
   }
   cout << maxSum;
}