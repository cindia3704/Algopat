/*
    작성자: 김지수
    작성일: 2021/09/18
    백준 -- 수 찾기(1920번)
    문제:
   N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가
   존재하는지 알아내는 프로그램
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> seq;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int seqNum;
   cin >> seqNum;
   for (int i = 0; i < seqNum; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
   }
   sort(seq.begin(), seq.end());
   int findListNum;
   cin >> findListNum;
   for (int i = 0; i < findListNum; i++) {
      int num;
      cin >> num;
      if (binary_search(seq.begin(), seq.end(), num)) {
         cout << 1 << '\n';
      } else {
         cout << 0 << '\n';
      }
   }
}
