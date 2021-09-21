/*
    작성자: 김지수
    작성일: 2021/09/22
    백준 -- 통나무 건너뛰기 (11497번)
    문제:
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tc;
   cin >> tc;
   while (tc--) {
      int logNum;
      cin >> logNum;
      vector<int> logs;
      for (int i = 0; i < logNum; i++) {
         int num;
         cin >> num;

         logs.push_back(num);
      }
      sort(logs.begin(), logs.end());

      int level = 0;
      for (int i = 0; i < logs.size() - 2; i++) {
         int diff = abs(logs[i] - logs[i + 2]);
         level = max(level, diff);
      }

      cout << level << endl;
   }
}