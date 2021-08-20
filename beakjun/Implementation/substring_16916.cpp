/*
    작성자: 김지수
    작성일: 2021/08/21
    백준 -- 부분 문자열 (16916번)
    문제:
    - S와 P가 주어졌을 때, P가 S의 부분 문자열인지 아닌지 알아보자
*/

#include <iostream>
#include <vector>
using namespace std;
string whole, part;

vector<int> prePostTable(string s) {
   vector<int> ret(s.length(), 0);
   int j = 0;
   for (int i = 1; i < s.length(); i++) {
      while (j > 0 && s[i] != s[j]) {
         j = ret[j - 1];
      }
      if (s[i] == s[j]) {
         ret[i] = ++j;
      }
   }
   return ret;
}

bool kmp(string whole, string part) {
   vector<int> table = prePostTable(part);
   int j = 0;
   for (int i = 0; i < whole.length(); i++) {
      while (j > 0 && whole[i] != part[j]) {
         j = table[j - 1];
      }
      if (whole[i] == part[j]) {
         if (j == part.length() - 1) {
            return true;
         } else
            j++;
      }
   }
   return false;
}

int main(void) {
   cin >> whole >> part;
   int wholeIdx = 0, partIdx = 0;
   bool result = kmp(whole, part);
   if (result)
      cout << 1;
   else
      cout << 0;
}
