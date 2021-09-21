/*
    작성자: 김지수
    작성일: 2021/09/20
    programmers -- 3진법 뒤집기 (68935번)
*/
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int changeToBase10(string num) {
   int ans = 0;
   int idx = num.length() - 1;
   for (int i = 0; i < num.length(); i++) {
      int n = (num[i] - '0') * pow(3, idx - i);
      ans += n;
   }
   return ans;
}

int changeBase(int n) {
   string ans = "";
   while (n >= 1) {
      int mod = n % 3;
      ans.append(to_string(mod));
      n /= 3;
   }
   return changeToBase10(ans);
}

int solution(int n) {
   int answer = 0;
   answer = changeBase(n);
   return answer;
}