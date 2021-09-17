/*
    작성자: 김지수
    작성일: 2021/09/18
    백준 -- 안테나 (18310번)
    문제:
    - 일직선 상의 마을에 여러 채의 집이 위치해 있고, 한 집에 안테나 설치하려함
    - 모든 집까지의 거리의 총 합이 최소가 되도록 설치하려 할 때 어느 집에 설치?
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> houses;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int numHouse;
   cin >> numHouse;
   for (int i = 0; i < numHouse; i++) {
      int num;
      cin >> num;
      houses.push_back(num);
   }
   sort(houses.begin(), houses.end());
   int index = (numHouse % 2 == 0) ? (numHouse / 2 - 1) : (numHouse / 2);
   cout << houses[index];
}