/*
    작성자: 김지수
    작성일: 2021/04/27
    백준 -- 가장 큰 증가 부분 수열 (11055번)
    문제:수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을
   구하는 프로그램을 작성하시오.
    - X예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이
   가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은
   113이다.
*/

#include <iostream>
using namespace std;
const int MAX = 10000;
int seq[MAX];
int cache[MAX];

int main(void) {
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> seq[i];
   }
   for (int i = 0; i < n; i++) {
      cache[i] = seq[i];
   }
   int maxNum = seq[0];

   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
         if (seq[i] < seq[j]) {
            int tot = cache[i] + seq[j];
            cache[j] = max(tot, cache[j]);
            if (maxNum < tot) {
               maxNum = tot;
            }
         }
      }
   }
   cout << maxNum << endl;
}