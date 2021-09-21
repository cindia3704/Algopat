/*
    작성자: 김지수
    작성일: 2021/09/22
    programmers -- 최댓값과 최솟값 (12939번)
*/

#include <string>
#include <vector>

using namespace std;
vector<long long> sortVector(vector<long long> v) {
   for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
         if (v[i] > v[j]) {
            long long temp = v[i];
            v[i] = v[j];
            v[j] = temp;
         }
      }
   }

   return v;
}

string solution(string s) {
   string answer = "";
   vector<long long> temp;
   int index = 0;
   while (index < s.length()) {
      vector<char> number;
      while (s[index] != ' ' && index < s.length()) {
         number.push_back(s[index]);
         index++;
      }
      bool neg = false;
      long long num = 0;
      long long digit = 1;
      for (int i = number.size() - 1; i >= 0; i--) {
         if (number[i] == '-') {
            neg = true;
         } else {
            num += ((number[i] - '0') * digit);
            digit *= 10;
         }
      }
      if (neg) {
         temp.push_back(-num);
      } else {
         temp.push_back(num);
      }
      index++;
   }
   temp = sortVector(temp);
   answer.append(to_string(temp[0]) + " ");
   answer.append(to_string(temp[temp.size() - 1]));
   return answer;
}