/*
    작성자: 김지수
    작성일: 2021/08/18
    백준 -- 빗물(14719번)
    문제:
    - 2차원 세계에 블록이 쌓여있을때 고이는 빗물의 총량을 구하라
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int height, width;
vector<int> block;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> height >> width;
   for (int i = 0; i < width; i++) {
      int size;
      cin >> size;
      block.push_back(size);
   }
   int sum = 0;
   // 내 기준 왼쪽가장 큰 값 & 오른쪽 가장 큰 값 구함
   // 왼 & 오 큰값중 작은값 구함
   // 위 값에서 내 높이 뺌
   for (int i = 0; i < width; i++) {
      int maxLeft = *max_element(block.begin(), block.begin() + i);
      int maxRight = *max_element(block.begin() + i, block.end());
      int minH = min(maxLeft, maxRight);
      if (minH - block[i] > 0) {
         sum += (minH - block[i]);
      }
   }
   cout << sum << endl;
}