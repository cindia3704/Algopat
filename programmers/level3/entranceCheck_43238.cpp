/*
    작성자: 김지수
    작성일: 2021/09/25
    programmers -- 입국 심사 (43238번)
*/
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
   long long answer = 0;
   sort(times.begin(), times.end());
   long long start = 0;
   long long end = times[times.size() - 1] * n;
   while (start != end) {
      long long mid = (start + end) / 2;
      long long count = 0;
      for (int i = 0; i < times.size(); i++) {
         count += mid / times[i];
      }
      if (count >= n) {
         end = mid;
      } else {
         start = mid + 1;
      }
   }
   answer = start;
   return answer;
}