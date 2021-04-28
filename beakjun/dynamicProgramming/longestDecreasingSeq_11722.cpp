/*
    작성자: 김지수
    작성일: 2021/04/28
    백준 -- 가장 긴 감소하는 부분 수열 (11722번)
    문제:수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을
   작성하시오.
    - 예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는
   부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1000;
vector<int> seq;
vector<int> cache;
int n;

int main(void) {
   cin >> n;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
      cache.push_back(1);
   }

   for (int i = 0; i < n - 1; i++) {
      int minNum = seq[i];
      for (int j = i + 1; j < n; j++) {
         if (minNum > seq[j]) {
            cache[j] = max(cache[i] + 1, cache[j]);
         }
      }
   }
   sort(cache.begin(), cache.end());
   cout << cache[n - 1] << endl;
}