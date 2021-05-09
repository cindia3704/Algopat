/*
    작성자: 김지수
    작성일: 2021/05/09
    백준 -- 나이순 정렬 (10814번)
    문제:온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다.
    이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에
   오는 순서로 정렬하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
   int n;
   cin >> n;
   vector<pair<int, int> > seq;
   vector<pair<int, string> > people;
   for (int i = 0; i < n; i++) {
      int age;
      string name;
      cin >> age >> name;
      seq.push_back(make_pair(age, i));
      people.push_back(make_pair(age, name));
   }
   sort(seq.begin(), seq.end());
   for (int i = 0; i < seq.size(); i++) {
      cout << seq[i].first << " " << people[seq[i].second].second << "\n";
   }
}