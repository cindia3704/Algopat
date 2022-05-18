/*
    작성자: 김지수
    작성일: 2022/05/19
    백준 -- 계단 오르기 (2579번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 302
using namespace std;
int cache[MAX];
int stairNum;
vector<int> weights;

int findMax(int stair) {
   int& ret = cache[stair];
   if (stair < 0) {
      return 0;
   }
   if (stair == 0) {
      return weights[0];
   }
   if (ret != -1) {
      return ret;
   }
   // 한칸 내려가면 그 다음에는 무조건 2칸 내려가야함
   int oneStep = weights[stair] + weights[stair - 1] + findMax(stair - 3);
   // 두칸 내려가면 그다음에는 1칸 or 2칸 내려가기 가능
   int twoStep = weights[stair] + findMax(stair - 2);
   ret = max(oneStep, twoStep);

   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   memset(cache, -1, sizeof(cache));
   cin >> stairNum;

   for (int i = 0; i < stairNum; i++) {
      int num;
      cin >> num;
      weights.push_back(num);
   }

   cout << findMax(stairNum - 1);
}