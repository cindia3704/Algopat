/*
    작성자: 김지수
    작성일: 2021/10/02
    백준 -- 큰 수 구성하기 (18511번)
    문제:
    - N보다 작거나 같은 자연수 중, 집한 K의 원소로만 이루어진 가장 큰 수 출력
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string temp;
int ans;
vector<int> sets;

void makeNum(string n) {
   if (temp.length() > 0 && stoi(n) >= stoi(temp)) {
      ans = max(ans, stoi(temp));
   }
   if (temp.length() == n.length()) {
      return;
   } else {
      for (int i = 0; i < sets.size(); i++) {
         temp.append(to_string(sets[i]));
         makeNum(n);
         temp.pop_back();
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string N;
   int elementNum;
   cin >> N >> elementNum;

   for (int i = 0; i < elementNum; i++) {
      int num;
      cin >> num;
      sets.push_back(num);
   }
   sort(sets.begin(), sets.end(), greater<int>());
   makeNum(N);
   cout << ans << endl;
}