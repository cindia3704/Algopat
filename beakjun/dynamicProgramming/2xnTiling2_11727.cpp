/*
    작성자: 김지수
    작성일: 2021/03/09
    백준 -- 2xn 타일링 (11727번)
    문제:2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는
   프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 10007;
int cache[1001];

int tiling(int n) {
   int &ret = cache[n];
   if (n <= 1) {
      ret = 1;
      return ret;
   }
   if (ret != -1) {
      return ret;
   }
   ret = tiling(n - 1) % MAX + tiling(n - 2) % MAX + tiling(n - 2);
   return ret;
}

int main(void) {
   int n;
   cin >> n;
   memset(cache, -1, sizeof(cache));
   cout << tiling(n) % MAX << endl;
}