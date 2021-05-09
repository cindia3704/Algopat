/*
    작성자: 김지수
    작성일: 2021/05/09
    백준 -- 좌표 정렬하기 (11650번)
    문제:2차원 평면 위의 점 N개가 주어진다.
     좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로
   정렬한 다음 출력하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   int n;
   cin >> n;
   vector<pair<int, int> > cor;
   for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      cor.push_back(make_pair(x, y));
   }
   sort(cor.begin(), cor.end());

   for (int i = 0; i < cor.size(); i++) {
      cout << cor[i].first << " " << cor[i].second << "\n";
   }
}