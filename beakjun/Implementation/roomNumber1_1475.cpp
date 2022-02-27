/*
    작성자: 김지수
    작성일: 2022/02/27
    백준 -- 방 번호 (1475번)
    문제:
    - 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다
    -다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오
    - 6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다
    - 0 입력시 -> 1 출력 (반례)**
*/

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int count[10];
   int setCount = 1;
   memset(count, 0, sizeof(count));
   string roomNumber;
   cin >> roomNumber;
   for (int i = 0; i < roomNumber.length(); i++) {
      char now = roomNumber[i];
      int idx = now - '0';
      if (count[idx] < setCount) {
         count[idx]++;
      } else {
         if (idx == 9 && count[6] < setCount) {
            count[6]++;
         } else if (idx == 6 && count[9] < setCount) {
            count[9]++;
         } else {
            setCount++;
            count[idx]++;
         }
      }
   }
   cout << setCount;
}