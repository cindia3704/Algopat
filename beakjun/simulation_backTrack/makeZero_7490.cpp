/*
    작성자: 김지수
    작성일: 2021/09/14
    백준 -- 0 만들기 (7490번)
    문제:
    - 1부터 N까지의 수를 오름차순으로 쓴 수열 1 2 3 ... N 있음
   - +는 더하기, -는 빼기, 공백은 숫자를 이어 붙이는 것을 뜻한다
   - +'나 '-', 또는 ' '(공백)을 숫자 사이에 삽입 -> 수식의 값을 계산하고 그
   결과가 0이 될 수 있는지를 살피자.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
const int MAX_N = 20;
char equation[MAX_N];
bool visited[MAX_N];
char op[3] = {'+', '-', '0'};
vector<string> ans;

void getCombination(int number, int depth, int sum, int nextNum) {
   if (depth == (number * 2) - 1) {
      if (sum == 0) {
         string s = "";
         for (int i = 0; i < depth; i++) {
            if (equation[i] == '0') {
               s.append(" ");
            } else {
               stringstream ss;
               ss << equation[i];
               s.append(ss.str());
            }
         }
         ans.push_back(s);
      }
      return;
   } else {
      if (depth % 2 == 0) {
         if (!visited[nextNum]) {
            equation[depth] = (char)(nextNum + 48);
            visited[nextNum] = true;
            if (depth != 0) {
               if (equation[depth - 1] == '+') {
                  sum += nextNum;
               } else if (equation[depth - 1] == '0') {
                  int t = depth - 1;
                  string num = "";
                  while ((equation[t] != '+' && equation[t] != '-') && t >= 0) {
                     if (equation[t] == '0') {
                        t--;
                        continue;
                     }
                     stringstream ss;
                     ss << equation[t];
                     num.append(ss.str());
                     t--;
                  }
                  reverse(num.begin(), num.end());
                  int numFinal = stoi(num) * 10;
                  numFinal += nextNum;
                  char prevOp = equation[t];
                  if (prevOp == '+' && t > 0) {
                     sum -= stoi(num);
                     sum += numFinal;
                  } else if (prevOp == '-' && t > 0) {
                     sum += stoi(num);

                     sum -= numFinal;
                  } else {
                     sum = numFinal;
                  }
               } else {
                  sum -= nextNum;
               }
            } else {
               sum += nextNum;
            }
            getCombination(number, depth + 1, sum, nextNum + 1);
            visited[nextNum] = false;
         }
      } else {
         for (int i = 0; i < 3; i++) {
            equation[depth] = op[i];
            getCombination(number, depth + 1, sum, nextNum);
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(visited, false, sizeof(visited));
   int tc;
   cin >> tc;
   while (tc--) {
      int number;
      cin >> number;
      getCombination(number, 0, 0, 1);
      sort(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); i++) {
         cout << ans[i] << endl;
      }
      cout << endl;
      ans.clear();
   }
}