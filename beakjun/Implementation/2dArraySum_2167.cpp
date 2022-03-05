/*
    작성자: 김지수
    작성일: 2022/03/05
    백준 -- 2차원 배열의 합 (2167번)
*/

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 301;
vector<int> arr[MAX];

int getSum(int sy, int sx, int ey, int ex) {
   int sum = 0;
   for (int i = sy; i <= ey; i++) {
      for (int j = sx; j <= ex; j++) {
         sum += arr[i].at(j);
      }
   }
   return sum;
}

int main(void) {
   int row, col;
   cin >> row >> col;

   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         int num;
         cin >> num;
         arr[i].push_back(num);
      }
   }
   int resultNum;
   cin >> resultNum;
   for (int i = 0; i < resultNum; i++) {
      int sy, sx, ey, ex;
      cin >> sy >> sx >> ey >> ex;
      cout << getSum(sy - 1, sx - 1, ey - 1, ex - 1) << '\n';
   }
}