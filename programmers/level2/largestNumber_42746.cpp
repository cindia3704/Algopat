/*
    작성자: 김지수
    작성일: 2021/09/26
    programmers -- 가장 큰수 (42746번)
*/
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(int a, int b) {
   string sa = to_string(a);
   string sb = to_string(b);
   return sa + sb > sb + sa;
}

string solution(vector<int> numbers) {
   sort(numbers.begin(), numbers.end(), comp);
   string answer = "";
   string z = "";

   for (int i = 0; i < numbers.size(); i++) {
      answer.append(to_string(numbers[i]));
      z.append("0");
   }
   if (answer == z) {
      answer = "0";
   }
   return answer;
}