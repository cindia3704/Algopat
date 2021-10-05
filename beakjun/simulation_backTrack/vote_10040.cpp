/*
    작성자: 김지수
    작성일: 2021/10/05
    백준 -- 투표 (10040번)
    문제:
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int numCompetition, numPeople;
   cin >> numCompetition >> numPeople;

   int limit[numPeople];
   int score[numCompetition];
   int cost[numCompetition];

   fill(score, score + numCompetition, 0);
   for (int i = 0; i < numCompetition; i++) {
      cin >> cost[i];
   }
   for (int i = 0; i < numPeople; i++) {
      int l;
      cin >> l;
      for (int j = 0; j < numCompetition; j++) {
         if (cost[j] <= l) {
            score[j]++;
            break;
         }
      }
   }

   int maxNum = 0;
   int maxIdx = 0;
   for (int i = 0; i < numCompetition; i++) {
      if (score[i] > maxNum) {
         maxNum = score[i];
         maxIdx = i;
      }
   }
   cout << maxIdx + 1;
}