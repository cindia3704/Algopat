/*
    작성자: 김지수
    작성일: 2021/10/03
    programmers -- 완주하지 못한 선수 (42576번)
    // 정렬 안하고 하면 시간초과!!
*/
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
   string answer = "";
   sort(participant.begin(), participant.end());
   sort(completion.begin(), completion.end());
   for (int i = 0; i < participant.size(); i++) {
      if (participant[i] != completion[i]) {
         answer = participant[i];
         break;
      }
   }
   return answer;
}