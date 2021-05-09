/*
    작성자: 김지수
    작성일: 2021/05/09
    백준 -- 수 정렬하기 2 (2751번)
    문제:N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을
   작성하시오.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   int n;
   cin >> n;
   vector<int> seq;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
   }
   sort(seq.begin(), seq.end());
   for (int i = 0; i < seq.size(); i++) {
      cout << seq[i] << "\n";
   }
}