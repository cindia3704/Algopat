/*
    작성자: 김지수
    작성일: 2021/04/29
    백준 -- 연속합 (1912번)
    문제:
    - n개의 정수로 이루어진 임의의 수열이 주어진다
    - 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을
   구하려고 한다.
*/
#include <bits/stdc++.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 100000;
int n;
vector<int> seq;
// idx 까지 계산할 때 가장 큰 연속 합
int cache[MAX_N];
int maxSum = INT_MIN;

void findGreatestSum() {
   for (int i = 0; i < n; i++) {
      cache[i] = seq[i];
      int before = i - 1;
      if (before >= 0 && cache[before] + seq[i] > seq[i]) {
         cache[i] = cache[before] + seq[i];
      }
      maxSum = max(maxSum, cache[i]);
   }
}

int main(void) {
   cin >> n;
   memset(cache, 0, sizeof(cache));
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
   }

   findGreatestSum();
   cout << maxSum << endl;
}