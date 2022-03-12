/*
    작성자: 김지수
    작성일: 2022/03/12
    백준 -- 좌표압축 (18870번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const long long MAX = 987654321;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   vector<pair<long long, int> > cor;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      cor.push_back(make_pair(num, i));
   }

   int counts[n];
   memset(counts, -1, sizeof(counts));
   sort(cor.begin(), cor.end());
   long long prev = cor[0].first;
   int countRank = 0;
   for (int i = 0; i < n; i++) {
      long long nowNum = cor[i].first;
      int nowIdx = cor[i].second;
      if (prev == nowNum) {
         counts[nowIdx] = countRank;
      } else {
         countRank++;
         counts[nowIdx] = countRank;
         prev = nowNum;
      }
   }
   for (int i = 0; i < n; i++) {
      cout << counts[i] << " ";
   }
}