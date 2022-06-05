/*
    작성자: 김지수
    작성일: 2022/06/05
    백준 -- 부분수열의 합 (1182번)
*/

#include <iostream>
#define MAX 21
using namespace std;
int seq[MAX];
int seqLength, targetSum;
int ans = 0;

void makeComb(int totalPick, int nowPick, int start, int nowSum) {
   // 이번턴에 뽑는 수 다 뽑았을때 합이 목표합과 같으면 정답 +1
   if (nowPick == totalPick) {
      if (nowSum == targetSum) {
         ans++;
      }
      return;
   } else {
      // 뽑는 수에 중복없게 start 넣음
      for (int i = start; i < seqLength; i++) {
         makeComb(totalPick, nowPick + 1, i + 1, nowSum + seq[i]);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> seqLength >> targetSum;
   for (int i = 0; i < seqLength; i++) {
      cin >> seq[i];
   }
   // 뽑는 개수는 1~전체수
   for (int i = 1; i <= seqLength; i++) {
      makeComb(i, 0, 0, 0);
   }
   cout << ans;
}
