/*
    작성자: 김지수
    작성일: 2022/03/18
    백준 -- 연속합 (1912번)
    문제:
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
vector<int> arr;
int sumArr[MAX + 1];

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      arr.push_back(num);
   }

   sumArr[0] = 0;
   int maxNum = -987654321;
   for (int i = 0; i < n; i++) {
      if (sumArr[i] + arr[i] > arr[i]) {
         sumArr[i + 1] = sumArr[i] + arr[i];
         maxNum = max(maxNum, sumArr[i + 1]);
      } else {
         sumArr[i + 1] = arr[i];
         maxNum = max(maxNum, sumArr[i + 1]);
      }
   }
   cout << maxNum;
}