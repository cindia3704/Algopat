/*
    작성자: 김지수
    작성일: 2021/04/15
    백준 -- 연산자 끼워넣기(14888번)
    문제:
    - N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에
   끼워넣을 수 있는 N-1개의 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-),
   곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
   - 모든 연산자의 우선순위가 같을때
   최대값 & 최소값 구하기
   연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은
   결과가 나오는 입력만 주어진다.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000000 + 1;
const int MAX_OPERANDS = 11;

vector<int> operands;
vector<int> operators;
bool visited[MAX_OPERANDS];
int maxResult = -MAX;
int minResult = MAX;

void dfs(int node, int remainingOperands, int calculation) {
   if (remainingOperands == 0) {
      maxResult = max(maxResult, calculation);
      minResult = min(minResult, calculation);
   }
   visited[node] = true;
   for (int i = 0; i < 4; i++) {
      if (operators[i] > 0) {
         switch (i) {
            case 0:
               operators[i]--;
               dfs(node + 1, remainingOperands - 1,
                   calculation + operands[node]);
               operators[i]++;
               break;
            case 1:
               operators[i]--;
               dfs(node + 1, remainingOperands - 1,
                   calculation - operands[node]);
               operators[i]++;
               break;
            case 2:
               operators[i]--;
               dfs(node + 1, remainingOperands - 1,
                   calculation * operands[node]);
               operators[i]++;
               break;

            case 3:
               operators[i]--;
               dfs(node + 1, remainingOperands - 1,
                   calculation / operands[node]);
               operators[i]++;
               break;
            default:
               break;
         }
      }
   }
   visited[node] = false;
}

int main(void) {
   memset(visited, false, sizeof(visited));
   int numOperands;
   cin >> numOperands;
   for (int i = 0; i < numOperands; i++) {
      int n;
      cin >> n;
      operands.push_back(n);
   }

   for (int i = 0; i < 4; i++) {
      int num;
      cin >> num;
      operators.push_back(num);
   }
   dfs(1, numOperands - 1, operands[0]);
   cout << maxResult << endl;
   cout << minResult << endl;
}
