/*
    작성자: 김지수
    작성일: 2021/09/21
    programmers -- 더 맵게 (42626번)
*/
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
   int answer = 0;
   priority_queue<int> q;
   for (int i = 0; i < scoville.size(); i++) {
      q.push(-scoville[i]);
   }
   bool found = false;
   while (!q.empty()) {
      int now = -q.top();
      if (now >= K) {
         found = true;
         break;
      } else if (now < K && q.size() == 1) {
         break;
      } else {
         answer++;
         q.pop();
         int next = -q.top();
         q.pop();
         int nextNum = now + (next * 2);
         q.push(-nextNum);
      }
   }
   answer = (found == true) ? answer : -1;
   return answer;
}