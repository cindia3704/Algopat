/*
    작성자: 김지수
    작성일: 2021/09/26
    programmers -- 입실 퇴실 (86048번)
*/
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
   vector<int> answer;
   vector<int> temp[enter.size() + 1];
   int startEnter = 0;
   int startLeave = 0;
   set<int> entered;
   while (startEnter < enter.size()) {
      auto f = entered.find(leave[startLeave]);
      if (f != entered.end()) {
         entered.erase(leave[startLeave]);
         startLeave++;
      } else {
         set<int>::iterator it;
         for (it = entered.begin(); it != entered.end(); it++) {
            temp[enter[startEnter]].push_back(*it);
            temp[*it].push_back(enter[startEnter]);
         }
         entered.insert(enter[startEnter]);
         startEnter++;
      }
   }
   for (int i = 1; i <= enter.size(); i++) {
      answer.push_back(temp[i].size());
   }
   return answer;
}