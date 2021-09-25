/*
    작성자: 김지수
    작성일: 2021/09/24
    programmers -- 타겟 넘버 (43165번)
*/

#include <string>
#include <vector>

using namespace std;
int answer = 0;

void makeCombination(vector<int> num, int target, int depth, int sum) {
   if (depth == num.size()) {
      if (sum == target) {
         answer++;
      }
      return;
   } else if (depth > num.size()) {
      return;
   } else {
      makeCombination(num, target, depth + 1, sum + num[depth]);
      makeCombination(num, target, depth + 1, sum - num[depth]);
   }
}

int solution(vector<int> numbers, int target) {
   makeCombination(numbers, target, 0, 0);
   return answer;
}