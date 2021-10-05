/*
    작성자: 김지수
    작성일: 2021/10/05
    백준 -- 배열 합치기 (11728번)
    문제:
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int seqSize1, seqSize2;
   cin >> seqSize1 >> seqSize2;
   vector<int> seq;
   for (int i = 0; i < seqSize1 + seqSize2; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
   }
   sort(seq.begin(), seq.end());
   for (int i = 0; i < seq.size(); i++) {
      cout << seq[i] << " ";
   }
}