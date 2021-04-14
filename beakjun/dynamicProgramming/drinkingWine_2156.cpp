/*
    작성자: 김지수
    작성일: 2021/04/14
    백준 -- 포도주 시식 (2156번)
    문제:
    1)포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신
    후에는 원래 위치에 다시 놓아야 한다.
    2)연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
    효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을
    선택해야 할지 고민하고 있다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10001;
vector<int> wines;
vector<int> result;
int cache[MAX];

int maxUntilIndex(int index) {
   int& ret = cache[index];
   if (index == 0) {
      ret = wines[index];
   }

   if (ret != -1) {
      return ret;
   } else {
      int notChooseBefore = maxUntilIndex(index - 2) + wines[index];
      int chooseBefore =
          maxUntilIndex(index - 3) + wines[index - 1] + wines[index];
      int notDrink = maxUntilIndex(index - 1);
      ret = max(notChooseBefore, chooseBefore);
      ret = max(ret, notDrink);  //현재 와인을 안마셔도 됨!
   }
   return ret;
}

int main(void) {
   memset(cache, -1, sizeof(cache));
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      int amount;
      cin >> amount;
      wines.push_back(amount);
   }

   int max = 0;
   for (int i = 0; i < n; i++) {
      int num = maxUntilIndex(i);
      max = num >= max ? num : max;
   }

   cout << max << endl;
}