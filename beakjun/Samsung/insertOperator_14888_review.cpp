/*
    작성자: 김지수
    작성일: 2021/10/05
    백준 -- 연산자 끼워넣기 (14888번)
    문제:
*/

#include <iostream>
#include <stack>
using namespace std;
int operatorCount[4];
int operandList[11];
int arr[10];
int numOperand, numOperator;
long long maxNum = -9999999999;
long long minNum = 9999999999;

long long calculate() {
   stack<int> s;
   int operatorIndex = 0;
   for (int i = 0; i < numOperand; i++) {
      if (s.empty()) {
         s.push(operandList[i]);
      } else {
         int sum = 0;
         int a = s.top();
         s.pop();
         int b = operandList[i];
         int op = arr[operatorIndex];
         switch (op) {
            case 0:
               sum = a + b;
               break;
            case 1:
               sum = a - b;
               break;
            case 2:
               sum = a * b;
               break;
            default:
               sum = a / b;
               break;
         }
         operatorIndex++;
         s.push(sum);
      }
   }
   return s.top();
}

void makeCombination(int depth) {
   if (depth == numOperator) {
      long long temp = calculate();
      if (temp > maxNum) {
         maxNum = temp;
      }
      if (temp < minNum) {
         minNum = temp;
      }
      return;
   } else {
      for (int i = 0; i < 4; i++) {
         if (operatorCount[i] > 0) {
            operatorCount[i]--;
            arr[depth] = i;
            makeCombination(depth + 1);
            operatorCount[i]++;
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> numOperand;
   numOperator = numOperand - 1;
   for (int i = 0; i < numOperand; i++) {
      cin >> operandList[i];
   }

   for (int i = 0; i < 4; i++) {
      cin >> operatorCount[i];
   }
   makeCombination(0);
   cout << maxNum << "\n" << minNum << '\n';
}