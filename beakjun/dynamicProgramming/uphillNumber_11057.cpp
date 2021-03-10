/*
    작성자: 김지수
    작성일: 2021/03/11
    백준 -- 오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한
        수가 같아도 오름차순으로 친다.
        예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은
   오르막 수가 아니다. 수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는
   프로그램을 작성하시오. 수는 0으로 시작할 수 있다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// cache[자리수][자리수의 첫 숫자]
int cache[1001][10];  // 담기는 수 = 1007로 나눈 나머지 --> int 로 표현 가능!
const int MAX = 10007;

int uphillNumber(int place, int firstNum) {
   int &ret = cache[place][firstNum];
   if (place == 1) {  // 1일때 10을 반환해야함으로!
      return ret = 1 % MAX;
   }
   if (ret != -1) {  // -1이 아니면 이미 계산 된 값
      return ret % MAX;
   } else {
      ret = 0;
      for (int j = 0; j <= firstNum; j++) {
         ret = ret + uphillNumber(place - 1, j) % MAX;
      }
   }
   return ret % MAX;
}

int main(void) {
   int n;
   cin >> n;
   long long answer = 0;
   memset(cache, -1, sizeof(cache));  // 처음에 cache 다 -1 로 초기화!
   // 수는 0으로 시작할 수 있기 때문에 0~9 돌림
   for (int i = 0; i <= 9; i++) {
      answer += uphillNumber(n, i) % MAX;
   }
   cout << answer % MAX << endl;
}
