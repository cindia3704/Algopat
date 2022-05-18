/*
    작성자: 김지수
    작성일: 2022/05/19
    백준 -- 1로 만들기 (1463번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 1000001

using namespace std;
long long cache[MAX];

long long findLeastOperation(long long num) {
   long long &ret = cache[num];
   if (num == 1) {
      return 0;
   }
   if (num < 1) {
      return 1000002;
   }
   if (ret != 1000002) {
      return ret;
   }
   long long div2 = 1000002;
   long long div3 = 1000002;
   if (num % 2 == 0) {
      div2 = findLeastOperation(num / 2) + 1;
   }
   if (num % 3 == 0) {
      div3 = findLeastOperation(num / 3) + 1;
   }
   long long temp = min(div2, div3);
   long long minus1 = findLeastOperation(num - 1) + 1;
   ret = min(minus1, temp);
   return ret;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   long long num;
   cin >> num;
   for (int i = 1; i <= num; i++) {
      cache[i] = 1000002;
   }

   cout << findLeastOperation(num);
}