/*
    작성자: 김지수
    작성일: 2021/09/25
    programmers -- 폰켓몬 (1845번)
*/
#include <set>
#include <vector>
using namespace std;

int solution(vector<int> nums) {
   int answer = 0;
   set<int> numTemp;
   for (int i = 0; i < nums.size(); i++) {
      numTemp.insert(nums[i]);
   }
   int half = nums.size() / 2;
   answer = (half >= numTemp.size()) ? numTemp.size() : half;
   return answer;
}