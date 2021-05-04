/*
    작성자: 김지수
    작성일: 2021/05/04
    백준 -- 계단 오르기 (2579번)
    문제:
    - 계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지
   가는 게임이다.
    -  각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여
   있는 점수를 얻게 된다.
   - 계단 오르는 데는 다음과 같은 규칙이 있다.

    1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을
   밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
    2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지
   않는다.
    3. 마지막 도착 계단은 반드시 밟아야 한다.
    - 각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의
   최댓값을 구하는 프로그램
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_NUM = 10000;
vector<int> stairs;
int cache[MAX_NUM];
int numStairs;

int findMaxSum(int start) {
   int &ret = cache[start];
   if (start < 0) {
      return 0;
   }
   if (start == 0) {
      return stairs[0];
   }
   if (ret != -1) {
      return ret;
   }
   int goOne = stairs[start] + stairs[start - 1] + findMaxSum(start - 3);
   int goTwo = stairs[start] + findMaxSum(start - 2);
   ret = max(goOne, goTwo);

   return ret;
}

int main(void) {
   memset(cache, -1, sizeof(cache));
   cin >> numStairs;
   for (int i = 0; i < numStairs; i++) {
      int a;
      cin >> a;
      stairs.push_back(a);
   }

   cout << findMaxSum(numStairs - 1) << endl;
}
