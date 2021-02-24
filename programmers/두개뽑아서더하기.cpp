/*
    작성자: 김지수
    작성일: 2021/01/30
    프로그래머스 -- 두 개 뽑아서 더하기
    문제:정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두
   개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return
   하도록 solution 함수를 완성해주세요.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
   vector<int> answer;
   int count = numbers.size();
   for (int i = 0; i < count; i++) {
      for (int j = i + 1; j < count; j++) {
         int add = numbers[i] + numbers[j];
         answer.push_back(add);
      }
   }
   sort(answer.begin(), answer.end());
   answer.erase(unique(answer.begin(), answer.end()), answer.end());
   return answer;
}