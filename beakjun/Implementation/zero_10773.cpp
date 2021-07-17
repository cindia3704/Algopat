/*
    작성자: 김지수
    작성일: 2021/07/18
    백준 -- 제로 (10773)
    문제:
    - 재현이는 재민이를 도와서 돈을 관리하는 중인데, 애석하게도 항상 정신없는
   재현이는 돈을 실수로 잘못 부르는 사고를 치기 일쑤였다.
   - 재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를
   지우게 시킨다.
   - 재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다.
   재민이를 도와주자!
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
   int totalNum;
   int sum = 0;
   cin >> totalNum;
   stack<int> allNum;
   for (int i = 0; i < totalNum; i++) {
      int input;
      cin >> input;
      if (input == 0 && !allNum.empty()) {
         allNum.pop();
      } else {
         allNum.push(input);
      }
   }
   while (!allNum.empty()) {
      sum += allNum.top();
      allNum.pop();
   }
   cout << sum;
}