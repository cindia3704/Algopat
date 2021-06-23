/*
    작성자: 김지수
    작성일: 2021/06/23
    백준 -- 1로 만들기 2 (12852번)
    문제:
    -정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
        -X가 3으로 나누어 떨어지면, 3으로 나눈다.
        -X가 2로 나누어 떨어지면, 2로 나눈다.
        -1을 뺀다
    - 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고
   한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int cache[1000001];
vector<pair<int, int> > q;

int makeTo1(int num) {
   int& ret = cache[num];
   int retNum = num;
   if (num <= 1) {
      ret = 0;
   }
   if (ret != -1) {
      return ret;
   }

   ret = makeTo1(num - 1) + 1;
   retNum = num - 1;

   if (num % 2 == 0) {
      int temp = makeTo1(num / 2);
      if (temp + 1 < ret) {
         ret = temp + 1;
         retNum = num / 2;
      }
   }
   if (num % 3 == 0) {
      int temp = makeTo1(num / 3);
      if (temp + 1 < ret) {
         ret = temp + 1;
         retNum = num / 3;
      }
   }
   // retNum = 다음으로 방문해야할 숫자
   //(num & retNum 프린트 해보면 패턴 볼수있음 )
   q.push_back(make_pair(num, retNum));

   return ret;
}

int main(void) {
   int num;
   cin >> num;
   memset(cache, -1, sizeof(cache));
   q.push_back(make_pair(1, 0));
   int ans = makeTo1(num);
   cout << ans << endl;

   int now = num;
   for (int j = q.size() - 1; j >= 0; j--) {
      if (q[j].first == now) {
         cout << q[j].first << " ";
         now = q[j].second;
      }
   }
}