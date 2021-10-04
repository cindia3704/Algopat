/*
    작성자: 김지수
    작성일: 2021/10/04
    백준 -- 파일 정리  (20291번)
    문제:
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int fileNum;
   cin >> fileNum;
   map<string, int> extensions;
   for (int i = 0; i < fileNum; i++) {
      string fileName;
      cin >> fileName;
      size_t pos = fileName.find(".");
      string fileExt = fileName.substr(pos + 1);
      if (pos != std::string::npos) {
         if (extensions.find(fileExt) != extensions.end()) {
            extensions.find(fileExt)->second++;
         } else {
            extensions.insert(make_pair(fileExt, 1));
         }
      }
   }
   map<string, int>::iterator it;
   vector<pair<string, int> > finalExt;
   for (it = extensions.begin(); it != extensions.end(); it++) {
      finalExt.push_back(make_pair(it->first, it->second));
   }
   sort(finalExt.begin(), finalExt.end());
   for (int i = 0; i < finalExt.size(); i++) {
      cout << finalExt[i].first << " " << finalExt[i].second << '\n';
   }
}