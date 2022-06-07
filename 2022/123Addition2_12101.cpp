/*
    작성자: 김지수
    작성일: 2022/06/08
    백준 -- 1,2,3 더하기 2 (12101번)
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;
long long targetNum, seqCount;
set<string> sums;
long long countSeqNum = 0;

void makeSum(long long nowSum, string seq) {
   // 원하는 합 찾은경우
   if (nowSum == targetNum) {
      // 맨 뒤에 붙은 + 지움
      seq.pop_back();
      // 세트에서 찾아보고 없으면 넣음 (중복 제거)
      if (sums.find(seq) == sums.end()) {
         sums.insert(seq);
         // 이번이 몇번째로 찾은 조합인지 업데이트
         countSeqNum++;
      }
      // 찾은 조합이 찾으려는 번째 조합이면 출력
      if (countSeqNum == seqCount) {
         cout << seq;
      }
      return;
   } else if (nowSum > targetNum) {
      // 원하는 합보다 크면 리턴
      return;
   } else {
      // 오름차순으로 조합만들어야하고 가능한 수 = 1/2/3
      for (int i = 1; i <= 3; i++) {
         string temp = seq + to_string(i);
         temp += '+';
         makeSum(nowSum + i, temp);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> targetNum >> seqCount;
   makeSum(0, "");

   // 만약 만들수 있는 조합개수가 원하는 번째수보다 작으면 -1 출력
   if (countSeqNum < seqCount) {
      cout << -1;
   }
}