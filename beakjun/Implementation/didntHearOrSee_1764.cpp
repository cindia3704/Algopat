/*
    작성자: 김지수
    작성일: 2021/09/11
    백준 -- 듣보잡 (1764번)
    문제:
    - 듣지 못한 명단 & 보지 못한 명단 주어질때 듣지도 보지도 못한 명단 만들기
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
   int notHear, notSee;
   cin >> notHear >> notSee;
   vector<string> names;
   vector<string> answer;
   for (int i = 0; i < notHear; i++) {
      string name;
      cin >> name;
      names.push_back(name);
   }
   sort(names.begin(), names.end());
   for (int i = 0; i < notSee; i++) {
      string name;
      cin >> name;
      vector<string>::iterator it;
      if (binary_search(names.begin(), names.end(), name)) {
         answer.push_back(name);
      }
   }
   cout << answer.size() << endl;
   sort(answer.begin(), answer.end());
   for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << endl;
   }
}