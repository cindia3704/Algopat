/*
    작성자: 김지수
    작성일: 2021/09/19
    programmers -- 없는 숫자 더하기 (86051번)
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
   int answer = 45;
   for (int i = 0; i < numbers.size(); i++) {
      answer -= numbers[i];
   }
   return answer;
}