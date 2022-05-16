/*
    작성자: 김지수
    작성일: 2022/05/16
    백준 -- 점프 점프 (11060번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 1002
using namespace std;

int seq[MAX];
int seqLength;
// cache[i] = i번째 자리까지 도달하기위한 최소 점프 수
int cache[MAX];

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   // 길이 입력
   cin >> seqLength;

   //최소 점프수 찾는거기 때문에 매우 큰수로 모든 점프수 세팅
   for (int i = 0; i <= seqLength; i++) {
      cache[i] = 987654321;
   }

   // 입력 받고
   for (int i = 1; i <= seqLength; i++) {
      cin >> seq[i];
   }

   // 첫번째자리까지 오는 점프수 = 0
   cache[1] = 0;

   // 길이 돌면서
   for (int i = 1; i <= seqLength; i++) {
      // 각 위치에서 점프할 수 있는 최대 거리
      int hop = seq[i];
      // 현 위치 + 갈수 있는 모든 거리
      for (int j = i + 1; j <= i + hop; j++) {
         // 길이보다 큰건 무시
         if (j > seqLength)
            continue;
         else {
            // 다음 위치까지의 최소 점프 수 = 현 자리 점프수 +1 or 이전에 계산한
            // 다음위치까지의 최소 점프수
            cache[j] = min(cache[i] + 1, cache[j]);
         }
      }
   }

   // 갈 방법이 없으면 -1 출력
   if (cache[seqLength] == 987654321) {
      cout << -1;
   } else {
      cout << cache[seqLength];
   }
}