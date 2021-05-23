/*
    작성자: 김지수
    작성일: 2021/05/23
    백준 -- 알파벳 찾기 (10809)
    문제:
    - 수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터
   K번째 있는 수를 구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   int n, k;
   vector<int> seq;
   cin >> n >> k;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
   }
   sort(seq.begin(), seq.end());
   cout << seq[k - 1] << endl;
}