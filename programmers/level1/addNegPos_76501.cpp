/*
    작성자: 김지수
    작성일: 2021/09/19
    programmers -- 음양 더하기 (76501번)
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
   int answer = 0;
   for (int i = 0; i < absolutes.size(); i++) {
      if (signs[i]) {
         answer += absolutes[i];
      } else {
         answer -= absolutes[i];
      }
   }
   return answer;
}