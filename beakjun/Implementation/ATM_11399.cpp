/*
    작성자: 김지수
    작성일: 2022/03/12
    백준 -- ATM (11399번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;
   vector<int> t;
   for (int i = 0; i < n; i++) {
      int time;
      cin >> time;
      t.push_back(time);
   }
   sort(t.begin(), t.end());

   vector<int> ans;
   int temp = 0;
   for (int i = 0; i < n; i++) {
      ans.push_back(temp + t[i]);
      temp += t[i];
   }

   int sum = 0;
   for (int i = 0; i < n; i++) {
      sum += ans[i];
   }
   cout << sum;
}