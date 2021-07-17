/*
    작성자: 김지수
    작성일: 2021/07/17
    백준 -- 덩치 (7568)
    문제:
    - A 와 B의 덩치가 각각 (x, y), (p, q)라고 할 때 x > p 그리고 y > q 이라면
   우리는 A의 덩치가 B의 덩치보다 "더 크다"고 말한다.
   - 그런데 서로 다른 덩치끼리 크기를 정할 수 없는 경우도 있다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   int numPeople;
   vector<pair<int, int> > people;
   cin >> numPeople;
   int rank[numPeople];
   memset(rank, 0, sizeof(rank));
   int maxWeight = 0;
   int maxHeight = 0;

   for (int i = 0; i < numPeople; i++) {
      int weight, height;
      cin >> weight >> height;
      people.push_back(make_pair(weight, height));
   }

   for (int i = 0; i < numPeople; i++) {
      int rank = 1;
      int nowWeight = people[i].first;
      int nowHeight = people[i].second;
      for (int j = 0; j < numPeople; j++) {
         int nextWeight = people[j].first;
         int nextHeight = people[j].second;
         if ((nowWeight < nextWeight) && (nowHeight < nextHeight)) {
            rank++;
         }
      }
      cout << rank << " ";
   }
}