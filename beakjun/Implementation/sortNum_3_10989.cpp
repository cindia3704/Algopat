/*
    작성자: 김지수
    작성일: 2021/05/18
    백준 -- 수 정렬하기 3 (10989번)
    문제:N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을
   작성하시오.
    주의!! 시간제한: 3초, 메모리 제한: 8MB
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_NUM = 10000 + 1;

int main(void) {
   ios::sync_with_stdio(false);
   int n;
   cin >> n;
   int nums[MAX_NUM];
   memset(nums, 0, sizeof(nums));
   int maxNum = 0;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      nums[num]++;
      if (maxNum < num) {
         maxNum = num;
      }
   }
   for (int i = 0; i <= maxNum; i++) {
      while (nums[i] > 0) {
         cout << i << "\n";
         nums[i]--;
      }
   }
}