/*
    작성자: 김지수
    작성일: 2021/10/09
    백준 -- 겹치는 건 싫어 (20922번)
    문제:
*/
#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int seqLength, limit;
   cin >> seqLength >> limit;
   int ans = -1;
   int count[100001];
   fill(count, count + 100001, 0);
   int seq[seqLength];
   for (int i = 0; i < seqLength; i++) {
      cin >> seq[i];
   }
   int end = 0;
   for (int i = 0; i < seqLength; i++) {
      while (end < seqLength) {
         count[seq[end]]++;
         if (count[seq[end]] > limit) {
            count[seq[end]]--;
            break;
         } else {
            int temp = end - i + 1;
            ans = (temp > ans) ? temp : ans;
         }

         end++;
      }
      count[seq[i]]--;
   }
   cout << ans;
}