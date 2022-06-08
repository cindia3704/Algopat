/*
    작성자: 김지수
    작성일: 2022/06/08
    백준 -- 연산자 끼워넣기 2 (15658번)
*/

#include <math.h>

#include <deque>
#include <iostream>
#define MAX_OPERAND 12
#define MAX_OPERATOR 44
#define PLUS 0
#define MINUS 1
#define MULT 2
#define DIV 3
using namespace std;

int operandNum;
int operand[MAX_OPERAND];
int operators[4];
int pick[MAX_OPERAND];
long long ansMax = -1000000000;
long long ansMin = 1000000000;
deque<long long> q;
void makeToStack() {
   int idx1 = 0;
   int idx2 = 0;

   while (idx1 < operandNum - 1) {
      q.push_back(operand[idx1]);
      q.push_back(pick[idx2]);
      idx1++;
      idx2++;
   }
   q.push_back(operand[idx1]);
   return;
}
long long getResult(long long a, long long op, long long b) {
   switch (op) {
      case PLUS:
         return a + b;
         break;
      case MINUS:
         return a - b;
         break;
      case MULT:
         return a * b;
         break;
      case DIV:
         if (a < 0) {
            int temp = abs(a) / b;
            return -temp;
         } else {
            return a / b;
         }
         break;
      default:
         return 0;
         break;
   }
}

void calculate() {
   while (q.size() > 1) {
      long long a = q.front();
      q.pop_front();
      long long op = q.front();
      q.pop_front();
      long long b = q.front();
      q.pop_front();
      long long temp = getResult(a, op, b);
      q.push_front(temp);
   }
   long long ans = q.front();
   if (ans > ansMax) {
      ansMax = ans;
   }
   if (ans < ansMin) {
      ansMin = ans;
   }
}

void makeComb(int pickCount) {
   if (pickCount == operandNum - 1) {
      makeToStack();
      calculate();
      q.clear();
      return;
   } else {
      for (int i = 0; i < 4; i++) {
         if (operators[i] > 0) {
            pick[pickCount] = i;
            operators[i]--;
            makeComb(pickCount + 1);
            operators[i]++;
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> operandNum;
   for (int i = 0; i < operandNum; i++) {
      cin >> operand[i];
   }
   cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];

   makeComb(0);
   cout << ansMax << '\n';
   cout << ansMin;
}