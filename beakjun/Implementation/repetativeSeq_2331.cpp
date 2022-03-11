/*
    작성자: 김지수
    작성일: 2022/03/11
    백준 -- 반복수열 (2331번)
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
bool find(int num) {
   for (int i = 0; i < ans.size(); i++) {
      if (ans[i] == num) {
         ans.erase(ans.begin() + i);
         return true;
      }
   }
   return false;
}

int calculate(int a, int p) {
   int sum = 0;
   int temp = a;
   while (temp >= 1) {
      int num = temp % 10;
      sum += pow(num, p);
      temp /= 10;
   }
   return sum;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int a, p;
   cin >> a >> p;
   bool repeat = false;
   ans.push_back(a);
   int temp = a;
   while (true) {
      temp = calculate(temp, p);
      bool found = find(temp);

      if (found) {
         repeat = true;
      } else if (repeat && !found) {
         break;
      } else if (!found && !repeat) {
         ans.push_back(temp);
      }
   }
   cout << ans.size() << endl;
}