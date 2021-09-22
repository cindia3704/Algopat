/*
    작성자: 김지수
    작성일: 2021/09/22
    programmers -- 체육복 (42862번)
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
   int answer = n - lost.size();
   int have[n + 2];
   fill(have, have + n + 2, 0);
   sort(lost.begin(), lost.end());
   sort(reserve.begin(), reserve.end());
   for (int i = 0; i < reserve.size(); i++) {
      bool found = false;
      for (int j = 0; j < lost.size(); j++) {
         if (reserve[i] == lost[j]) {
            found = true;
            answer++;
            lost.erase(remove(lost.begin(), lost.end(), reserve[i]),
                       lost.end());
         }
      }
      if (!found) {
         have[reserve[i]]++;
      }
   }
   for (int i = 0; i < lost.size(); i++) {
      int now = lost[i];
      if (have[now - 1] > 0) {
         have[now - 1]--;
         answer++;
      } else if (have[now + 1] > 0) {
         have[now + 1]--;
         answer++;
      }
   }
   return answer;
}