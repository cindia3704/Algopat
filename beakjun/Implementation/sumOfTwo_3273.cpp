/*
    작성자: 김지수
    작성일: 2021/08/26
    백준 -- 두 수의 합 (3273번)
    문제:
    - 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai,
   aj)쌍의 수를 구하는 프로그램을 작성
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 2000001;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int numbers[MAX_N];
   vector<int> sequence;
   memset(numbers, 0, sizeof(numbers));

   int seqNum, sum;
   cin >> seqNum;
   for (int i = 0; i < seqNum; i++) {
      int num;
      cin >> num;
      sequence.push_back(num);
      numbers[num]++;
   }
   cin >> sum;

   sort(sequence.begin(), sequence.end());

   int count = 0;
   for (int i = 0; i < seqNum; i++) {
      int diff = sum - sequence[i];
      if (diff <= 0) {
         continue;
      }
      if (numbers[diff] > 0 && diff > 0 && diff != sequence[i]) {
         // 두 숫자가 달라야해서 diff!=seq[i]
         count++;
      }
   }

   cout << count / 2;  // 앞에서 찾고 뒤에서 찾으면 한 쌍마다 2개씩 더해짐
   return 0;
}