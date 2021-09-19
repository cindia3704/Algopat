/*
    작성자: 김지수
    작성일: 2021/09/19
    programmers -- 로또의 최고 순위와 최저 순위 (77484번)
*/

#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
   vector<int> answer;
   int have[46];
   fill(have, have + 46, 0);

   for (int i = 0; i < lottos.size(); i++) {
      have[lottos[i]]++;
   }
   int min = 0;
   vector<int> temp;
   for (int i = 0; i < win_nums.size(); i++) {
      if (have[win_nums[i]] > 0) {
         min++;
      }
   }
   temp.push_back(min + have[0]);
   temp.push_back(min);
   for (int i = 0; i < temp.size(); i++) {
      if (temp[i] <= 1) {
         answer.push_back(6);
      } else {
         answer.push_back(7 - temp[i]);
      }
   }

   return answer;
}