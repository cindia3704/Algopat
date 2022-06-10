/*
    작성자: 김지수
    작성일: 2022/06/11
    백준 -- 부등호 (2529번)
*/

#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
#define GREATER 1
#define LESS 0
#define MAX 10
using namespace std;

bool used[MAX];
deque<int> dq;
int operatorNum;
vector<int> signs;
int pick[MAX];

long long maxAns = -9876543210;
long long minAns = 9876543210;
string maxAnswer = "";
string minAnswer = "";

void makeStack() {
   int idxSign = 0;
   int idxNum = 0;
   while (idxSign < operatorNum) {
      dq.push_back(pick[idxNum]);
      dq.push_back(signs[idxSign]);
      idxNum++;
      idxSign++;
   }
   dq.push_back(pick[idxNum]);
}

void check() {
   bool isValid = true;
   while (dq.size() > 1 && isValid == true) {
      int num1 = dq.front();
      dq.pop_front();
      int op = dq.front();
      dq.pop_front();
      int num2 = dq.front();

      if (op == GREATER) {
         if (num1 > num2) {
            continue;
         } else {
            isValid = false;
            return;
         }
      } else if (op == LESS) {
         if (num1 > num2) {
            isValid = false;
            return;
         } else {
            continue;
         }
      }
   }
   if (isValid) {
      string num = "";
      for (int i = 0; i <= operatorNum; i++) {
         num += to_string(pick[i]);
      }

      // 범위가 0-9로 만들수 잇는 수니까 long long 까지 감
      long long toNum = stoll(num);
      if (toNum > maxAns) {
         maxAns = toNum;
         maxAnswer = num;
      }
      if (toNum < minAns) {
         minAns = toNum;
         minAnswer = num;
      }
   }
   return;
}

void makeComb(int pickCount) {
   if (pickCount == operatorNum + 1) {
      makeStack();
      check();
      dq.clear();
      return;
   } else {
      for (int i = 0; i < 10; i++) {
         if (used[i] == false) {
            used[i] = true;
            pick[pickCount] = i;
            makeComb(pickCount + 1);
            used[i] = false;
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> operatorNum;
   for (int i = 0; i < operatorNum; i++) {
      char op;
      cin >> op;
      if (op == '>') {
         signs.push_back(GREATER);
      } else {
         signs.push_back(LESS);
      }
   }

   memset(used, false, sizeof(used));
   makeComb(0);
   cout << maxAnswer << "\n";
   cout << minAnswer;
}