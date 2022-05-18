/*
    작성자: 김지수
    작성일: 2022/05/18
    백준 -- N과 M(5) (15651번)
    -> N개의 자연수 중에서 M개를 고른 수열
    -> 중복 불가, 수열은 사전 순으로 증가하는 순서로 출력
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 9
using namespace std;
int pick[MAX];
vector<int> numList;
bool picked[MAX];

int n, m;

void pickCard(int pickCount) {
   if (pickCount == m) {
      for (int i = 0; i < m; i++) {
         cout << pick[i] << " ";
      }
      cout << '\n';
      return;
   } else if (pickCount > m) {
      return;
   } else {
      // 중복없이 뽑기 위해 뽑음여부 관리
      for (int i = 0; i < n; i++) {
         if (picked[i] == false) {
            picked[i] = true;
            pick[pickCount] = numList[i];
            pickCard(pickCount + 1);
            picked[i] = false;
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      numList.push_back(num);
   }
   // 사전 순으로 증가하는 순서로 출력하기 위해
   sort(numList.begin(), numList.end());

   memset(picked, false, sizeof(picked));
   pickCard(0);
}
