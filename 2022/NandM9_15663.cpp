/*
    작성자: 김지수
    작성일: 2022/06/08
    백준 -- N과 M (9) (15663번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#define MAX 8
using namespace std;

int n, m;
int lists[MAX];
bool visited[MAX];
set<string> ans;

void makeComb(int pickCount, string comb) {
   if (pickCount == m) {
      if (ans.find(comb) == ans.end()) {
         cout << comb << '\n';
         ans.insert(comb);
      }
      return;
   } else {
      for (int i = 0; i < n; i++) {
         if (visited[i] == false) {
            visited[i] = true;
            string temp = comb + to_string(lists[i]);
            temp += ' ';
            makeComb(pickCount + 1, temp);
            visited[i] = false;
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n >> m;
   memset(visited, false, sizeof(visited));
   for (int i = 0; i < n; i++) {
      cin >> lists[i];
   }
   sort(lists, lists + n);
   makeComb(0, "");
}