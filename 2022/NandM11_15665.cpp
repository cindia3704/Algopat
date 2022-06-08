/*
    작성자: 김지수
    작성일: 2022/06/08
    백준 -- N과 M(11) (15665번)
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#define MAX 9
using namespace std;
int n, m;
int seq[MAX];
set<string> combinations;

void makeComb(int pickCount, string comb) {
   if (pickCount == m) {
      if (combinations.find(comb) == combinations.end()) {
         combinations.insert(comb);
         cout << comb << '\n';
      }
      return;
   } else {
      for (int i = 0; i < n; i++) {
         string temp = comb + to_string(seq[i]);
         temp += " ";
         makeComb(pickCount + 1, temp);
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
   makeComb(0, "");
}