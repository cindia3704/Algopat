/*
    작성자: 김지수
    작성일: 2021/09/12
    백준 -- 공 넣기 (10810번)
    문제:
    - N 개의 바구니 (1번~N번)에 공을 M번 넣으려 함
    - i j k <- i~j번 바구니에 k번공 넣음
    - 바구니에 공 이미 있으면 빼고, 새공 넣음
    - 각 바구니에 있는 공의 번호 출력
*/
#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int basketNum, putInNum;
   cin >> basketNum >> putInNum;
   int basket[basketNum + 1];
   memset(basket, 0, sizeof(basket));
   for (int i = 0; i < putInNum; i++) {
      int from, to, ball;
      cin >> from >> to >> ball;
      for (int j = from; j <= to; j++) {
         basket[j] = ball;
      }
   }
   for (int i = 1; i <= basketNum; i++) {
      cout << basket[i] << " ";
   }
}
