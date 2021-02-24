/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 최소, 최대(10818번)
    문제:N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을
   작성하시오.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   int size, num;
   cin >> size;
   vector<int> numList;
   for (int i = 0; i < size; i++) {
      cin >> num;
      numList.push_back(num);
   }
   sort(numList.begin(), numList.end());
   cout << numList[0] << " " << numList[numList.size() - 1];
}