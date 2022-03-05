/*
    작성자: 김지수
    작성일: 2022/03/05
    백준 -- 후위 표기식2 (1935번)
*/

#include <cstring>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   stack<double> tempRet;
   double arrAlpha[26];
   memset(arrAlpha, 0.0, sizeof(arrAlpha));
   int numOperand;
   cin >> numOperand;

   string input;
   cin >> input;

   for (int op = 0; op < numOperand; op++) {
      int value;
      cin >> value;
      arrAlpha[op] = value;
   }

   for (int i = 0; i < input.length(); i++) {
      int tempIdx = input[i] - 'A';
      if (tempIdx >= 0) {
         tempRet.push(arrAlpha[tempIdx]);
      } else {
         double num2 = tempRet.top();
         tempRet.pop();
         double num1 = tempRet.top();
         tempRet.pop();
         double result = 0.0;
         switch (input[i]) {
            case '+':
               result = num1 + num2;
               break;
            case '-':
               result = num1 - num2;
               break;
            case '*':
               result = num1 * num2;
               break;
            case '/':
               result = num1 / num2;
               break;
            default:
               break;
         }
         tempRet.push(result);
      }
   }
   printf("%.2f", tempRet.top());
}