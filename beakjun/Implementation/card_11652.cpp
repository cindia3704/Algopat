/*
    작성자: 김지수
    작성일: 2021/05/23
    백준 -- 카드 (11652)
    문제:준규는 숫자 카드 N장을 가지고 있다.
    - 숫자 카드에는 정수가 하나
   적혀있는데, 적혀있는 수는 -262보다 크거나 같고, 262보다 작거나 같다.
   - 준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수를 구하는
   프로그램을 작성하시오. 만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은
   것을 출력한다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int MAX_N = 100000;

int main(void) {
   ios::sync_with_stdio(false);
   map<long long, long long> cards;
   long long maxNum = 987654321;
   long long maxNumCount = 0;
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      long long num;
      cin >> num;
      map<long long, long long>::iterator it;

      it = cards.find(num);

      if (it != cards.end()) {
         cards[num]++;
         if (cards[num] > maxNumCount) {
            maxNum = num;
            maxNumCount = cards[num];
         } else if ((cards[num] == maxNumCount && num < maxNum)) {
            maxNum = num;
         }
      } else {
         cards[num] = 1;
         if (cards[num] > maxNumCount) {
            maxNum = num;
            maxNumCount = cards[num];
         } else if ((cards[num] == maxNumCount && num < maxNum)) {
            maxNum = num;
         }
      }
   }
   cout << maxNum << endl;
}