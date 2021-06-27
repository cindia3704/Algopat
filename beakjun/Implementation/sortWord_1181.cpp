/*
    작성자: 김지수
    작성일: 2021/06/27
    백준 -- 단어 정렬 (1181)
    문제:
    -알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라
   정렬하는 프로그램을 작성하시오.
      1.길이가 짧은 것부터
      2.길이가 같으면 사전 순으로
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, string> > words;

int main(void) {
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      string word;
      cin >> word;
      words.push_back(make_pair(word.length(), word));
   }
   string last = "";
   sort(words.begin(), words.end());
   for (int i = 0; i < n; i++) {
      if (words[i].second == last)
         continue;
      else {
         cout << words[i].second << endl;
         last = words[i].second;
      }
   }
}