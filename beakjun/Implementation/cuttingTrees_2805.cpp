/*
    작성자: 김지수
    작성일: 2022/03/18
    백준 -- 나무 자르기 (2805번)
    문제:
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000001;
long long treeNum, leastAmount;
long long ansHeight = 0;
vector<long long> trees;
long long ans = 0;

long long getAmount(long long h) {
   long long count = 0;
   for (int i = 0; i < treeNum; i++) {
      if ((trees[i] - h) > 0) {
         count += (trees[i] - h);
      }
   }
   return count;
}
long long binSearch(long long s, long long e) {
   if (s == e) {
      if (getAmount(s) >= leastAmount) {
         return s;
      } else {
         return ans;
      }
   }
   long long mid = (s + e) / 2;
   long long temp = getAmount(mid);

   if (temp < leastAmount) {
      return binSearch(s, mid);
   } else if (temp == leastAmount) {
      return mid;
   } else {
      ans = max(ans, mid);
      if (e <= mid + 1) {
         return mid;
      } else {
         return binSearch(mid + 1, e);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> treeNum >> leastAmount;
   for (int i = 0; i < treeNum; i++) {
      long long t;
      cin >> t;
      trees.push_back(t);
   }
   sort(trees.begin(), trees.end());
   ansHeight = trees[trees.size() - 1];
   cout << binSearch(0, ansHeight);
}