/*
    작성자: 김지수
    작성일: 2022/06/10
    백준 -- N과 M(12) (15666번)
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#define MAX 9
using namespace std;

int n, m;
int seq[MAX];
set<string> s;

void makeComb(int pickCount, int start, string comb) {
   if (pickCount == m) {
      if (s.find(comb) == s.end()) {
         cout << comb << '\n';
         s.insert(comb);
      }
      return;
   } else {
      for (int i = start; i < n; i++) {
         string temp = comb + to_string(seq[i]);
         temp += " ";
         makeComb(pickCount + 1, i, temp);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      cin >> seq[i];
   }

   sort(seq, seq + n);
   makeComb(0, 0, "");
}