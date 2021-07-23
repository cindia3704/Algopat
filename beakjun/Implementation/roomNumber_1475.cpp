/*
    작성자: 김지수
    작성일: 2021/07/24
    백준 -- 방 번호 (1475번)
    문제:
    - 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다
    -다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오
    - 6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다
    - 0 입력시 -> 1 출력 (반례)**
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int oneSet[10];

int main(void) {
   memset(oneSet, 0, sizeof(oneSet));

   int roomNum;
   int maxNum = 0;
   cin >> roomNum;

   while (roomNum >= 0) {
      if (roomNum == 0) {
         maxNum = 1;
         break;
      }
      int digitVal = roomNum % 10;
      if (digitVal == 6 || digitVal == 9) {
         int index = (oneSet[6] <= oneSet[9]) ? 6 : 9;
         oneSet[index]++;
      } else {
         oneSet[digitVal]++;
      }
      roomNum /= 10;
   }

   for (int i = 0; i < 10; i++) {
      maxNum = (maxNum <= oneSet[i]) ? oneSet[i] : maxNum;
   }

   cout << maxNum;
}