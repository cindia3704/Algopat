/*
    작성자: 김지수
    작성일: 2021/09/19
    programmers -- 내적 (70128번)
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
   int answer = 0;
   for (int i = 0; i < a.size(); i++) {
      answer += (a[i] * b[i]);
   }
   return answer;
}