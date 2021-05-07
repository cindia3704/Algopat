/*
    작성자: 김지수
    작성일: 2021/05/08
    프로그래머스 -- 튜플
    문제:
    - 원소의 개수가 n개이고, 중복되는 원소가 없는 튜플 (a1, a2, a3, ..., an)이
   주어질 때(단, a1, a2, ..., an은 자연수), 이는 다음과 같이 집합 기호 '{',
   '}'를 이용해 표현할 수 있습니다.
    - {{a1}, {a1, a2}, {a1, a2, a3}, {a1, a2, a3, a4}, ... {a1, a2, a3, a4, ...,
   an}}
   - 특정 튜플을 표현하는 집합이 담긴 문자열 s가 매개변수로 주어질 때, s가
   표현하는 튜플을 배열에 담아 return 하도록 solution 함수를 완성해주세요.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
   vector<int> answer;
   s = s.substr(1, s.size() - 2);  // 앞뒤 괄호 없앰
   // 괄호 단위로 짧은 순서에 있는 수가 먼저 푸씨 되어야 함 --> 괄호 단위 스트링
   // & 그의 길이 저장
   vector<pair<int, string> > tokens;

   while (s.size() > 0) {
      string token = s.substr(0, 1);
      if (token == "{" || token == "," || token == "}") {
         // 제일 처음 보는게 { , } 중 하나면 s를 앞에서 부터 하나 자르기
         s.erase(0, 1);
         continue;
      }

      else {
         // 숫자 보이면, } 나올때까지 보고 이를 tokens에 넣음
         string token = s.substr(0, s.find("}"));
         tokens.push_back(make_pair(token.size(), token));

         s.erase(0, token.size() + 1);  // 지금 본 부분까지 지움
      }
   }

   sort(tokens.begin(), tokens.end());  // tokens에 넣어진 걸 길이순서로 정렬

   for (int i = 0; i < tokens.size();
        i++) {  // tokens에 있는 element 돌아가며 콤마(,) 단위로 자름
      string now = tokens[i].second;
      while (now.size() > 0) {
         string tok = now.substr(0, now.find(","));
         int a = stoi(tok);  // 숫자로 변환한 뒤 answer에 푸씨!
         if (find(answer.begin(), answer.end(), a) == answer.end()) {
            answer.push_back(a);
         }
         now.erase(0, tok.size() + 1);
      }
   }

   return answer;
}