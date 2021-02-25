/*
    작성자: 김지수
    작성일: 2021/02/25
    프로그래머스 -- 스킬트리
    문제:선행 스킬 순서 skill과 유저들이 만든 스킬트리1를 담은 배열
   skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 return 하는
   solution 함수를 작성해주세요.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
   int answer = 0;
   int size = skill.length();
   for (int i = 0; i < skill_trees.size(); i++) {
      int prev = 0;
      int next = 0;
      bool valid = true;
      int j = 0;
      while (j < size - 1) {
         prev = skill_trees[i].find(skill.substr(j, 1));
         next = skill_trees[i].find(skill.substr(j + 1, 1));
         if (prev == -1 && next == -1) {
            valid = true;
         } else if (prev < next) {
            if (prev == -1) {
               valid = false;
               break;
            } else {
               valid = true;
            }
         } else {
            if (next == -1) {
               valid = true;
            } else {
               valid = false;
               break;
            }
         }
         j++;
      }
      if (valid) {
         answer += 1;
      }
   }
   return answer;
}